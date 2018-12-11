#-------------------------------------------------
#
# Project created by QtCreator 2017-08-03T04:26:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app

INCLUDEPATH += ../include

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

LIBS += -L../libs/ -L/usr/lib/
LIBS += -lRRele220_4 -lRDevice -lRParameter -lbcm2835
