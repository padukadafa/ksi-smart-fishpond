#include <SPI.h>
#include <sensor.h>
#include <Adafruit_ADS1X15.h>
#include "config.h"
OneWire oneWire(2);
DallasTemperature sensorSuhu(&oneWire);
Adafruit_ADS1115 ads;
float vClear = 0.965; // Tegangan referensi untuk air jernih

void Sensor::init()
{
    pinMode(ECHOPIN, INPUT);
    pinMode(TRIGPIN, OUTPUT);

    if (!ads.begin())
    {
        Serial.println("Tidak dapat mendeteksi ADS1115. Periksa koneksi!");
        while (1)
            ;
    }

    sensorSuhu.begin();
}
float Sensor::readTurbidity()
{
    int16_t rawValue = ads.readADC_SingleEnded(0);
    float voltage = rawValue * 0.1875 / 1000;
    return calculateTurbidity(voltage);
}
int16_t Sensor::readTemp()
{
    // sensorSuhu.requestTemperatures();

    // return sensorSuhu.getTempCByIndex(0);
    return 18;
}
float Sensor::readPH()
{
    int16_t rawValue = ads.readADC_SingleEnded(0);
    float voltage = rawValue * 0.1875 / 1000;

    return calculatePh(voltage);
}
int16_t Sensor::readFeedCapacity()
{
    digitalWrite(TRIGPIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGPIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGPIN, LOW);

    return (pulseIn(ECHOPIN, HIGH) * 0.034 / 2) / 35 * 100;
}

float Sensor::calculateTurbidity(float voltage)
{
    return (voltage - 1.03) / (3.02) * 100;
}
float Sensor::calculatePh(float voltage)
{
    return voltage;
}
void Sensor::startPH()
{
    digitalWrite(PH_PIN, HIGH);
    delay(1000);
}
void Sensor::stopPH()
{
    digitalWrite(PH_PIN, LOW);
}