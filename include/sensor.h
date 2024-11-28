#pragma once
#include <OneWire.h>
#include <DallasTemperature.h>
#define V_REF 3.3     // Tegangan referensi
#define ADC_MAX 21366 // Resolusi maksimum ADC ADS1115 (16-bit)

class Sensor
{
public:
    void init();
    float readPH();
    void startPH();
    void stopPH();
    float readTurbidity();
    int16_t readTemp();
    int16_t readFeedCapacity();

private:
    float calculateTurbidity(float voltage);
    float calculatePh(float voltage);
};
