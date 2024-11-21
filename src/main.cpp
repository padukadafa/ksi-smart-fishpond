#include <Arduino.h>
#include "sensor.hpp"
Sensor sensor;
void setup()
{
  Serial.begin(9600);
  sensor.init();
}

void loop()
{
  Serial.println(sensor.readSuhu());
  delay(1000);
}