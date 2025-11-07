# 🛰️ EDC Project — Smart Sensor-Controlled Servo System

## 📖 Overview
This project is part of the **Electronic Devices and Circuits (EDC)** lab.  
It integrates **Arduino** and **Node.js** to demonstrate real-time sensor monitoring and servo motor control over a network.

The Arduino continuously reads a sensor value (like moisture or temperature) and transmits:
- The **sensor value**
- A **control signal** — `1` for ON and `0` for OFF

The Node.js server receives these values, processes them, and logs or reacts accordingly — such as turning a servo motor ON/OFF.

---

## ⚙️ Hardware Setup
- Arduino Uno / ESP32 / compatible microcontroller  
- Sensor (e.g., LM35, soil moisture sensor)  
- Servo Motor  
- Jumper wires and power source

---

## 🧠 Working Principle
1. The sensor measures data continuously.
2. Arduino reads the analog value.
3. If the sensor reading exceeds a set threshold, Arduino sends it to server.js
4. The server.js receives this data and updates the servo motor state.

---

## 🖥️ Software Components

| Component | Description |
|------------|--------------|
| **Arduino Sketch (`.ino`)** | Reads sensor data and sends sensor value + ON/OFF signal. |
| **server.js (`node.js`)** | Receives and logs data from Arduino. |
| **Frontend** | Displays live sensor readings. |

---

## 🧩 Example Serial Data
Sensor: 812, Status: 1
Sensor: 820, Status: 0

---

## 🚀 How to Run

### 1. Upload Arduino Code
Upload your `.ino` sketch to the Arduino board. Make sure serial monitor is off or crossed out.

### 2. Run the Node Server
```bash
node server.js
```

###3. View Data
Open your terminal or dashboard to see:
Sensor Value: <value>, Servo: ON/OFF on dashboard.


##📦 Future Enhancements

Add live graph visualization (HTML/JS).
Store data in a database (MongoDB/Firebase).
Add notification alerts when thresholds are crossed.

##💡 Summary
This project demonstrates IoT integration between Arduino and Node.js, combining sensor-based input with actuator control.
It’s a simple yet powerful setup to explore real-time data transfer, automation, and hardware-software communication.
