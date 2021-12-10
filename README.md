# FailureAnalysis Project Description
Group Project for PHYS 679: Semiconductor Device Processing with Instructor Dr. Fuding Lin.

## Project Goal:
The goal of this project is to build an automated LED stress testing experiement apparatus by interfacing Arduino Nano's and a Raspberry Pi.

## Useful Links:

A full introduction and description of the projet can be found <here>
  kjsbfjsd.ytasyv

A full parts list can be found here: [Parts List](https://github.com/loganRidings/FailureAnalysis/blob/main/partsList.md#parts-list)
  
The Arduino code to do xyz is here:
  
The python script to run on the Pi is here:

Some of the useful references we consulted while working on this project:



All Arduino and RaspberryPi and php and SQL code here, pls

Please comment code thoroughly and keep things organized as much as possible

The analog pins can read up to 5V at 10000 Hz resolution
The resistor values should be low enough to keep V_R below 5V
For 180 mA, and 2.3V drop over LED, maximum resistor value should be ~15 Ohms - JK

Use the serial baud at 9600 for Arduino and RasPi
Serial prompts (Strings) from RasPi to Arduino:
  LED driver: "driver"
  Current unit: "current"
  Photoresistor 1: "photoOne"
  Photoresistor 2: "photoTwo"
  Stop all Arduinos (send to infinite loop): "stop"
  
