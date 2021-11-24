
int sensorPin[] = {A0,A1,A2,A3,A4};
int sensorValue = 0;

void setup() {
  // Set up serial ports and initialize analog pins
  Serial.begin(9600);
  for (int i = 0; i < 5; i++) {
    pinMode(sensorPin[i], INPUT);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
