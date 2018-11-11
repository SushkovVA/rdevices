#-------------------------------------------------
#
# Project created by QtCreator 2017-08-04T23:56:45
#
#-------------------------------------------------

QT       -= gui

unix {
    target.path = /usr/lib
    INSTALLS += target
}

TARGET = RDevice
TEMPLATE = lib
CONFIG += staticlib

SOURCES += rdevice.cpp

HEADERS += ../include/rdevice.h

INCLUDEPATH += ../include/
LIBS += -L../libs/
#LIBS += -lRParameter
DESTDIR = ../libs/
