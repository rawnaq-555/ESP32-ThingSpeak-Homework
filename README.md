# ESP32 DHT22 Temperature and Humidity Monitoring

## Student Information
- **Name:** Rawnaq Marae
- **University ID:** 12401585

## Project Description
This project uses an ESP32 microcontroller and a DHT22 sensor to monitor temperature and humidity.

The project is simulated using Wokwi. The ESP32 connects to Wi-Fi, reads temperature and humidity values from the DHT22 sensor, and sends the readings to ThingSpeak using the ThingSpeak Arduino library every 20 seconds.

The project uses `ThingSpeak.setField()` and `ThingSpeak.writeFields()` to send sensor data to the ThingSpeak cloud platform.

ThingSpeak displays the collected data in two charts.

## Components
- ESP32 Development Board
- DHT22 Temperature and Humidity Sensor
- Wokwi Simulator
- ThingSpeak IoT Platform

## Required Libraries
- WiFi.h
- ThingSpeak.h
- DHT.h

## Wiring Connections

| DHT22 Pin | ESP32 Pin |
|---|---|
| VCC | 3.3V |
| DATA | GPIO 15 |
| GND | GND |

## Wokwi Simulation
https://wokwi.com/projects/478860324247301121

## ThingSpeak Channel
- **Channel Name:** Rawnaq_marae_12401585
- **Channel ID:** 3549803
- **Public URL:** https://thingspeak.com/channels/3549803

## Setup Instructions

1. Open the Wokwi simulation project.
2. Make sure the DHT sensor library and ThingSpeak library are installed.
3. Configure the Wi-Fi connection using `Wokwi-GUEST`.
4. Set the ThingSpeak Channel ID and Write API Key in `sketch.ino`.
5. Start the simulation.
6. Open the Serial Monitor to view the temperature, humidity, and ThingSpeak connection status.
7. Open the public ThingSpeak channel to view the updated charts.

## Results
The ESP32 successfully connects to Wi-Fi and sends temperature and humidity readings to ThingSpeak every 20 seconds.

The collected readings are displayed in two charts:
- **Field 1:** Temperature (°C)
- **Field 2:** Humidity (%)

A successful transmission displays the message `Data Sent to ThingSpeak` in the Serial Monitor.

The simulation and ThingSpeak charts demonstrate successful cloud-based temperature and humidity monitoring.

## Screenshots

The following screenshots show the Wokwi circuit and the ThingSpeak temperature and humidity charts.

![Wokwi Circuit](wokwi-circuit.png)

![ThingSpeak Charts](thingspeak-charts.png)

## Conclusion
The ESP32 and DHT22 sensor were successfully integrated with ThingSpeak using the Wokwi simulator. The project demonstrates real-time IoT monitoring of temperature and humidity through Wi-Fi and cloud-based visualization.
