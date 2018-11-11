#include "rrele220_4.h"

#include "bcm2835.h"


#include "iostream"

RRele220_4::RRele220_4(QString name, int gpio1, int gpio2,  int gpio3, int gpio4, QObject *parent) :
    RDevice(name, parent),
    gpioDevice1(gpio1),
    gpioDevice2(gpio2),
    gpioDevice3(gpio3),
    gpioDevice4(gpio4)
{
    //QStringList stateList;

    addParameter("DeviceState1", "off");
    addParameter("DeviceState2", "off");
    addParameter("DeviceState3", "off");
    addParameter("DeviceState4", "off");

    bcm2835_init();
    bcm2835_gpio_fsel(gpioDevice1, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(gpioDevice2, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(gpioDevice3, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(gpioDevice4, BCM2835_GPIO_FSEL_OUTP);

    setValue("DeviceState1", "off");
    setValue("DeviceState2", "off");
    setValue("DeviceState3", "off");
    setValue("DeviceState4", "off");
}

RRele220_4::~RRele220_4()
{
    bcm2835_close();
}

void RRele220_4::updateData(QString nameParameter)
{
    QString state = "";
    if (nameParameter == "")
    {
        state = ( bcm2835_gpio_lev(gpioDevice1) == LOW ? "on" : "off" );
        getParameter("DeviceState1")->setValue(state);

        state = ( bcm2835_gpio_lev(gpioDevice2) == LOW ? "on" : "off" );
        getParameter("DeviceState2")->setValue(state);

        state = ( bcm2835_gpio_lev(gpioDevice3) == LOW ? "on" : "off" );
        getParameter("DeviceState3")->setValue(state);

        state = ( bcm2835_gpio_lev(gpioDevice4) == LOW ? "on" : "off" );
        getParameter("DeviceState4")->setValue(state);

    }
    else
    {

        if ( ! isParameterExist(nameParameter) )
            return;

        RParameter* releDevice = getParameter(nameParameter);

        if (nameParameter == "DeviceState1")
            state = ( bcm2835_gpio_lev(gpioDevice1) == LOW ? "on" : "off" );
        else if (nameParameter == "DeviceState2")
            state = ( bcm2835_gpio_lev(gpioDevice2) == LOW ? "on" : "off" );
        else if (nameParameter == "DeviceState3")
            state = ( bcm2835_gpio_lev(gpioDevice3) == LOW ? "on" : "off" );
        else if (nameParameter == "DeviceState4")
            state = ( bcm2835_gpio_lev(gpioDevice4) == LOW ? "on" : "off" );

        releDevice->setValue(state);

    }
}

bool RRele220_4::setValue(QString nameParameter, QString value)
{
    if ( ! isParameterExist(nameParameter) )
        return false;

    RParameter* releDevice = getParameter(nameParameter);

    if ( ! releDevice->isValueValid(value) )
        return false;

    int state( value == "on" ? LOW : HIGH);

    if (nameParameter == "DeviceState1")
    {
        bcm2835_gpio_write(gpioDevice1, state);
    }
    else if (nameParameter == "DeviceState2")
    {
        bcm2835_gpio_write(gpioDevice2, state);
    }
    else if (nameParameter == "DeviceState3")
    {
        bcm2835_gpio_write(gpioDevice3, state);
    }
    else if (nameParameter == "DeviceState4")
    {
        bcm2835_gpio_write(gpioDevice4, state);
    }

    releDevice->setValue(value);

    return true;
}
