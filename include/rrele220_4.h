#ifndef RRELE220_4_H
#define RRELE220_4_H

#include "rdevice.h"

class RRele220_4 : public RDevice
{

public:
    RRele220_4(QString name, int gpio1, int gpio2,  int gpio3, int gpio4, QObject *parent = 0);
    ~RRele220_4();

public slots:
    void updateData(QString nameParameter = "");
    bool setValue(QString nameParameter, QString value);

private:
    int gpioDevice1;
    int gpioDevice2;
    int gpioDevice3;
    int gpioDevice4;

};

#endif // RRELE220_4_H
