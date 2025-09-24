

# **3) Building APIs for IoT**

### **Introduction**

IoT devices (sensors, actuators) need APIs to communicate with applications, cloud services, and users. APIs expose resources like device status, sensor readings, and control commands in a standardized way. To build APIs for IoT, developers use lightweight web frameworks like **Express (Node.js)** or **Flask (Python)**.

---

## **Steps to Build APIs for IoT**

1. **Select Protocol** – REST (HTTP/HTTPS), CoAP, MQTT.
2. **Define Endpoints** – Example: `/devices`, `/sensors/temp`, `/devices/{id}/control`.
3. **Choose Data Format** – JSON for readability, CBOR for constrained devices.
4. **Implement Security** – API keys, JWT tokens, HTTPS/DTLS.
5. **Integrate with Database** – Store IoT data in SQL/NoSQL/Time-series DB.
6. **Enable Real-time Updates** – Use MQTT or WebSockets when needed.

---

## **(a) Example in Node.js (Express)**

### **Install Dependencies**

```bash
npm install express body-parser
```

### **Code**

```javascript
const express = require('express');
const bodyParser = require('body-parser');

const app = express();
app.use(bodyParser.json());

// Example IoT data (simulate sensor)
let sensorData = { id: "temp_sensor_1", value: 27.5, unit: "C" };
let lightStatus = { id: "light_1", status: "OFF" };

// GET: Fetch sensor data
app.get('/api/sensors/temperature', (req, res) => {
  res.json(sensorData);
});

// POST: Control a device
app.post('/api/devices/light1/control', (req, res) => {
  const { status } = req.body;
  lightStatus.status = status;
  res.json({ message: `Light is now ${status}` });
});

// Start server
app.listen(3000, () => {
  console.log('IoT API running on http://localhost:3000');
});
```

### **Explanation**

* `/api/sensors/temperature` → GET request returns temperature data.
* `/api/devices/light1/control` → POST request to turn light ON/OFF.
* Data exchanged in **JSON**, making it easy for IoT apps to consume.

---

## **(b) Example in Python (Flask)**

### **Install Dependencies**

```bash
pip install flask
```

### **Code**

```python
from flask import Flask, request, jsonify

app = Flask(__name__)

# Example IoT data
sensor_data = {"id": "temp_sensor_1", "value": 28.2, "unit": "C"}
light_status = {"id": "light_1", "status": "OFF"}

# GET: Fetch sensor data
@app.route('/api/sensors/temperature', methods=['GET'])
def get_temperature():
    return jsonify(sensor_data)

# POST: Control a device
@app.route('/api/devices/light1/control', methods=['POST'])
def control_light():
    data = request.get_json()
    light_status['status'] = data.get('status', 'OFF')
    return jsonify({"message": f"Light is now {light_status['status']}"})

if __name__ == '__main__':
    app.run(port=5000, debug=True)
```

### **Explanation**

* Flask provides lightweight REST API framework.
* `/api/sensors/temperature` → Returns temperature JSON.
* `/api/devices/light1/control` → Accepts POST JSON payload `{ "status": "ON" }`.

---

## **Best Practices**

* Use **authentication** (API keys, JWT).
* Implement **rate limiting** to avoid overload.
* Store IoT data in a database for long-term analytics.
* Add **error handling** with standard HTTP status codes.

---

## **Conclusion**

To build APIs for IoT, developers define lightweight endpoints that expose device functionality, use JSON/CBOR for data exchange, and ensure security. Frameworks like **Express (Node.js)** and **Flask (Python)** make it simple to design REST APIs, enabling smooth communication between **devices, cloud platforms, and user applications**.

---
