int led_pin = {1,2,3,4,5,6,7,8,9,10};
// input levels for duty cycle as a percentage
int duty_cycle = {25,50,75};
void setup() {
  // put your setup code here, to run once:
for (int index = 0; index<10; index++) {
  pinMode(led_pin[index], OUTPUT);
}
}
// Set pins to appropriate duty cycles, wait for prompt from rasPi to give report
void loop() {
  // put your main code here, to run repeatedly:
  for (int index = 0; index < 10; index++){
    int dutyIndex = index%3;
    analogWrite(led_pin[index],duty_cycle[dutyIndex]);
  }
}

/*
 Turn on pin at specced duty cycle
 Input pin number and percentage to run at
*/
void ledOn(pinNum, dutyCycle) {
  int runVal = dutyCycle * 255 / 100;
  analogWrite(pinNum,dutyCycle);
}