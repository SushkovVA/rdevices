#include "rmovesensor.h"
#include "bcm2835.h"

RMoveSensor::RMoveSensor(QString name, int gpioOut, QObject *parent) :
    RDevice(name, parent),
    gpioOutPin(gpioOut)
{
    QStringList stateList;
    stateList << "true" << "false";
    addParameter("Moving", DEFAULT_VALUE, stateList);

    bcm2835_init();
    bcm2835_gpio_fsel(gpioOutPin, BCM2835_GPIO_FSEL_INPT);
}

RMoveSensor::~RMoveSensor()
{
    bcm2835_close();
}

void RMoveSensor::updateData(QString nameParameter)
{
    if (nameParameter == "")
    {
        updateMoving();
    }
    else
    {
        if ( ! isParameterExist(nameParameter) )
            return;
        if (nameParameter == "Moving")
            updateMoving();
    }
}

void RMoveSensor::updateMoving()
{
    RParameter* isMoving = getParameter("Moving");
    int state = bcm2835_gpio_lev(gpioOutPin);

    if (state == HIGH)
        isMoving->setValue("true");
    else
        isMoving->setValue("false");
}
