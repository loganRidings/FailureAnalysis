//resistor vals (Ohms)
int resistors[5] = {};
// Analog pins to read voltage over resistors
int analogPin[] = {A0,A1,A2,A3,A4};

// name this arduino for the RasPi to ask for below
String unitName = "current";
String endCommand = "stop";

void setup() {
   // Set baud rate to match RasPi @ 9600
  Serial.begin(9600);
}

/*
  Main body of code, loops until serial command sends "stop"
*/
void loop() {
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
        // Send each voltage reading value independently (as floats), to 4 decimals
        for (int i = 0; i < 30; i ++) {
          Serial.print(voltageArray[i], 4);
        }
        // Print newline after all data is read over serial send
        Serial.println();
      }
  }
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
