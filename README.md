# Battle-Bot-code

![alt text](https://github.com/Nakib00/Battle-Bot-code/blob/main/Battle%20bot%20img.jpg?raw=true)

# Arduino Motor Control

This repository contains an Arduino sketch for controlling motors using an Electronic Speed Controller (ESC). The sketch is written in C++ and utilizes the Servo library for interfacing with the ESC.

## Hardware Requirements

To run this code, you will need the following components:

- Arduino board
- Electronic Speed Controller (ESC)
- Motors
- Power supply for the motors

## Circuit Diagram

Please refer to the circuit diagram below for the connections:


![alt text](https://github.com/Nakib00/Battle-Bot-code/blob/main/Circuit%20of%20Battle%20bot.png?raw=true)


Make sure to connect the ESC signal pin to the specified digital pin on the Arduino board and provide power to the motors using an appropriate power supply.

## Installation and Setup

1. Clone this repository to your local machine or download the code as a ZIP file.
2. Connect the hardware components as per the circuit diagram.
3. Open the Arduino IDE.
4. Connect your Arduino board to the computer.
5. Open the `motor_control.ino` file in the Arduino IDE.
6. Verify and upload the sketch to the Arduino board.

## Usage

1. Once the code is uploaded to the Arduino board, open the Serial Monitor in the Arduino IDE.
2. Send commands via the Serial Monitor to control the motors. The available commands are:
   - 'W': Stop
   - 'R': Move left
   - 'L': Move right
   - 'B': Move forward
   - 'F': Move backward
   - '1' to '9': Adjust speed from minimum to maximum

## Troubleshooting

If you encounter any issues while running the code or controlling the motors, consider the following:

- Double-check the circuit connections and ensure they match the circuit diagram.
- Verify that the ESC is compatible with the motors and power supply.
- Ensure that the correct digital pins are defined in the code for ESC signal control.

## Softwere 

- [Bluetooth RC car](https://play.google.com/store/apps/details?id=braulio.calle.bluetoothRCcontroller)

## License

This code is licensed under ZAN Tech.

Feel free to modify and adapt it according to your needs.

For any questions or further assistance, please reach out to [your contact information].
