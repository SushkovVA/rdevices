#-------------------------------------------------
#
# Project created by QtCreator 2017-08-12T02:42:57
#
#-------------------------------------------------

QT       -= gui

TARGET = RTemperatureSensorDHT
TEMPLATE = lib
CONFIG += staticlib

SOURCES += rtemperaturesensordht.cpp

HEADERS += ../include/rtemperaturesensordht.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH += ../include/
LIBS += -L../libs/
LIBS += -lRReadDHT -lRDevice -lRParameter
DESTDIR = ../libs/
