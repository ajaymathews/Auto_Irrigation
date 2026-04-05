# Auto Irrigation System 

A modernized, secure, and power-efficient smart irrigation system built for the NodeMCU (ESP8266). This system monitors soil moisture levels and automatically triggers a water pump/relay while syncing status to the Blynk IoT cloud.

## Key Features
- **IoT Enabled**: Real-time monitoring via Blynk app.
- **Power Optimization**: Uses **Deep Sleep** to conserve battery (wakes up every 30 minutes).
- **Secure Credentials**: All Wi-Fi and API tokens are managed in a separate `config.h` file.
- **I2C Display Support**: Reduces wiring complexity by using only 2 pins for the LCD.

## Required Components
1. **NodeMCU (ESP8266)**
2. **Capacitive/Resistive Soil Moisture Sensor**
3. **5V Relay Module** (for Water Pump/Solenoid)
4. **16x2 I2C LCD Display**
5. **Jumper Wires & Breadboard**
6. **External Power Source** (e.g., Li-ion battery or 5V Adapter)

## Wiring Diagram
| Component | NodeMCU Pin | Description |
| :--- | :--- | :--- |
| **Soil Sensor** | A0 | Analog Input |
| **Relay** | D5 (GPIO14) | Digital Output |
| **LCD SDA** | D2 (GPIO4) | I2C Data |
| **LCD SCL** | D1 (GPIO5) | I2C Clock |
| **Deep Sleep Link**| D0 to RST | **CRITICAL**: Connect D0 to RST for wake-up support |

## Getting Started

### 1. Configure Credentials
Before uploading the code, update the `config.h` file with your network and Blynk details:

```cpp
#define WIFI_SSID       "Your_WiFi_Name"
#define WIFI_PASS       "Your_WiFi_Password"
#define BLYNK_AUTH_TOKEN "Your_Blynk_Token"
```

### 2. Libraries Required
Ensure you have the following libraries installed in your Arduino IDE:
- `ESP8266WiFi`
- `BlynkSimpleEsp8266`
- `LiquidCrystal_I2C`

### 3. Hardware Setup
- Connect the components as per the wiring table.
- **Note**: For Deep Sleep to work, you must connect **GPIO16 (D0)** to the **RST** pin after uploading the code (as the board won't upload if they are connected).

### 4. Calibration
If your moisture readings are inaccurate, adjust the `DRY_VALUE` and `WET_VALUE` constants in `config.h` based on your sensor's serial output.
