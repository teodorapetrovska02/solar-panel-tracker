#include <Servo.h>

#define LDR1 A0
#define LDR2 A1

//Error value. Can be changed if needed
#define error 10

//Starting point of the servo motor
int StartPoint =  90;

//Object for the servo motor
Servo servo;

void setup() {
//Include servo motor PWM pin
  servo.attach(11);
//Set the starting point of the servo
  servo.write(StartPoint);
  delay(1000);
}

void loop() {
//Get the LDR sensor values
  int ldr1 = analogRead(LDR1);
  int ldr2 = analogRead(LDR2);

//Get the difference of these values
  int value1 = abs(ldr1 - ldr2);
  int value2 = abs(ldr2 - ldr1);

// Logic for servo motor (solar panel movement)
  if ((value1 <= error) || (value2 <= error)) {

  } else {
    if (ldr1 > ldr2) {
      StartPoint = --StartPoint;
    }
    if (ldr1 < ldr2) {
      StartPoint = ++StartPoint;
    }
  }

//Write values on the servo motor
  servo.write(StartPoint);
  delay(80);
}