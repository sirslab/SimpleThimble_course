#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <espnow.h>
#include <Servo.h>

// Define struct containing force sensed data
typedef struct force_data {
uint16_t force_sensed_index = 0;
} force_data;

// Initialize force_data struct
struct force_data forceData;

// Create servo objects
Servo servo_index;

// Define Master Mac address A0:A3:B3:2B:FE:58
uint8_t macMaster[] = {0x78, 0x21, 0xB4, 0x77, 0xFB, 0x40};

// Initialize other auxiliary variables
int limit = 180;
int offset_index = 0;

// Define the callback function connected to the event of receiving ESP-NOW data
void onDataReceiver(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
memcpy(&forceData, incomingData, sizeof(forceData));
servo_index.write(map(forceData.force_sensed_index, 0, 255, offset_index, limit));
ESP.wdtFeed();
}

void setup() {
// Start serial communication
Serial.begin(115200);

// Attach the servos to their respective pins
servo_index.attach(4);   // pin D5

// Disconnect from WiFi and erase the stored config
WiFi.disconnect();
ESP.eraseConfig();

// Start up sequence
servo_index.write(0);
delay(500);
servo_index.write(50);
delay(500);
servo_index.write(0);

// Set device as a Wi-Fi Station
WiFi.mode(WIFI_STA);

// Init ESP-NOW
if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
}

// Set the device to act as both a sender and receiver using ESP-NOW
esp_now_set_self_role(ESP_NOW_ROLE_COMBO);

// Add the MAC address of the master device as a peer for ESP-NOW communication
esp_now_add_peer(macMaster, ESP_NOW_ROLE_COMBO, 1, NULL, 0);

// We can register the receiver callback function
esp_now_register_recv_cb(onDataReceiver);
}

void loop() {
// loop does nothing
}