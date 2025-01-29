#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <espnow.h>
#include <Servo.h>

Servo servo_idx;   // create servo object to control a servo
Servo servo_thmb;  // create servo object to control a servo

void setup() {
    Serial.begin(115200);
    delay(1000);
    servo_idx.attach(4);  // attaches the servo on pin D5 to the servo object
    
    WiFi.disconnect();
    ESP.eraseConfig();

    servo_idx.write(0);
    delay(500);
    servo_idx.write(180);
    delay(500);
    servo_idx.write(0);

    //pinMode(LED_BUILTIN, OUTPUT);
    //digitalWrite(LED_BUILTIN, LOW);

    // Wifi STA Mode
    WiFi.mode(WIFI_STA);

    // Get Mac Add
    Serial.println();
    Serial.print("Mac Address: ");
    Serial.print(WiFi.macAddress());
}

void loop() {
    // loop does nothing.
}