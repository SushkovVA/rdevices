#-------------------------------------------------
#
# Project created by QtCreator 2017-08-14T23:03:06
#
#-------------------------------------------------

QT       -= gui

TARGET = RRele220_4
TEMPLATE = lib
CONFIG += staticlib

SOURCES += rrele220_4.cpp

HEADERS += ../include/rrele220_4.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH += ../include/
LIBS += -L../libs/
LIBS += -lRDevice -lRParameter
DESTDIR = ../libs/
