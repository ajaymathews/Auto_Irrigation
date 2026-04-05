/*
* config.h - Credential Management & Hardware Constants
* Auto_Irrigation Project
*/

#ifndef CONFIG_H
#define CONFIG_H

// --- Wi-Fi Credentials ---
#define WIFI_SSID       "<WIFI_SSID>"
#define WIFI_PASS       "<WIFI_PASS>"

// --- Blynk Configuration ---
#define BLYNK_TEMPLATE_ID   "<TEMPLATE_ID>"
#define BLYNK_TEMPLATE_NAME "<TEMPLATE_NAME>"
#define BLYNK_AUTH_TOKEN    "<BLYNK_AUTH_TOKEN>"

// --- Hardware Pin Assignments (NodeMCU/ESP8266) ---
#define SOIL_MOISTURE_PIN   A0       // Analog input for soil sensor
#define RELAY_PIN           D5       // GPIO14 - Digital output for relay control
#define LCD_SDA             D2       // GPIO4 - I2C SDA
#define LCD_SCL             D1       // GPIO5 - I2C SCL

// --- Operational Parameters ---
#define MOISTURE_THRESHOLD  30       // Start irrigation if moisture is below 30%
#define SLEEP_DURATION      1800E6   // Deep Sleep for 30 minutes (in microseconds)

// --- Calibration Settings ---
#define DRY_VALUE           1024     // Analog reading for dry soil
#define WET_VALUE           400      // Analog reading for wet soil (saturated)

#endif // CONFIG_H
