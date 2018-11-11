#-------------------------------------------------
#
# Project created by QtCreator 2017-09-10T19:46:36
#
#-------------------------------------------------

QT       -= gui

TARGET = RMoveSensor
TEMPLATE = lib
CONFIG += staticlib

SOURCES += rmovesensor.cpp

HEADERS += ../include/rmovesensor.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH += ../include/
LIBS += -L../libs/
LIBS += -lRDevice -lRParameter
DESTDIR = ../libs/
