This is version 2


# FIRMWARE APPLICATION FOR ESP32 DEV-KIT-V1 THAT USES SPIFFS FOR FILE SAVING AND HTTPS FOR FILE DOWNLOAD VIA HTTPS PROTOCOL 
    NOTE: Version-2 is just the updated and advance version of Version-1 with new programs

Check my Project Videos:
    (https://drive.google.com/drive/u/1/folders/1sDHBQAxutHWzhlY8MnNhDF_fwrui1atU)
    Check above link where I create and explain the whole project.

Prerequrisits: 
    1. ESP32 Plugin for Arduino IDE 
    2. SPIFFS File system 
    3. WiFi library and module
    4. WiFi ClientSecure module and HTTP module for ESP32
    5. Arduino IDE version 1.8.18
    NOTE: SPIFFS file systems is not optimized for newer arduino IDE versions, so it is better to use version 1.8.18

Project Description
    Developed a firmware application for ESP32 Dev-Kit-V1 microcontroller using Arduino IDE & Arduino-ESP32 Plugin, 
    This firmware downloads web file via HTTPS from a public URL and writes it to SPIFFS(SPI flash file system) at a speed of at least 150KBps 
    - Implemented WiFi connectivity that uses WiFi modules for internet connectivity. 
    - Implemented “Https Client-secure” module for Web connectivity, Https GET requests
    - Implemented SPIFFS(SPI-Flash File system) that creates files for storage of packet data.
    - The project is implemented using ESP32 Plugin for Arduino IDE & SPI-Flash file system.

Libraries and header files
    #include SPIFFS.h
    #include FS.h
    #include <WiFi.h>
    #include <WiFiClientSecure>
    #include <HTTP.h>
NOTE: After everything is set. You can directly select you ESP32 development board for Arduino IDE and select port and Directly flash the code.
FOOTNOTES: This project contains version-1 and version-2. 
Version 2 is updated version of version 1 that contains larger buffer for larger payload data for HTTPS GET request.



































