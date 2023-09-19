#ifndef __PAGE_H_
#define __PAGE_H_

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8" />
    <link rel="apple-touch-icon" type="image/png" sizes="28x28" href="394126.png">
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Cooler</title>
    <style>
        * {
            padding: 0;
            margin: 0;
            list-style: none;
            box-sizing: border-box;
            text-decoration: none;
        }

        body {
            font-family: Arial;
            text-align: center;
            margin: 0px auto;
            padding-top: 0px;
        }

        /* Styling for the panel */
        .panel {
            display: inline-block;
            padding: 10px;
            /* Default padding for larger screens */
            background-color: #f2f2f2;
            border: 1px solid #ccc;
            border-radius: 10px;
            box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.2);
        }

        /* Styling for the button container */
        .button-container {
            display: flex;
            justify-content: center;
            gap: 20px;
            margin-bottom: 50px;
        }

        /* Styling for the custom button */
        .custom-button {
            padding: 50px 85px;
            /* Default padding for larger screens */
            font-size: 30px;
            /* Default font size for larger screens */
            color: white;
            background-color: dodgerblue;
            border: none;
            border-radius: 15px;
            box-shadow: 0px 2px 5px rgba(0, 0, 0, 0.2);
            cursor: pointer;
            margin: 2%;
            transition: box-shadow 0.3s ease;
            /* Add transition effect for smooth animation */
        }

        /* update button styles on hover */
        .custom-button:hover {
            box-shadow: 0px 4px 8px rgba(0, 0, 0, 0.4);
        }

        /* update button styles on active state */
        .custom-button:active {
            box-shadow: 0px 1px 3px rgba(0, 0, 0, 0.4);
            transform: translateY(2px);
        }

        .container {
            display: flex;
            flex-direction: column;
        }

        .nav ul {
            display: flex;
            justify-content: center;
            gap: 12px;
            padding: 24px;
        }

        .ul li {
            color: white;
        }

        /* Styling for the tabs */
        .tab {
            list-style-type: none;
            margin: 0;
            padding: 0;
            overflow: hidden;
            background-color: #f9f9f9;
            border-radius: 0px;
            box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.2);
            display: flex;
            justify-content: center;
        }

        /* Styling for the tab links */
        .tab li {
            padding: 15px 60px;
            cursor: pointer;
            background-color: #ccc;
            margin-right: 10px;
            margin-left: 10px;
            margin-bottom: 2px;
            border-radius: 10px;
            font-weight: bold;
            position: relative;
            transition: transform 0.3s ease;
            border-top-left-radius: 0px;
            border-top-right-radius: 0px;
            color: black;
        }

        /* Styling for the active tab link */
        .tab li.active {
            background-color: dodgerblue;
            color: white;
        }

        /* Styling for the default tab link */
        .tab li:not(.active) {
            background-color: #ccc;
            color: black;
        }

        /* Styling for Chrome browser tabs */
        .tab li:before {
            content: "";
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 4px;
            background-color: dodgerblue;
            transform: scaleX(0);
            transition: transform 0.3s ease;
        }

        /* Styling for active Chrome browser tab */
        .tab li.active:before {
            transform: scaleX(1);
        }

        /* Custom styles for tabs */
        .tab li:nth-child(1) {
            background-color: dodgerblue;
            color: white;
        }

        .tab li:nth-child(2) {
            background-color: #ccc;
        }

        /* Styling for the tab content container */
        #tab-content-container {
            margin-top: 20px;
        }

        /* Styling for the tab content */
        .tab-content {
            display: none;
            padding: 18px;
            background-color: #f9f9f9;
            border: 1px solid #ccc;
            border-radius: 10px;
            max-width: 600px;
            margin: 0 auto;
            text-align: center;
        }

        /* Styling for the active tab content */
        .tab-content.active {
            background-color: #f9f9f9;
            display: block;
        }

        /* Styling for the button container */
        .button-container {
            display: flex;
            justify-content: center;
            gap: 20px;
            margin-top: 20px;
        }

        /* Styling for the custom button */
        .custom-button {
            padding: 15px 30px;
            /* Default padding for larger screens */
            font-size: 15px;
            /* Default font size for larger screens */
            color: white;
            background-color: dodgerblue;
            border: none;
            border-radius: 15px;
            box-shadow: 0px 2px 5px rgba(0, 0, 0, 0.2);
            cursor: pointer;
            transition: box-shadow 0.3s ease;
            /* Add transition effect for smooth animation */
        }

        /* update button styles on hover */
        .custom-button:hover {
            box-shadow: 0px 4px 8px rgba(0, 0, 0, 0.4);
        }

        /* update button styles on active state */
        .custom-button:active {
            box-shadow: 0px 1px 3px rgba(0, 0, 0, 0.4);
            transform: translateY(2px);
        }

        /* Media queries for smaller screens (mobile devices) */
        @media screen and (max-width: 768px) {
            .panel {
                padding: 35px;
                /* Doubled padding for smaller screens (mobile devices) */
            }

            .button-container {
                flex-direction: column;
                /* Display buttons vertically on smaller screens */
            }

            .custom-button {
                padding: 25px 45px;
                /* Doubled padding for smaller screens (mobile devices) */
                font-size: 20px;
                /* Doubled font size for smaller screens (mobile devices) */
            }

            .tab li {
                padding: 15px 25px;
            }
        }

        .switch {
            position: relative;
            display: inline-block;
            width: 120px;
            height: 68px
        }

        .switch input {
            display: none
        }

        .slider {
            position: absolute;
            top: 0;
            left: 0;
            right: 0;
            bottom: 0;
            background-color: #ccc;
            border-radius: 34px
        }

        .slider:before {
            position: absolute;
            content: "";
            height: 52px;
            width: 52px;
            left: 8px;
            bottom: 8px;
            background-color: #fff;
            -webkit-transition: .4s;
            transition: .4s;
            border-radius: 68px
        }

        input:checked+.slider {
            background-color: #2196F3
        }

        input:checked+.slider:before {
            -webkit-transform: translateX(52px);
            -ms-transform: translateX(52px);
            transform: translateX(52px)
        }

        .container-checkmark {
            position: relative;
            padding-left: 35px;
            margin-bottom: 12px;
            cursor: pointer;
            font-size: 22px;
            -webkit-user-select: none;
            -moz-user-select: none;
            -ms-user-select: none;
            user-select: none;
            margin-right: 20px;
            margin-left: 15px;
            white-space: nowrap;
        }

        /* Hide the browser's default radio button */
        .container-checkmark input {
            position: absolute;
            opacity: 0;
            cursor: pointer;
        }

        /* Create a custom radio button */
        .checkmark {
            position: absolute;
            top: 0;
            left: 0;
            height: 25px;
            width: 25px;
            background-color: #eee;
            border-radius: 50%;
        }

        /* On mouse-over, add a grey background color */
        .container-checkmark:hover input~.checkmark {
            background-color: #ccc;
        }

        /* When the radio button is checked, add a blue background */
        .container-checkmark input:checked~.checkmark {
            background-color: #2196F3;
        }

        /* Create the indicator (the dot/circle - hidden when not checked) */
        .checkmark:after {
            content: "";
            position: absolute;
            display: none;
        }

        /* Show the indicator (dot/circle) when checked */
        .container-checkmark input:checked~.checkmark:after {
            display: block;
        }

        /* Style the indicator (dot/circle) */
        .container-checkmark .checkmark:after {
            top: 9px;
            left: 9px;
            width: 8px;
            height: 8px;
            border-radius: 50%;
            background: white;
        }

        .form-container {
            min-width: 320px;
        }

        progress {
            display: block;
            width: 100%;
            margin: 2em auto;
            padding: 2px;
            border: 0 none;
            background: #444;
            border-radius: 14px;
            box-shadow: inset 0 1px 1px rgba(0, 0, 0, 0.5),
                0 1px 0 rgba(255, 255, 255, 0.2);
        }

        progress::-moz-progress-bar {
            border-radius: 12px;
            background: #fff;
            box-shadow: inset 0 -2px 4px rgba(0, 0, 0, 0.4),
                0 2px 5px 0 rgba(0, 0, 0, 0.3);
        }

        @media screen and (max-width: 768px) {
            progress {
                height: 25px;
            }
        }

        progress::-webkit-progress-bar {
            background: #fff;
            border-radius: 12px;
        }

        progress::-webkit-progress-value {
            border-radius: 12px;
            background: dodgerblue;
            box-shadow: inset 0 -2px 4px rgba(0, 0, 0, 0.4),
                0 2px 5px 0 rgba(0, 0, 0, 0.3);
        }

        #overlay {
            position: fixed;
            display: none;
            width: 100%;
            height: 100%;
            top: 0;
            left: 0;
            right: 0;
            bottom: 0;
            /*background-color: rgba(163, 160, 160, 0.5);*/
            z-index: 2;
            cursor: pointer;
        }

        .footer {
            position: fixed;
            bottom: 0;
            left: 0;
            width: 100%;
            background-color: #ccc;
            color: #000;
            text-align: center;
            padding: 10px;
        }
    </style>
</head>

<body>
    <div class="container">
        <div>
            <ul class="tab">
                <!-- Tab links -->
                <li class="active" onclick="toggleTab(0, '/Home')">Home</li>
                <li onclick="toggleTab(1, '/Setting')">Setting</li>
                <li onclick="toggleTab(2, '/update')">Update</li>
            </ul>
            <div id="tab-content-container">
                <!-- Content for Detect Remote tab -->
                <div id="home-content" class="tab-content active">
                    <h1>Cooler Control</h1>
                    </br>
                    </br>
                    </br>
                    <label class="switch"><input type="checkbox" id="sliderswitch" onchange="toggleCheckbox();"
                            %CHECKEDSTATE% />
                        <span class="slider"></span></label>
                    </br>
                    </br>
                    </br>
                </div>
                <!-- Content for Upload File tab -->
                <div id="setting-content" class="tab-content">
                    <form action="/getParams" method="post" onsubmit="return false;">
                        <label for="ssid"><strong>SSID</strong></label>
                        <input type="text" id="ssid" name="ssid" %DISSSIDPASS% /><br /><br />
                        <label for="password"><strong>Pass</strong></label>
                        <input type="password" id="password" name="password" %DISSSIDPASS% /><br /><br />
                        <strong>
                            mode:
                        </strong>
                        <label class="container-checkmark"> Station
                            <input type="radio" id="station" name="radio" value="Station" %SCHECK%
                                onchange="handleCheckboxChange()">
                            <span class="checkmark"></span>
                        </label>

                        <label class="container-checkmark"> Access Point
                            <input type="radio" id="accessPoint" name="radio" value="AccessPoint" %APCHECK%
                                onchange="handleCheckboxChange()">
                            <span class="checkmark"></span>
                        </label>
                        </br>
                        </br>
                        <input type="button" class="custom-button" value="Save" onclick="savewifiConfig('Save')" />
                        <input type="button" class="custom-button" value="Reset" onclick="ButtonCheck('Reset')" />
                    </form>
                </div>
                <div id="update-content" class="tab-content">
                    <form enctype="multipart/form-data" class="form-container" id="upload_form" method="POST">
                        <input accept=".bin,.bin.gz" class="input-file" id="file1" name="firmware"
                            type="file" /><br /><progress id="progressBar" max="100" value="0"></progress>
                        <div class="additional-info">
                            <h3 id="status">Firmware upload</h3>
                            <p id="loaded_n_total"></p>
                        </div>
                        <br />
                        <br />
                        <button id="button-send" class="custom-button" type="submit" disabled="disabled">
                            Upload
                        </button>
                    </form>
                </div>
            </div>
        </div>
    </div>
    <div class="footer">
        <p> | <strong>%version%</strong> | Made by <a
                href="https://github.com/alixahedi/Esp8266_Wifi_Controller" target="_blank"><strong>Alixahedi</strong></a> |</p>
    </div>
    <script>
        // Display the default tab content on page load
        window.onload = function () {
            var defaultTab =
                document.getElementsByClassName("tab-content active")[0];
            defaultTab.style.display = "block";
        };

        function toggleTab(tabIndex, url) {
            console.log(tabIndex);
            var tabContents = document.getElementsByClassName("tab-content");
            var tabLinks = document
                .getElementsByClassName("tab")[0]
                .getElementsByTagName("li");

            for (var i = 0; i < tabContents.length; i++) {
                tabContents[i].style.display = "none";
                tabLinks[i].className = "";
                tabLinks[i].style.backgroundColor = "#ccc";
                tabLinks[i].style.color = "black";
            }

            tabContents[tabIndex].style.display = "block";
            tabLinks[tabIndex].className = "active";
            tabLinks[tabIndex].style.backgroundColor = "dodgerblue";
            tabLinks[tabIndex].style.color = "white";
        }

        function handleCheckboxChange() {
            var accessPointCheckbox = document.getElementById("accessPoint");
            var stationCheckbox = document.getElementById("station");
            var ssidInput = document.getElementsByName("ssid")[0];
            var passwordInput = document.getElementsByName("password")[0];

            if (accessPointCheckbox.checked) {
                ssidInput.disabled = true;
                passwordInput.disabled = true;
            } else if (stationCheckbox.checked) {
                ssidInput.disabled = false;
                passwordInput.disabled = false;
            }
        }

        function toggleCheckbox() {
            var sliderswitch = document.getElementById("sliderswitch");
            var xhr = new XMLHttpRequest();
            if (sliderswitch.checked) {
                xhr.open("GET", "/button?state=1", true);
            } else {
                xhr.open("GET", "/button?state=0", true);
            }
            xhr.send();
        }

        function ButtonCheck(x) {
            var xhr = new XMLHttpRequest();
            xhr.open("GET", "/" + x, true);
            xhr.send();
            xhr.onload = function () {
                if (xhr.status === 200) {
                    window.location.href = "/" + x;
                }
            };
        }

        function savewifiConfig(action) {
            console.log(action + " button clicked");
            var ssid = document.getElementsByName("ssid")[0].value;
            var password = document.getElementsByName("password")[0].value;
            document.getElementsByName("ssid")[0].value = "";
            document.getElementsByName("password")[0].value = "";

            var accessPointCheckbox = document.getElementById("accessPoint");
            var stationCheckbox = document.getElementById("station");

            var xhr = new XMLHttpRequest();
            if (accessPointCheckbox.checked) {
                xhr.open(
                    "GET",
                    "/getParams?ssid=" + ssid + "&password=" + password + "&wifi=0",
                    true
                );
            } else if (stationCheckbox.checked) {
                xhr.open(
                    "GET",
                    "/getParams?ssid=" + ssid + "&password=" + password + "&wifi=1",
                    true
                );
            }
            xhr.send();
        }

        function stringToBoolean(e) {
            switch (e.toLowerCase().trim()) {
                case "true":
                case "yes":
                case "1":
                    return !0;
                case "false":
                case "no":
                case "0":
                case null:
                    return !1;
                default:
                    return Boolean(e);
            }
        }
        const urlParams = new URLSearchParams(window.location.search),
            onlyFirmware = urlParams.get("onlyFirmware");
        function disableAll() {
            document.getElementById("overlay").style.display = "block";
        }
        function enableAll() {
            document.getElementById("overlay").style.display = "none";
        }
        function _(e) {
            return document.getElementById(e);
        }
        function uploadFile() {
            var e = _("file1").files[0],
                t = new FormData();
            t.append(_("file1").name, e, e.name);
            e = new XMLHttpRequest();
            e.upload.addEventListener("progress", progressHandler, !1),
                e.addEventListener("load", completeHandler, !1),
                e.addEventListener("loadstart", startHandler, !1),
                e.addEventListener("error", errorHandler, !1),
                e.addEventListener("abort", abortHandler, !1),
                e.open("POST", "/update"),
                e.setRequestHeader("Access-Control-Allow-Headers", "*"),
                e.setRequestHeader("Access-Control-Allow-Origin", "*"),
                e.send(t);
        }
        function progressHandler(e) {
            _("loaded_n_total").innerHTML =
                "Uploaded " + e.loaded + " bytes of " + e.total;
            e = Math.round((e.loaded / e.total) * 100);
            (_("progressBar").value = e),
                (_("status").innerHTML = e + "% uploaded... please wait");
        }
        function completeHandler(e) {
            enableAll(),
                (_("status").innerHTML = "Upload Success!"),
                (_("progressBar").value = 0);
        }
        function startHandler(e) {
            disableAll();
        }
        function errorHandler(e) {
            enableAll(), (_("status").innerHTML = "Upload Failed");
        }
        function abortHandler(e) {
            enableAll(), (_("status").innerHTML = "Upload Aborted");
        }
        onlyFirmware &&
            !0 === stringToBoolean(onlyFirmware) &&
            (_("switch-container").style.display = "none"),
            _("upload_form").addEventListener("submit", (e) => {
                e.preventDefault(), uploadFile();
            });
        _("file1").addEventListener("change", function (e) {
            var t = _("file1").files[0];
            t && t.name
                ? ((_("button-send").disabled = !1), (_("progressBar").value = 0))
                : (_("button-send").disabled = !0),
                (_("status").innerHTML = "Firmware Upload!"),
                (_("loaded_n_total").innerHTML = "");
        });
    </script>
</body>

</html>
)rawliteral";

#endif /* __PAGE_H_ */
