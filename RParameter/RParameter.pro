#-------------------------------------------------
#
# Project created by QtCreator 2017-08-04T23:57:28
#
#-------------------------------------------------

QT       -= gui

unix {
    target.path = /usr/lib
    INSTALLS += target
}

TARGET = RParameter
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += ../include

SOURCES += rparameter.cpp

HEADERS += ../include/rparameter.h

DESTDIR = ../libs/
