# measurement-of-adulteration-contents-in-liquids
Measurement of Adulteration Contents in Liquids is an Arduino Uno-based project that detects liquid purity using an analog liquid quality sensor. The system calculates the purity percentage, displays results on a 16×2 I2C LCD, and uses green/red LEDs for instant quality indication, enabling low-cost real-time adulteration detectio
## Features

- Real-time liquid quality monitoring
- Purity percentage calculation
- LCD display for results
- Red LED for adulterated liquid
- Serial Monitor output for debugging

## Components Used

- Arduino Uno
- Liquid Quality Sensor
- 16×2 I2C LCD
- Green LED
- Red LED
- 220Ω Resistors
- Jumper Wires

## Circuit Connections

### Liquid Quality Sensor

| Sensor | Arduino |
|--------|---------|
| VCC | 5V |
| GND | GND |
| AO | A0 |

### I2C LCD

| LCD | Arduino |
|-----|---------|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

### LEDs

| LED | Arduino Pin |
|-----|-------------|
| Green LED | D7 |
| Red LED | D6 |

## Working

1. The liquid quality sensor reads the liquid properties.
2. Arduino reads the analog value from the sensor.
3. The sensor value is converted into a purity percentage.
4. The purity percentage is displayed on the LCD.
5. The LEDs indicate the quality:
   - **Green:** Pure
   - **Red:** Adulterated

## Calibration

The project uses the following calibration values:

```cpp
int pureValue = 900;
int impureValue = 300;
```

These values can be adjusted based on the sensor readings for different liquids.

## Project Structure

```
Measurement-of-Adulteration-Contents-in-Liquids/
│── sketch.ino
│── diagram.json
│── README.md
```

## Future Improvements

- IoT monitoring using ESP32
- Mobile application support
- Cloud data logging
- Improved sensor calibration
- Support for multiple liquid types

Sanjivani Raut
Electronics & Telecommunication Engineering Student
