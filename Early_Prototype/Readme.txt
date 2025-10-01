
This is the version on of the project that contains basic blueprint like structrue for the Final project, which is version-2.

Check my Project Videos:
    (https://drive.google.com/drive/u/1/folders/1sDHBQAxutHWzhlY8MnNhDF_fwrui1atU)
    Check above link where I create and explain the whole project.

Project Description
    Developed a firmware application for ESP32 Dev-Kit-V1 microcontroller using Arduino IDE & Arduino-ESP32 Plugin, 
    This firmware downloads web file via HTTPS from a public URL and writes it to SPIFFS(SPI flash file system) at a speed of at least 150KBps 
    - Implemented WiFi connectivity that uses WiFi modules for internet connectivity. 
    - Implemented “Https Client-secure” module for Web connectivity, Https GET requests
    - Implemented SPIFFS(SPI-Flash File system) that creates files for storage of packet data.
    - The project is implemented using ESP32 Plugin for Arduino IDE & SPI-Flash file system.

Prerequrisits: 
    1. ESP32 Plugin for Arduino IDE 
    2. SPIFFS File system 
    3. WiFi library and module
    4. WiFi ClientSecure module and HTTP module for ESP32
    5. Arduino IDE version 1.8.18
    NOTE: SPIFFS file systems is not optimized for newer arduino IDE versions, so it is better to use version 1.8.18

Includes the below libraries/header files & their functions in the code.
  #include "FS.h"
  #include "SPIFFS.h"
  #include <WiFi.h>
  #include <HTTPClient.h>
  #include <WiFiClientSecure.h>

///---WiFi FUnction used in the project---///
    WiFi.begin(ssid, password);
    WiFi.status() 
    WiFi.SSID();

///---SPIFFS Functions used in this project---///
    SPIFFS.begin(true)
    SPIFFS.open(filename, FILE_WRITE);
    File.readString()
    File.read();
    File.close();
    SPIFFS.remove();
    file.write();

///---HTTP & HTTPS FUnctions used int this project---///
    WiFiClientSecure client;
    client.setInsecure();  // skip certificate check
    HTTPClient http;
    http.begin(client, url)) {
    http.GET();
    http.getStreamPtr();
    http.end();


 
