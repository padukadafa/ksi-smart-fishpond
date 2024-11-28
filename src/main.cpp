#include <Arduino.h>
#include <SoftwareSerial.h>
#include <app.h>
App app;
void setup()
{
  app.init();
}

void loop()
{
  app.app_loop();
}
