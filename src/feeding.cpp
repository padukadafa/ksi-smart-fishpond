#include "feeding.h"
#include <Servo.h>
#include <Arduino.h>
Servo servo;
void Feeding::init()
{
    servo.attach(9);
}

void Feeding::feed()
{
    for (int i = 10; i < 170; i += 20)
    {
        servo.write(i);
        delay(1000);
    }
}
