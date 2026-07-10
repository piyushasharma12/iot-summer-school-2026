# 🏠 Room Comfort Management System Using ESP32

## About the Project

This project was developed to create a smart room monitoring system using the ESP32 microcontroller. The idea is to monitor important environmental parameters like **temperature, humidity, light intensity, , and automatically control connected devices whenever the conditions go beyond the desired range.

 the system also makes simple decisions on its own, such as turning on a fan when the temperature becomes too high or switching on a light when the room is dark. It also calculates a wellness score to indicate the overall comfort level of the room.

---

## Features

* Real-time monitoring of room conditions
* Automatic control of connected devices
* Wellness score calculation
* Sensor-based decision making
* Energy-efficient automation
* Easy to expand with IoT platforms

---

## Components Used

### Hardware

* ESP32 Development Board
* DHT11/DHT22 Sensor
* LDR Sensor
* Relay Module
* DC Fan
* LED Light
* Mini Water Pump
* Breadboard
* Jumper Wires

### Software

* Arduino IDE
* ESP32 Board Package
)

---

## How It Works

The ESP32 continuously reads data from all the sensors connected to it. Based on predefined conditions, it automatically performs different actions.

For example:

* If the temperature is too high, the fan is turned ON.
* If the room is dark, the LED light is switched ON.
* If the humidity becomes too high, the exhaust fan is activated.


The system also checks all the sensor values and calculates a wellness score that represents the overall comfort level of the room.

---

## Project Flow

```
Sensors
│
├── Temperature
├── Humidity
├── Light
        │
        ▼
      ESP32
        │
        ▼
Data Processing
        │
        ▼
Decision Making
        │
        ▼
Automatic Device Control
(Fan, Light, Exhaust Fan, Water Pump)
```

---

## Advantages

* Improves indoor comfort
* Reduces manual effort
* Saves energy
* Supports automatic plant watering
* Simple and cost-effective design
* Can be extended with cloud services or mobile applications

---

## Applications

* Smart Homes
* Offices
* Hostels
* Libraries
* Classrooms
* Indoor Gardening
* Smart Building Automation

---

## Future Improvements

Some features that can be added in the future include:

* Mobile application support
* Cloud data storage
* Voice assistant integration
* Machine learning for better predictions
* Weather-based automation
* Air quality monitoring

---

## Team Members

* Ananaya Bhagat
* Mishthi Chopra
* Piyusha Sharma
* Tanvi Kohli

---

## Note

This project was developed as part of an IoT learning project to understand how sensors, automation, and the ESP32 can be used together to build a smart indoor monitoring and control system.


author 
PIYUSHA SHARMA 
IOT027
IIT JAMMU
