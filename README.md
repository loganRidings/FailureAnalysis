# FailureAnalysis
All Arduino and RaspberryPi and php and SQL code here, pls

Please comment code thoroughly and keep things organized as much as possible

The analog pins can read up to 5V at 10000 Hz resolution
The resistor values should be low enough to keep V_R below 5V
For 180 mA, and 2.3V drop over LED, maximum resistor value should be ~15 Ohms

Use the serial baud at 9600 for Arduino and RasPi
Serial prompts (Strings) from RasPi to Arduino:
  LED driver: "driver"
  Current unit: "current"
  Photodiode 1: "photoOne"
  Photodiode 2: "photoTwo"
  Stop all Arduinos (send to infinite loop): "stop"
  
