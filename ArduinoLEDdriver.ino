// Initialize vars
//Digital Switching pins
int ledPin[] = {9,10,11};
//resistor vals (Ohms)
int resistors[] = {100,1000,10000};
// Analog pins to read voltage over resistors
int analogPin[] = {A0,A1,A2,A3,A4};
// input levels for duty cycle as a percentage
int dutyCycle[] = {25,50,75};
// name this arduino for the RasPi to ask for below
String unitName = "driver";
String endCommand = "stop";

void setup() {
  // Set baud rate to match RasPi @ 9600
  Serial.begin(9600);
  // initialize pinModes
  for (int index = 0; index<3; index++) {
    pinMode(ledPin[index], OUTPUT);
  }
}

// Set pins to appropriate duty cycles, wait for prompt from rasPi to give report
void loop() {
  // Turn on LEDs
  for (int index = 0; index < 3; index++){
    ledOn(ledPin[index],dutyCycle[index]);
  }
  // wait for HIGH signal from RasPi
  while (!Serial.available()){}
  
  String command = Serial.readStringUntil('\n');
  // Above line gets which arduino raspi is asking for

  // Read analog pin for resistor value and send pin no. with voltage drop over resistor
  if (command == unitName) {
    float voltage = 0;
    float voltageArray[30] = {};
      // Read pins 1-5
      for (int i = 0; i < 5; i++) {
        // take 30 measurements on analog pin and add to voltageArray
        for (int j = 0; j < 30; j++) {
          voltage = voltageFunc(i);
          voltageArray[j] = voltage;
        }
        // Send the pin number over serial to RasPi
        Serial.println(i);
        // Send each voltage reading value independently (as floats)
        for (int i = 0; i < 30; i ++) {
          Serial.print(voltageArray[i], 4);
        }
        Serial.println();
      }
  }
  if (command == endCommand) {
    ledOff();
  }
}

/*
 Turn on pin at specced duty cycle
 Input pin number and PERCENTAGE to run at
 Return void
*/
void ledOn(int pinNum, int dutyCycle) {
  int runVal = dutyCycle * 255 / 100;
  analogWrite(pinNum,dutyCycle);
}


/*
  When called, takes pinNum for analog pin address 
  Returns voltage drop across resistor
*/
float voltageFunc(int pinNum) {
  int val = 0;
  float voltageRead = 0;
  val = analogRead(pinNum);
        voltageRead = val * (5.0/1023.0);
        return voltageRead;
}


/*
 LEDs off, wait infinitely
 Return void
 */
void ledOff() {
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  while (true) {;}
}
