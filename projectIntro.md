# Introduction: 
	Light emitting diodes (LEDs) have found widespread use due to their low power consumption, low cost, and long lifetime. 
  They offer narrow band emission in a variety of colors and are consistently being improved. Because LEDs are ubiquitous in 
  virtually every industry, the importance of reliability cannot be understated. LEDs failure is often characterized by a gradual 
  decrease in luminous intensity over the lifetime of the bulb, although instantaneous failure occasionally occurs as well. LED 
  failure can be categorized into three types: packaging-related, semiconductor/metal-related, and stress-related. This study 
  focuses on stress-related failure.

  This study explores the operating limits of light emitting diodes (LEDs) through systematic variation of experimental factor 
  levels. Designing an automated failure analysis system using Arduino and Raspberry Pi microprocessors. Each experimental run 
  will power 9 LEDs at 25%, 50%, and 75% of the max duty cycle. To allow the LEDs to fail in a reasonable amount of time, they 
  will be operating above the manufacturers recommended levels. To estimate the current level to be used, an LED was driven to 
  failure by a direct current. The LEDs were more robust than anticipated, requiring ≈160 mA before a visible dimming occurred.
  Increasing the current over the next couple minutes, the diode failed completely at 190 mA. Each experimental run used 180 mA
  of current to drive the LEDs, which required an external power source.
  
  This experiment used VCC 4300H5LC cadmium sulfide LEDs with a peak wavelength of 565 nm. The digital pins on the Arduinos were 
  used to apply a gate voltage of +5V to an NTE2397 n-MOSFET from NTE Electronics. The FET acted as a switch to supply 20 V to the 
  LED circuit. The experiment used two Arduino Nanos to power and pulse the LEDs, one Nano was used to measure the data from the 
  LEDs, and one Nano was dedicated to the operating the CdS photodetectors (PDV-P8001, Advanced Photonics, Inc). A Raspberry Pi was
  used to send commands and query data from each Arduino microcontroller via the serial pinouts on the devices. The photodetectors 
  used 1kΩ pull-down resistors, a lower resistance value was used so that the detectors would be more sensitive to large drops in 
  luminous intensity. 
 
Figure 1. Example circuit from experimental setup. Each digital output pulsed the LEDs at a different frequency (max 490 Hz). 
The current was measured by the analogue input of the measurement Arduino. Resistors were used to control the amount of current 
through each of the LEDs. 
![image](https://user-images.githubusercontent.com/80741351/145651165-70e0a6cb-c7ef-4214-a8cf-5d8ad8984a2d.png)
