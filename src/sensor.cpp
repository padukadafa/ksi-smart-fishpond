#include <sensor.hpp>
OneWire oneWire(12);
DallasTemperature sensorSuhu(&oneWire);

void Sensor::init()
{
    sensorSuhu.begin();
}
void Sensor::readTurbidity()
{
}
int Sensor::readSuhu()
{
    sensorSuhu.requestTemperatures();

    return sensorSuhu.getTempCByIndex(0);
}
void Sensor::readPH() {}