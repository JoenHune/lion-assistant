#include "lion_assistant.h"
#include "ui_lion_assistant.h"
//#include <QSerialPort>
//QSerialPort serial;

lion_assistant::lion_assistant(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lion_assistant)
{
    ui->setupUi(this);
//    serial.setPort("com4");
//    serial.setBaudRate(QSerialPort::Baud9600);
//    serial.setDataBits(QSerialPort::Data8);
//    serial.setParity(QSerialPort::NoParity);
//    serial.setStopBits(QSerialPort::OneStop);
//    serial.FlowControl(QSerialPort::NoFlowControl);
//    serial.open(QIODevice::ReadWrite);
//    serial.write("ok*");
}

lion_assistant::~lion_assistant()
{
    delete ui;
//    serial.close();
}
