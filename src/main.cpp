#include <Arduino.h>
#include <Servo.h>

Servo myservo;
int pos = 0;
// put function declarations here:

void setup()
{
  myservo.attach(14);
  // put your setup code here, to run once:
}

void loop()
{
  myservo.write(-180);
  delay(1000);
  myservo.write(180);
  delay(1000);
}