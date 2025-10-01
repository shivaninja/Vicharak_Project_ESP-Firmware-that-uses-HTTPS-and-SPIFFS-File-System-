
This is the version on of the project that contains basic blueprint like structrue for the Final project, which is version-2.


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


 
