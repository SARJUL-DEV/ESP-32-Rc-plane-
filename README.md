✈️ ESP Smart Plane System (NRF Controller + Receiver)

By SARJUL DEV

This project uses NRF24L01 wireless communication for fast and stable control.

Controller → ESP8266 + NRF24L01
Receiver → ESP32 + NRF24L01 + MPU6050 + Motors

---

🧠 SYSTEM FLOW

[ Mobile Phone ]
        ↓ WiFi
[ ESP8266 Controller ]
        ↓ NRF24 Signal
[ ESP32 Receiver ]
        ↓
[ Motors + Gyro Control ]

---

🎮 CONTROLLER (ESP8266 + NRF24L01)

---

🔌 NRF24L01 → ESP8266 Wiring

        NRF24L01        ESP8266 (NodeMCU)

        +--------+      +------------------+
        | VCC    | ---> | 3.3V ⚠️          |
        | GND    | ---> | GND              |
        | CE     | ---> | D2 (GPIO4)       |
        | CSN    | ---> | D8 (GPIO15)      |
        | SCK    | ---> | D5 (GPIO14)      |
        | MOSI   | ---> | D7 (GPIO13)      |
        | MISO   | ---> | D6 (GPIO12)      |
        +--------+      +------------------+

⚠️ IMPORTANT:

- NEVER connect NRF to 5V
- Use stable 3.3V (recommended capacitor 10µF)

---

🛩️ RECEIVER (ESP32 + NRF24L01 + MPU6050)

---

🔌 NRF24L01 → ESP32 Wiring

        NRF24L01        ESP32

        +--------+      +------------------+
        | VCC    | ---> | 3.3V ⚠️          |
        | GND    | ---> | GND              |
        | CE     | ---> | GPIO 4           |
        | CSN    | ---> | GPIO 5           |
        | SCK    | ---> | GPIO 18          |
        | MOSI   | ---> | GPIO 23          |
        | MISO   | ---> | GPIO 19          |
        +--------+      +------------------+

---

🔌 MPU6050 → ESP32

MPU6050        ESP32

VCC    ------> 3.3V  
GND    ------> GND  
SDA    ------> GPIO21  
SCL    ------> GPIO22  

---

⚡ MOTOR + MOSFET CONNECTION

LEFT MOTOR

Battery (+) ---- Motor (+)
Motor (-) ------ Drain (MOSFET)
Source --------- GND
Gate ----------- GPIO 25

---

RIGHT MOTOR

Battery (+) ---- Motor (+)
Motor (-) ------ Drain (MOSFET)
Source --------- GND
Gate ----------- GPIO 26

---

🔥 FLYBACK DIODE

     Motor

   + -----------+
   |           |
   |   MOTOR   |
   |           |
   +-----------+

Diode:
Stripe → Battery +
Other → Motor -

---

🧠 FULL RECEIVER DIAGRAM

              [ ESP32 ]

     GPIO25 -------- MOSFET -------- Motor L
     GPIO26 -------- MOSFET -------- Motor R

     GPIO4  -------- CE (NRF)
     GPIO5  -------- CSN (NRF)
     GPIO18 -------- SCK
     GPIO23 -------- MOSI
     GPIO19 -------- MISO

     GPIO21 -------- SDA (MPU6050)
     GPIO22 -------- SCL (MPU6050)

     3.3V -------- VCC (NRF + MPU6050)
     GND  -------- GND (ALL)

         Battery → Motors

---

📡 HOW SYSTEM WORKS

1. ESP8266 reads joystick input (web UI)
2. Sends data via NRF24L01
3. ESP32 receives data
4. Controls motors + stabilization

---

⚠️ IMPORTANT RULES

- NRF MUST use 3.3V only
- Add capacitor (10µF) across VCC & GND (NRF)
- Keep wires short
- Use proper battery for motors

---

🔥 COMMON ISSUES

NRF not connecting
→ Check CE/CSN pins

Random disconnect
→ Add capacitor

No motor response
→ Check MOSFET wiring

---

💯 FINAL RESULT

- Ultra fast control (NRF)
- No WiFi lag
- Stable flight
- Long range control

---

👨‍💻 AUTHOR

SARJUL DEV

---

🔥 Built for high-performance wireless control
