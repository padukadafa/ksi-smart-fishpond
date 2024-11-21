#pragma once
#include <OneWire.h>
#include <DallasTemperature.h>

class Sensor
{
public:
    void init();
    void readPH();
    void readTurbidity();
    int readSuhu();
};
