
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

//int potpin = 0;  // analog pin used to connect the potentiometer
//int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(11);  // attaches the servo on pin 9 to the servo object
  myservo.write(0);
  myservo.write(45);
  myservo.write(90);
  myservo.write(1353);
  myservo.write(170);
  //myservo.writeMicroseconds(500000000);
}

void loop() {

}
                                                 
