# Vicharak Internship Project
Project1 — Google Home Automation with Voice-Controlled LED

 # Project Description

Develop a firmware application for ESP32 Dev Kit that downloads a file via HTTPS from a public URL and writes it to SPIFFS (SPI Flash File System) at a speed of at least 400 KB/s.

Firmware application for ESP32 Dev-Kit-V1 that downloads files via HTTPS and saves them to SPIFFS.
Version-2 is an improved version of Version-1 with structural & performance changes.

# Prerequisites

ESP32 Plugin for Arduino IDE

SPIFFS file system (SPI Flash File System)

WiFi library

WiFiClientSecure + HTTP modules

Arduino IDE version 1.8.18

# SPIFFS is not optimized in newer Arduino IDE versions, so 1.8.18 is preferred.

# Project Summary

Developed a firmware application for the ESP32 Dev-Kit-V1 microcontroller using the Arduino-ESP32 framework.
The firmware downloads a file via HTTPS and writes it to SPIFFS at ~150 KB/s.

Core Implementations:

Implemented WiFi connectivity

Implemented HTTPS GET using WiFiClientSecure

Implemented SPIFFS Flash file system for file buffering & write operations

Designed buffer logic to manage high-speed download streams

# SPIFFS Limitations Case Study

I wrote a PDF analyzing:

SPIFFS latency issues

Write frequency bottlenecks

Impact on download speed

Performance constraints for large payloads

# Libraries & Headers Used
#include "FS.h"
#include "SPIFFS.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>

# WiFi functions
WiFi.begin(ssid, password);
WiFi.status();
WiFi.SSID();

# SPIFFS functions
SPIFFS.begin(true);
SPIFFS.open(filename, FILE_WRITE);
File.readString();
File.read();
File.write();
File.close();
SPIFFS.remove();

# HTTP / HTTPS handling
WiFiClientSecure client;
client.setInsecure();      // skip certificate check

HTTPClient http;
http.begin(client, url);
http.GET();
http.getStreamPtr();
http.end();

# Video Demo

# https://drive.google.com/drive/u/1/folders/1sDHBQAxutHWzhlY8MnNhDF_fwrui1atU

# Project Versions
Version-1

Basic project structure

Low-capacity buffer

Prototype for architecture & logic flow

Version-2

Optimized buffers for larger HTTPS payloads

More robust file handling

Improved SPIFFS performance

# Conclusion

This project demonstrates:

Embedded WiFi networking

HTTPS data transfer

Flash file systems (SPIFFS)

Real-world firmware performance considerations
