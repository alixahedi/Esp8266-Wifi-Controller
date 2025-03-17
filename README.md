# ESP8266 WiFi Controller

This project allows you to **wirelessly control the power of an electrical device**, such as an evaporative cooler! 🌬️

With a built-in web interface, you can control the device from any browser. You can even **add the web page as a web application** to your mobile home screen for quick access. Just tap the icon and start controlling your device instantly.

## 🔥 Features
- 🛜 **Two operating modes**:
  - **Access Point Mode**: Creates its own WiFi network for direct connection.
  - **Station Mode**: Connects to an existing WiFi network.
- 🎛️ **Web-based control panel** – No need for additional apps!
- 🔧 **Easy configuration** – Set the device name, web page title, and host address in the `Wifi_Controller.ino` file.
- ⚡ **Over-the-Air (OTA) updates** – Upload new firmware directly from the web page.
- 🔄 **Auto-switching WiFi** – If no WiFi credentials are set, the device creates an Access Point.

---

## 🚀 Getting Started
1. **Flash the ESP8266** with the provided firmware using the **Arduino IDE**.
2. On first startup, the module will try to connect to a WiFi network.
   - If no credentials are stored, it will create an **Access Point named "Cooler"** (you can change this in the code).
3. Connect to the device and access the **settings page** (📷 see below).
4. Set up your WiFi credentials and **switch between modes** as needed.
5. Control your device via the web interface!

---

## 🖥️ Web Interface

### **Home Tab**
Control the device easily from the web page.

<a href="https://github.com/alixahedi/Esp8266_Wifi_Controller">
<img align="center" alt="Home Tab" width="31%" src="@/../assests/images/home.jpg">
</a>
<br/>

---

### **Settings Tab**
Configure the WiFi mode and update settings.

<a href="https://github.com/alixahedi/Esp8266_Wifi_Controller">
<img align="center" alt="Setting Tab" width="31%" src="@/../assests/images/setting.jpg">
</a>
<br/>

---

### **OTA Update**
Upload new firmware remotely using **Over-the-Air updates**.

<a href="https://github.com/alixahedi/Esp8266_Wifi_Controller">
<img align="center" alt="Update" width="31%" src="@/../assests/images/update.jpg">
</a>
<br/>

---

## 🛠️ How to Update Firmware (OTA)
1. **Compile the binary file**:
   - In **Arduino IDE**, go to `Sketch` ➝ `Export Compiled Binary`.
2. **Upload the `.bin` file** to the **Update tab** in the web interface.
3. Click **Upload**, and the ESP8266 will restart with the new firmware!

---

## 🏗️ Customization
Modify these values in `Wifi_Controller.ino` to personalize your device:
```cpp
#define DEVICE_NAME "Cooler"
#define WEB_TITLE "Cooler Controller"
#define HOST_ADDRESS "192.168.4.1"
```
Change them to fit your needs! 🎯

---

## 📌 Follow Me!
Stay connected and follow my work on other platforms:

<a href="https://twitter.com/alixahedi">
<img align="left" alt="Alix | Twitter" width="22px" src="@/../assests/images/social/Twitter.png" />
</a>
<a href="https://www.linkedin.com/in/ali-zahedi-b5a360158//">
<img align="left" alt="Ali's LinkedIN" width="22px" src="@/../assests/images/social/Linkedin.png" />
</a>
<a href="https://www.facebook.com/Alixahedi/">
<img align="left" alt="Ali's FaceBook" width="22px" src="@/../assests/images/social/fb.png" />
</a>
<a href="https://www.instagram.com/Alixahedi">
<img align="left" alt="Ali's Instagram" width="22px" src="@/../assests/images/social/insta.png" />
</a>
<br/>

---

## 📜 License
This project is licensed under the **MIT License**.

---
🔧 *Developed by [alixahedi](https://github.com/alixahedi).*
