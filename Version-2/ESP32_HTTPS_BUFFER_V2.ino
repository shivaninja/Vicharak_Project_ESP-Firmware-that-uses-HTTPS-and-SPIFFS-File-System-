#include "FS.h"
#include "SPIFFS.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>

const char* ssid = "wisdom and wine";
const char* password = "permissiongr@nted";
const char* filename = "/one.txt";
const char* url = "https://raw.githubusercontent.com/mdn/learning-area/main/javascript/introduction-to-js-1/assessment-start/raw-text.txt";

// Larger buffer for higher throughput
#define BUFFER_SIZE 16384   // 16 KB (safe for most ESP32 boards)

void setup() {
  Serial.begin(115200);

  // Connect Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected!");

  // Mount SPIFFS
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

      uint8_t *buff = (uint8_t*) malloc(BUFFER_SIZE);
      if (!buff) {
        Serial.println("Buffer allocation failed!");
        return;
      }

      unsigned long start = millis();
      int total = 0;

      while (http.connected() && (stream->available() > 0)) {
        int len = stream->read(buff, BUFFER_SIZE);  // non-blocking read
        if (len > 0) {
          file.write(buff, len);   // write in large chunks
          total += len;
        }
      }

      file.close();
      unsigned long duration = millis() - start;
      float speed = (total / 1024.0) / (duration / 1000.0);
      Serial.printf("Downloaded %d bytes in %.2f sec (%.2f KB/s)\n",
                    total, duration / 1000.0, speed);

      free(buff);

      // Optional: Read back
      File readFile = SPIFFS.open(filename, FILE_READ);
      if (readFile) {
        Serial.println("File content:");
        Serial.println(readFile.readString());
        readFile.close();
      }

    } else {
      Serial.printf("HTTP GET failed, code: %d\n", httpCode);
    }
    http.end();
  } else {
    Serial.println("Connection failed");
  }
}

void loop() {}
