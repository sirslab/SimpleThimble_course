#include <Arduino.h>
#include <ESP8266WiFi.h>

void setup() {
Serial.begin(115200);
WiFi.disconnect();
ESP.eraseConfig();

// Wifi STA Mode
WiFi.mode(WIFI_STA);

// Get Mac Add
Serial.println();
Serial.print("Mac Address: ");
Serial.print(WiFi.macAddress());
}


void loop() {
// the loop does nothing
}