#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Hash.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266mDNS.h>
#include <EEPROM.h>
#include <FS.h>  // For SPIFFS
#include "page.h"
#include "update.h"

const String App_Version = "V1.0.2";
const char* host = "cooler";

// Access Point credentials if the board fails to connect to the WiFi network
const char* ap_ssid = "Cooler";
const char* ap_password = "";

// Set to true to define Relay as Normally Open (NO)
#define RELAY_NO false

// Set number of relays
#define NUM_RELAYS 1

// Assign each GPIO to a relay
int relayGPIOs[NUM_RELAYS] = { 16 };

// Replace with your network credentials
String ssid;
String password;

bool Chekmark[2];

// Create AsyncWebServer object on port 80
ESP8266WebServer server(80);
ESP8266HTTPUpdateServer httpUpdater;

bool connectedToWiFi = false;  // Flag to check if connected to WiFi

String relayState(int numRelay) {
  if (RELAY_NO) {
    if (digitalRead(relayGPIOs[numRelay - 1])) {
      return "";
    } else {
      return "checked";
    }
  } else {
    if (digitalRead(relayGPIOs[numRelay - 1])) {
      return "checked";
    } else {
      return "";
    }
  }
  return "";
}

void writeToEEPROM(String data, int startAddr, int dataSize) {
  for (int i = 0; i < dataSize; i++) {
    if (i < data.length()) {
      EEPROM.write(startAddr + i, data[i]);
    } else {
      EEPROM.write(startAddr + i, '\0');
    }
  }
  EEPROM.commit();
}

static String readFromEEPROM(int startAddr, int dataSize) {
  String data = "";
  for (int i = 0; i < dataSize; i++) {
    char charData = EEPROM.read(startAddr + i);
    data += charData;
  }
  return data;
}

void handle_Root() {
  String page = index_html;
  page.replace("%CHECKEDSTATE%", relayState(1));
  page.replace("%version%", App_Version);
  page.replace("%SCHECK%", (Chekmark[0] ? "checked" : ""));
  page.replace("%APCHECK%", (Chekmark[1] ? "checked" : ""));
  page.replace("%DISSSIDPASS%", (Chekmark[1] ? "disabled" : ""));
  server.send(200, "text/html", page);
}

static void handle_Reset() {
  ESP.restart();
}

static void handle_Config_Save() {
  String New_ssid = server.arg("ssid");
  String New_password = server.arg("password");

  String wifi = server.arg("wifi");
  bool iwifi = wifi.toInt();

  Serial.print("New SSID : ");
  Serial.println(New_ssid);
  
  Serial.print("New SSID : ");
  Serial.println(New_ssid);
  Serial.print("New PASSWORD : ");
  Serial.println(New_password);

  EEPROM.write(1, iwifi);
  delay(10);
  writeToEEPROM(New_ssid, 2, 64);
  delay(10);
  writeToEEPROM(New_password, 67, 64);
  delay(10);

  ESP.restart();
}

static void handle_Button() {
  String state = server.arg("state");
  uint8_t iState = state.toInt();
  if (iState)
    digitalWrite(relayGPIOs[0], HIGH);
  else
    digitalWrite(relayGPIOs[0], LOW);
  handle_Root();
}

void handle_image() {
  File iconFile = SPIFFS.open("/394126.png", "r");
  if (iconFile) {
    server.streamFile(iconFile, "image/png");
    iconFile.close();
  }
}

void setup() {

  // Set all relays to off when the program starts - if set to Normally Open (NO), the relay is off when you set the relay to HIGH
  for (int i = 1; i <= NUM_RELAYS; i++) {
    pinMode(relayGPIOs[i - 1], OUTPUT);
    if (RELAY_NO) {
      digitalWrite(relayGPIOs[i - 1], HIGH);
    } else {
      digitalWrite(relayGPIOs[i - 1], LOW);
    }
  }

  // Serial port for debugging purposes
  Serial.begin(115200);
  EEPROM.begin(512);

  bool wifiMode = EEPROM.read(1);
  delay(10);
  ssid = readFromEEPROM(2, 64);
  delay(10);
  password = readFromEEPROM(67, 64);
  delay(10);

  Serial.print("wifi Mode : ");
  Serial.println(wifiMode);
  Serial.print("SSID : ");
  Serial.println(ssid);
  Serial.print("PASSWORD : ");
  Serial.println(password);

  if (!SPIFFS.begin()) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
  
  if (wifiMode) {
    Chekmark[0] = 1;
    Chekmark[1] = 0;
    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    int wifiConnectionAttempts = 0;
    while (WiFi.status() != WL_CONNECTED) {
      wifiConnectionAttempts++;
      delay(1000);
      Serial.println("Connecting to WiFi..");
      if (wifiConnectionAttempts >= 10) {
        // If the board fails to connect to the WiFi network after 10 attempts, start in Access Point Mode
        WiFi.mode(WIFI_AP);
        WiFi.softAP(ap_ssid, ap_password);
        Serial.println("Access Point Mode: Cooler");
        Serial.print("IP address: ");
        Serial.println(WiFi.softAPIP());
        connectedToWiFi = false;
        break;
      }
    }

    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("Connected to WiFi");
      Serial.print("IP address: ");
      Serial.println(WiFi.localIP());
      connectedToWiFi = true;
    } else {
      Chekmark[0] = 0;
      Chekmark[1] = 1;
      WiFi.softAP(ap_ssid, ap_password);
      delay(100);
      Serial.print("SoftAP IP: ");
      Serial.println(WiFi.softAPIP());
    }
  } else {
    Chekmark[0] = 0;
    Chekmark[1] = 1;
    WiFi.softAP(ap_ssid, ap_password);
    delay(100);
    Serial.print("SoftAP IP: ");
    Serial.println(WiFi.softAPIP());
  }
  MDNS.begin(host);
  httpUpdater.setup(&server);

  server.on("/", handle_Root);
  server.on("/394126.png", HTTP_GET, handle_image);
  server.on("/Reset", HTTP_GET, handle_Reset);
  server.on("/getParams", HTTP_GET, handle_Config_Save);
  server.on("/button", HTTP_GET, handle_Button);
  // Start server
  server.begin();

  MDNS.addService("http", "tcp", 80);
  Serial.printf("Server ready! Open http://%s.local in your browser\n", host);
}

void loop() {
  server.handleClient();
  MDNS.update();
}
