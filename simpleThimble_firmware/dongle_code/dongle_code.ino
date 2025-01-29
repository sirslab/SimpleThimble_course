#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>

// Define ESP8266 Mac address (first peer) C8:C9:A3:26:18:E4
uint8_t mac_peer1[] = { 0xC8, 0xC9, 0xA3, 0x26, 0x18, 0xE4 };

// Define peer info struct for first device
esp_now_peer_info_t peer1;

// Define struct containing force sensed data
typedef struct force_data {
    uint16_t force_sensed_index = 0;
};

// Initialize force_data struct
struct force_data forceData;

// Define variables for raw and received force sensed data
byte raw_value_index = 0;
uint8_t received_value_index = 0;


void setup() {
    // Start serial communication
    Serial.begin(115200);

    // Set device as a Wi-Fi Station
    WiFi.mode(WIFI_STA);

    // Init ESP-NOW
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    // Set peer1's address and channel, and disable encryption
    memcpy(peer1.peer_addr, mac_peer1, 6);
    peer1.channel = 1;
    peer1.encrypt = 0;

    // Register peer1
    Serial.println("Registering a peer 1");
    if (esp_now_add_peer(&peer1) == ESP_OK) {
        Serial.println("Peer 1 added");
    }
}


void loop() {
    // Check for available serial data
    if (Serial.available() > 0) {

        // Read raw force sensed data from serial input
        raw_value_index = (byte)(Serial.read());

        // Map raw force sensed values to a range of 0-255
        received_value_index = map((int)(raw_value_index), 36, 255, 0, 255);

        // Store mapped force sensed values in forceData struct
        forceData.force_sensed_index = received_value_index;

        // Send forceData to peer1 using ESP-NOW
        esp_now_send(peer1.peer_addr, (uint8_t *)&forceData, sizeof(forceData));

        // Print force sensed data to serial monitor
        Serial.println("-----------------");
        Serial.print("index finger: ");
        Serial.println(forceData.force_sensed_index);
    }
}