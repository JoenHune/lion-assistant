#-------------------------------------------------
#
# Project created by QtCreator 2016-12-22T18:18:24
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = lion_assistant
TEMPLATE = app

SOURCES += main.cpp\
        lion_assistant.cpp \
    qcustomplot.cpp

HEADERS  += lion_assistant.h \
    qcustomplot.h

FORMS    += lion_assistant.ui

CONFIG += c++11

RESOURCES += \
    lion_assistant.qrc

RC_ICONS = resources\lion_assistant.ico
