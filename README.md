✈️ ESP32 Smart Plane Controller (SARJUL DEV)

This project is a smart dual-motor plane control system built using ESP32 and MPU6050.
It provides real-time control through a mobile browser with a smooth joystick interface and built-in stabilization.

---

🚀 Features

- Dual joystick control (mobile friendly)
- Multi-touch support (control both motors at the same time)
- Gyro stabilization (left-right balance using MPU6050)
- Manual ON/OFF stabilization button
- Flip protection system
- Real-time web control (no app needed)
- Smooth PWM motor control
- Built-in watermark (SARJUL DEV)

---

🔧 Components Required

- ESP32 development board
- MPU6050 gyroscope module
- 2 × DC motors
- 2 × MOSFET (IRLZ44N recommended)
- 2 × flyback diode (1N4007)
- LiPo battery (7.4V or 11.1V recommended)
- Jumper wires

---

🔌 Connections

MPU6050 to ESP32

- VCC → 3.3V
- GND → GND
- SDA → GPIO 21
- SCL → GPIO 22

---

Motors using MOSFET

For each motor:

- Motor positive → Battery positive
- Motor negative → MOSFET Drain
- MOSFET Source → GND
- MOSFET Gate → ESP32 pin

Left motor → GPIO 25
Right motor → GPIO 26

---

Flyback Diode (Important)

- Connect across motor terminals
- Stripe side → Battery positive
- Other side → Motor negative

---

📡 Usage

1. Upload the code to ESP32
2. Turn on the device
3. Connect your phone to WiFi:

ESP32-PLANE
Password: 12345678

4. Open browser and go to:

http://192.168.4.1

5. Control the plane using joysticks

---

🎮 Controls

- Both joysticks up → forward
- Left high + right low → turn right
- Right high + left low → turn left
- Release → motors stop

---

🧠 Stabilization

- Default is OFF
- Turn ON using button on top-right
- Automatically balances left-right tilt
- Prevents sudden flipping

---

⚠️ Safety

- Always test at low speed first
- Use proper battery (LiPo recommended)
- Never power motors directly from ESP32
- Always use MOSFET for motors

---

🔥 Troubleshooting

Motor not working

- Check MOSFET wiring
- Check battery

Gyro not working

- Check SDA and SCL pins
- Make sure MPU6050 is connected properly

Web page not opening

- Make sure you are connected to ESP32 WiFi
- Open 192.168.4.1

---

💡 Future Ideas

- PID stabilization
- Auto straight flight mode
- Compass integration
- Mobile app version

---

👨‍💻 Author

SARJUL DEV

---

⭐ Support

If you like this project, consider starring the repository and sharing it.

---

Built with passion by SARJUL DEV
