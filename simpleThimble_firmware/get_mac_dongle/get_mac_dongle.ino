#include <Arduino.h>
#include <WiFi.h>

void setup() {
Serial.begin(115200);

// Set device as a Wi-Fi Station
WiFi.mode(WIFI_STA);

// Get Mac Add
Serial.println();
Serial.print("Mac Address: ");
Serial.println(WiFi.macAddress());
}

void loop() {
// the loop does nothing
}