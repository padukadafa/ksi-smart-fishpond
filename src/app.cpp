#include "app.h"
#include <Arduino.h>
#include <BlynkSimpleStream.h>
#include "sensor.h"
#define BLYNK_PRINT SwSerial
#include <SoftwareSerial.h>
#include "feeding.h"
#include "display.h"
#include "config.h"
SoftwareSerial SwSerial(10, 11); // RX, TX
Sensor sensor;
BlynkTimer timer;
byte addr[8];
Feeding feeding;
Display display;
void blynk_event();
BLYNK_WRITE(V4)
{
    int pinValue = param.asInt();

    if (pinValue == 1)
    {
        display.setDisplay(FEEDING);
        display.clearDisplay();
        display.show(12);
        SwSerial.println("Feeding!");
        feeding.feed();
        display.setDisplay(MAIN);
        display.clearDisplay();
    }
    else if (pinValue == 0)
    {
    }
}

void App::init()
{
    display.init();
    display.showLoading();
    SwSerial.begin(115200);
    Serial.begin(9600);
    sensor.init();
    feeding.init();
    pinMode(PH_PIN, OUTPUT);
    pinMode(PH_BUTTON_PIN, INPUT_PULLUP);
    Blynk.begin(Serial, BLYNK_AUTH_TOKEN);
    timer.setInterval(1000, blynk_event);
    display.clearDisplay();
}
void App::app_loop()
{
    if (display.currentDisplay == MAIN)
    {
        display.show(12, 23);
    }
    else if (display.currentDisplay == READ_PH)
    {
        display.show(sensor.readPH());
    }
    else if (display.currentDisplay == FEEDING)
    {
        display.show(10);
    }
    Blynk.run();
    timer.run();
    if (digitalRead(PH_BUTTON_PIN) == 0 && display.currentDisplay == MAIN)
    {
        display.clearDisplay();
        display.setDisplay(READ_PH);
        display.showLoading();
        sensor.startPH();
        delay(300);
        display.clearDisplay();
    }
    else if (digitalRead(PH_BUTTON_PIN) == 0 && display.currentDisplay == READ_PH)
    {
        display.setDisplay(MAIN);
        sensor.stopPH();
        delay(300);

        display.clearDisplay();
    }
}

void blynk_event()
{
    Blynk.virtualWrite(V1, sensor.readTurbidity());
    Blynk.virtualWrite(V0, sensor.readTemp());
    if (display.currentDisplay == READ_PH)
    {
        Blynk.virtualWrite(V2, sensor.readPH());
    }
    Blynk.virtualWrite(V3, sensor.readFeedCapacity());
    SwSerial.println("Data Sended!");
    SwSerial.print("Turbidity: ");
    SwSerial.println(sensor.readTurbidity());
    SwSerial.print("Suhu : ");
    SwSerial.println(sensor.readTemp());
    SwSerial.print("pH : ");
    SwSerial.println(sensor.readPH());
    SwSerial.print("Feed : ");
    SwSerial.println(sensor.readFeedCapacity());
}