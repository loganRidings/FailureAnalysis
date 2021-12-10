# FailureAnalysis Project Description
Group Project for PHYS 679: Semiconductor Device Processing with Instructor Dr. Fuding Lin.

## Project Goal:
The goal of this project is to build an automated LED stress testing experiement apparatus by interfacing Arduino Nano's and a Raspberry Pi.

## Useful Links:

A full introduction and description of the projet can be found here: [Intro](https://github.com/loganRidings/FailureAnalysis/blob/main/projectIntro.md) , [What We Did](https://github.com/loganRidings/FailureAnalysis/blob/main/Recap.md) 

A full parts list can be found here: [Parts List](https://github.com/loganRidings/FailureAnalysis/blob/main/partsList.md#parts-list)
  
The Arduino Circuit Diagram: [Diagram](https://github.com/loganRidings/FailureAnalysis/blob/main/FailureAnalysisPhotodiodes.png)
  
The Arduino code is here:
  - [driver](https://github.com/loganRidings/FailureAnalysis/blob/main/ArduinoLEDdriver.ino) Arduino 0 controls power and current for the LEDs.
  - [current](https://github.com/loganRidings/FailureAnalysis/blob/main/currentUnit.ino) Arduino 1 measures the current across the resitor and sends it to the pi via serial pins.
  - [photoDiodeOne](https://github.com/loganRidings/FailureAnalysis/blob/main/photoOne.ino) Arduino 2 measures the current out of 5 of the photodiodes.
  - [photoDiodeTwo](https://github.com/loganRidings/FailureAnalysis/blob/main/photoTwo.ino) Arduino 3 measures the current out of 1 of the photodiodes.
  
  
The python script to run on the Pi is here: [SerialPython](https://github.com/loganRidings/FailureAnalysis/blob/main/failingDraft.py)

Some of the useful references we consulted while working on this project:

  
