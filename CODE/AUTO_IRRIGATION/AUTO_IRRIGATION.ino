/*
* AUTO_IRRIGATION.ino - Modernized IoT NodeMCU Application
* Features: Wi-Fi, Blynk integration, Deep Sleep for power efficiency, I2C LCD support.
* Logic: Wakes up, reads soil moisture, irrigates if needed, sends data to cloud, and sleeps.
*/

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <LiquidCrystal_I2C.h>
#include "config.h"

// --- Global Objects ---
LiquidCrystal_I2C lcd(0x27, 16, 2); // Default I2C address 0x27

void setup()
{
  Serial.begin(115200);
  Serial.println("\n--- AUTO-IRRIGATION SYSTEM STARTING ---");

  // --- Hardware Initialization ---
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(SOIL_MOISTURE_PIN, INPUT);
  digitalWrite(RELAY_PIN, LOW); // Ensure relay starts off

  // --- LCD Initialization ---
  lcd.init();
  lcd.backlight();
  lcd.print("IRRIGATION SYS");
  lcd.setCursor(0, 1);
  lcd.print("INITIALIZING...");

  // --- IoT Connectivity ---
  Serial.print("Connecting to Blynk...");
  Blynk.begin(BLYNK_AUTH_TOKEN, WIFI_SSID, WIFI_PASS);
  Serial.println(" Connected!");

  // --- Sensor Reading & Calibration ---
  int rawValue = analogRead(SOIL_MOISTURE_PIN);
  float moisturePercent = map(rawValue, DRY_VALUE, WET_VALUE, 0, 100);
  
  // Constrain percent to [0, 100]
  moisturePercent = constrain(moisturePercent, 0, 100);

  Serial.printf("Raw Sensor: %d | Moisture: %.2f%%\n", rawValue, moisturePercent);

  // --- Update Displays ---
  lcd.clear();
  lcd.print("Moisture: ");
  lcd.print((int)moisturePercent);
  lcd.print("%");

  Blynk.virtualWrite(V1, moisturePercent); // Send data to Blynk Virtual Pin V1

  // --- Irrigation Logic ---
  if (moisturePercent < MOISTURE_THRESHOLD) {
    Serial.println("STATUS: THRESHOLD EXCEEDED - Starting Irrigation...");
    lcd.setCursor(0, 1);
    lcd.print("PUMP: ON ");
    
    digitalWrite(RELAY_PIN, HIGH);
    delay(5000);              // Irrigate for 5 seconds (Adjust as needed)
    digitalWrite(RELAY_PIN, LOW);
    
    lcd.setCursor(0, 1);
    lcd.print("PUMP: OFF");
  } else {
    Serial.println("STATUS: MOISTURE OK");
    lcd.setCursor(0, 1);
    lcd.print("STATUS: OK");
  }

  // --- Power Saving: Deep Sleep ---
  Serial.println("SYSTEM: Cycle complete. Entering Deep Sleep...");
  delay(1000); // Allow time for Blynk data to be sent
  ESP.deepSleep(SLEEP_DURATION); 
}

void loop() 
{
  // Since we use Deep Sleep, loop() is never reached.
  // The system resets and restarts setup() on wake.
}
