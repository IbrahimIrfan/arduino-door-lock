// include the Servo library
#include <Servo.h>

Servo myServo;  // create a servo object

int lightPin = A0;  //define a pin for Photo resistor
int servoPin = 9;
int lightReading;

void setup() {
  myServo.attach(servoPin); // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // open a serial connection to your computer
}

void loop() {
  myServo.write(0);
  lightReading = digitalRead(lightPin);
  if (lightReading) {
    delay(1000);
    lightReading = digitalRead(lightPin);
    if (lightReading == 0){
      delay(500);
      lightReading = digitalRead(lightPin);
      if (lightReading){
        myServo.write(180);
      }
    }
  }
}
