#ifndef RMOVESENSOR_H
#define RMOVESENSOR_H

#include "rdevice.h"

class RMoveSensor : public RDevice
{

public:
    RMoveSensor(QString name, int gpioOut, QObject *parent = 0);
    ~RMoveSensor();

public slots:
    void updateData(QString nameParameter = "");

private:
    int gpioOutPin;
    void updateMoving();
};

#endif // RMOVESENSOR_H
