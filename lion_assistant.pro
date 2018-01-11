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
    qcustomplot.cpp \
    is_clear_marked_pid.cpp

HEADERS  += lion_assistant.h \
    qcustomplot.h \
    is_clear_marked_pid.h

FORMS    += lion_assistant.ui \
    is_clear_marked_pid.ui

CONFIG += c++11

RESOURCES += \
    lion_assistant.qrc

RC_ICONS = resources\lion_assistant.ico
