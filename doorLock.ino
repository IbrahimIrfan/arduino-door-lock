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
  lightReading = analogRead(lightPin);
  if (lightReading > 650) { // light on
    delay(1000);
    lightReading = analogRead(lightPin);
    if (lightReading <= 650){ // turn off light
      delay(500);
      lightReading = analogRead(lightPin);
      if (lightReading > 650){ // light on
        myServo.write(180);
      }
    }
  }
}
