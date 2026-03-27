#✈️ ESP32 Smart Plane Controller (SARJUL DEV)

A powerful ESP32-based dual motor plane control system with real-time web controller, gyro stabilization, and multi-touch joystick support.

---

🚀 Features

- 🎮 Dual Virtual Joystick (Mobile Control)
- ✌️ Multi-touch Support (2 Finger Control)
- 🧠 Gyro Stabilization (MPU6050)
- 🔘 Manual ON/OFF Stabilization
- 🚨 Flip Protection System
- 📡 Real-time Web Control (No App Required)
- ⚡ Smooth Motor Control (PWM)
- ✍️ Built-in Watermark (SARJUL DEV)

---

📦 Components Required

Component| Quantity
ESP32 Board| 1
MPU6050 Gyroscope| 1
DC Motors| 2
MOSFET (IRFZ44N / IRLZ44N Recommended)| 2
Flyback Diode (1N4007)| 2
External Battery (7.4V / 11.1V LiPo Recommended)| 1
Jumper Wires| As needed

---

🔌 Wiring Diagram

🧠 MPU6050 → ESP32

MPU6050| ESP32
VCC| 3.3V
GND| GND
SDA| GPIO 21
SCL| GPIO 22

---

⚡ Motor + MOSFET Connection

For EACH Motor:

- Motor + → Battery +
- Motor - → MOSFET Drain
- MOSFET Source → GND
- MOSFET Gate → ESP32 GPIO

Motor| ESP32 Pin
Left Motor| GPIO 25
Right Motor| GPIO 26

---

🔥 Flyback Diode (IMPORTANT)

- Diode across motor terminals
- Stripe side → Battery +
- Other side → Motor -

---

📡 How It Works

1. ESP32 creates WiFi:
   
   SSID: ESP32-PLANE
Password: 12345678

2. Connect your phone to this WiFi

3. Open browser and go to:
   
   http://192.168.4.1

4. Control using dual joysticks

---

🎮 Controls

Action| Result
Both Joystick Up| Move Forward
Left ↑ Right ↓| Turn Right
Right ↑ Left ↓| Turn Left
Release| Stop

---

🧠 Gyro Stabilization

- Default: OFF
- Enable from top-right button
- Automatically:
  - Balances left-right tilt
  - Prevents flipping
  - Assists control

---

⚠️ Safety Tips

- Always test at LOW speed first
- Use proper battery (LiPo recommended)
- Never connect motor directly to ESP32
- Always use MOSFET

---

🔥 Troubleshooting

❌ Motor not working

- Check MOSFET wiring
- Check battery voltage

❌ Gyro not working

- Check SDA/SCL connections
- Ensure MPU6050 initialized

❌ Web UI not loading

- Confirm WiFi connection
- Open "192.168.4.1"

---

💡 Future Upgrades

- PID Stabilization
- Auto Straight Flight Mode
- Compass (Heading Lock)
- Mobile App Version

---

👨‍💻 Author

SARJUL DEV

---

⭐ Support

If you like this project:

- ⭐ Star the repo
- 🔁 Share with others
- 💬 Give feedback

---

🔥 Built with passion by SARJUL DEV
