#include "FS.h"
#include "SPIFFS.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>

//___ALL THE VARIABLES & CONSTANTS___//
const char* ssid = "wisdom and wine";
const char* password = "permissiongr@nted";
const char* filename = "/one.txt";
const char* url = "https://www.youtube.com/";

//___BUFFER SIZE THAT I WANT TO ALLOCATE INTO MEMORY DYNAMICALLY___//
#define BUFFER_SIZE 1024   // 1 KB buffer (enough for good speed)

void setup() {
  Serial.begin(115200);

  //___WIFI CONNECTION SYSTEM__//
  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected!");

  //__SPIFFS_SYSTEM___//
  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS Mount Failed");
  return;
  }

  WiFiClientSecure client;
  client.setInsecure();  // skip certificate check
  HTTPClient http;

  if (http.begin(client, url)) {
    int httpCode = http.GET();
    if (httpCode == HTTP_CODE_OK) {
      WiFiClient *stream = http.getStreamPtr();
      File file = SPIFFS.open(filename, FILE_WRITE);
      if (!file) {
        Serial.println("File open failed");
        return;
      }

      uint8_t buff[BUFFER_SIZE];
      unsigned long start = millis();
      int total = 0;

      //___TAKING_STREAMM_&_WRITING_IT_INTO_FILE___//
      while (http.connected() && stream->available()) {
        int len = stream->readBytes(buff, BUFFER_SIZE);
        file.write(buff, len);
        total += len;
      }

      file.close();
      unsigned long duration = millis() - start;
      float speed = (total / 1024.0) / (duration / 1000.0);
      Serial.printf("Downloaded %d bytes in %.2f sec (%.2f KB/s)\n", total, duration / 1000.0, speed);

      //__READING THE DATA THAT WE JUST WROTE INTO FILE SYSTEM__//
      File readFile = SPIFFS.open(filename, FILE_READ);
      if (readFile) {
        Serial.println("File content:");
        Serial.println(readFile.readString());
        readFile.close();
      }

    } else {
      Serial.printf("HTTP GET failed, code: %d\n", httpCode);
    }
    //___CLOSING HTTP CONNECTIONS___//
    http.end();
  } else {
    Serial.println("Connection failed");
  }
}

void loop() {}


