# Arduino IDE Setup for ESP32 and ESP8266

This guide provides step-by-step instructions to configure the Arduino IDE for working with ESP32 and ESP8266 boards.

## Prerequisites

- **Arduino IDE Version**: 2.3.1  
  Download for Windows (64-bit): [Arduino IDE 2.3.1](https://github.com/arduino/arduino-ide/releases/download/2.3.1/arduino-ide_2.3.1_Windows_64bit.msi)

---

## Setup Instructions

### Step 1: Install Arduino IDE

1. Download the [Arduino IDE 2.3.1](https://github.com/arduino/arduino-ide/releases/download/2.3.1/arduino-ide_2.3.1_Windows_64bit.msi).
2. Run the `.msi` file and follow the installation instructions.

---

### Step 2: Add ESP Board Manager URLs

1. Open Arduino IDE.
2. Navigate to **File -> Preferences**.
3. Scroll to the "Additional Boards Manager URLs" field and click the blue icon to open the input field.
4. Add the following URLs:
```bash
https://dl.espressif.com/dl/package_esp32_index.json
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
https://arduino.esp8266.com/stable/package_esp8266com_index.json
```
5. Click **OK** to save and close the Preferences window.

---

### Step 3: Install ESP32 and ESP8266 Board Packages

1. Go to **Tools -> Board -> Board Manager**.
2. Search for `esp` in the search bar.
3. Install the following packages:
- **ESP32 by Espressif Systems (version 2.0.5)**
- **ESP8266 by ESP8266 Community (version 2.7.4)**

---

## Troubleshooting

### Missing Drivers
1. Open **Device Manager** on your system and check the type of USB-to-UART conversion chip being used.
2. Based on the chip type, download the corresponding driver. For example:
- If the chip type is **USB-SERIAL CH340**, download the driver from [this link](https://sparks.gogo.co.nz/assets/site/downloads/CH34x_Install_Windows_v3_4.zip).
3. Additional drivers:
- **ESP8266 Drivers**: [Download CP210x Drivers](https://www.silabs.com/documents/public/software/CP210x_Windows_Drivers.zip)  
- **ESP32 Drivers**: [Install CH9102 Drivers](https://learn.adafruit.com/how-to-install-drivers-for-wch-usb-to-serial-chips-ch9102f-ch9102/windows-driver-installation)

---

## Additional Resources

- [Official Arduino IDE Documentation](https://www.arduino.cc/en/software)
- [ESP32 GitHub Repository](https://github.com/espressif/arduino-esp32)
- [ESP8266 GitHub Repository](https://github.com/esp8266/Arduino)
