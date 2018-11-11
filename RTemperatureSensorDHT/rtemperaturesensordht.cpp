#include "iostream"

#include "rtemperaturesensordht.h"
#include "pi_2_dht_read.h"

const int DHT_TYPE = 22;

RTemperatureSensorDHT::RTemperatureSensorDHT(QString name, int gpioOut, QObject *parent) :
    RDevice(name, parent),
    gpioOutPin(gpioOut)
{
    addParameter("Temperature", DEFAULT_VALUE, ValueType_double, "-100.", "100.");
    addParameter("Humidity", DEFAULT_VALUE, ValueType_int, "0", "100");
}

void RTemperatureSensorDHT::updateTemperature()
{
    float hum, temp;
    pi_2_dht_read(DHT_TYPE, gpioOutPin, &hum, &temp);
    RParameter* temperature = getParameter("Temperature");
    if ( temperature != NULL )
        temperature->setValue(QString::number(temp));
}

void RTemperatureSensorDHT::updateHumidity()
{
    float hum, temp;
    pi_2_dht_read(DHT_TYPE, gpioOutPin, &hum, &temp);
    RParameter* humidity = getParameter("Humidity");
    if ( humidity != NULL )
        humidity->setValue(QString::number(hum));
}

void RTemperatureSensorDHT::updateData(QString nameParameter)
{
    if (nameParameter == "")
    {
        updateTemperature();
        updateHumidity();
    }
    else
    {

        if ( ! isParameterExist(nameParameter) )
            return;

        if (nameParameter == "Temperature")
            updateTemperature();
        else if (nameParameter == "Humidity")
            updateHumidity();

    }

}
