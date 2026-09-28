# DHT11 Temperature & Humidity Monitor

An Arduino Uno project that measures temperature and humidity using a DHT11 sensor and displays the readings on a 16x2 LCD. The system displays humidity, temperature in Celsius, and temperature in Fahrenheit.

## Features

- Measures temperature using a DHT11 sensor
- Measures relative humidity
- Converts temperature from Celsius to Fahrenheit
- Displays live readings on a 16x2 LCD
- Outputs sensor readings to the Arduino Serial Monitor
- Updates readings every 5 seconds

## Components

- Arduino Uno R3
- DHT11 temperature and humidity sensor
- LCD1602 16x2 display
- 10k potentiometer
- Breadboard
- wires

## Wiring

### DHT11

| DHT11 Pin | Arduino Connection |
|---|---|
| VCC | 5V |
| DATA | Digital Pin 7 |
| GND | GND |

### LCD1602

| LCD Pin | Function | Arduino Connection |
|---|---|---|
| 1 | VSS | GND |
| 2 | VDD | 5V |
| 3 | VO | Potentiometer |
| 4 | RS | Digital Pin 12 |
| 5 | RW | GND |
| 6 | E | Digital Pin 11 |
| 7–10 | D0–D3 | Not Connected |
| 11 | D4 | Digital Pin 5 |
| 12 | D5 | Digital Pin 4 |
| 13 | D6 | Digital Pin 3 |
| 14 | D7 | Digital Pin 2 |
| 15 | A | 5V |
| 16 | K | GND |

The potentiometer is connected between 5V and GND, with the center pin connected to the LCD VO pin to control the display contrast.

## Required Libraries

This project uses the following Arduino libraries:

- DHT sensor library by Adafruit
- Adafruit Unified Sensor
- LiquidCrystal

The DHT libraries can be installed through the Arduino IDE Library Manager. LiquidCrystal is included with the Arduino IDE.

## How It Works

The DHT11 measures the current temperature and humidity. The Arduino reads these values and converts the Celsius temperature to Fahrenheit using:

`F = (C × 9 / 5) + 32`

The readings are then displayed on the LCD in the following format:

```text
Humidity: 32%
C:24.8 F:76.6
```

The same sensor readings are also sent to the Serial Monitor at 9600 baud.

## Running the Project

1. Connect the DHT11 and LCD1602 to the Arduino using the wiring tables above.
2. Install the required libraries through the Arduino IDE.
3. Open `DHT11_Temperature_Humidity_Sensor.ino`.
4. Select the correct Arduino board and COM port.
5. Upload the program to the Arduino Uno.
6. The LCD will begin displaying temperature and humidity readings.
7. Optionally, open the Serial Monitor and set the baud rate to `9600` to view the readings there.

## Project Photos

Photos of the completed Arduino circuit will be added here.

## Future Improvements

Possible future improvements include:

- Recording sensor readings over time
- Adding additional environmental sensors
