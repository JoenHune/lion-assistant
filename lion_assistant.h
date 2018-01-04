#ifndef lion_assistant_H
#define lion_assistant_H

#define DEBUG

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QDateTime>
#include <QFileDialog>
#include <QFile>
#include <QTimer>
#include <QScrollBar>
#include "qcustomplot.h"

#define MSG_HEAD "ffff"
#define MSG_LENGTH 20
#define MAX_DATA_AMOUNT 1000

namespace Ui {
class lion_assistant;
}

class lion_assistant : public QMainWindow
{
    Q_OBJECT

public:
    QList<QSerialPort::BaudRate> baudRate;
    QList<QSerialPort::DataBits> dataBits;
    QList<QSerialPort::Parity> parity;
    QList<QSerialPort::StopBits> stopBits;
    QVector<double> data1, data2, data3, data4;
    double offset1, offset2, offset3, offset4;

    explicit lion_assistant(QWidget *parent = 0);
    ~lion_assistant();
    void insertDataDisplay(const QByteArray& text,const QColor& color=Qt::black);

public slots:
    void switchSerial(void);
    void receive(void);
    void send(void);
    void transmit(void);
    void transmitString(void);
    void transmitHexadecimal(void);
    void transmitCircularly(void);
    void transmitFile(void);
    void openFile(void);
    void saveAs(void);
    void clear(void);
    void initialOscilloscope(void);
    void updateOscilloscope(void);
    void dataProcess(QByteArray);

private slots:
    void on_btn_TextUI_clicked();
    void on_btn_OscilUI_clicked();

    void on_btn_ch1_clicked();

    void on_btn_ch2_clicked();

    void on_btn_ch3_clicked();

    void on_btn_ch4_clicked();

    void on_btn_oscilClear_clicked();

    void on_dial_vertical_actionTriggered();

    void on_dial_horizontal_actionTriggered();

    void on_vSlider_offset_actionTriggered();

    void on_btn_referLine_clicked();

    void on_btn_zeroOffset_clicked();

    void on_btn_dataLine_clicked();

    void on_btn_SendPID_clicked();

    void on_btn_Mark_clicked();

    void on_list_PIDvalue_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::lion_assistant *ui;
    QSerialPort* port;
    QTimer* timer;
    QList<QSerialPortInfo> portList;
    QCustomPlot *oscilloscope;
    QCPGraph *channel1, *channel2, *channel3, *channel4;
    QCPGraph *refer1, *refer2, *refer3, *refer4;

    long dataQuantity;
    bool isPortOpen = false;
    int delayms;
    int looptimes;
    bool dataProcess_hasMsgHead;
    QByteArray dataProcess_MsgBuffer;

    void initSerialPortSetting(void);
    void connections(void);
    void updateBtnIconChColor(void);
    void updateBtnDataLineText(void);
    void updateBtnReferLineText(void);

    bool oscilloscope_isOpenCh1;
    bool oscilloscope_isOpenCh2;
    bool oscilloscope_isOpenCh3;
    bool oscilloscope_isOpenCh4;

    bool oscilloscope_isOpenRefer1;
    bool oscilloscope_isOpenRefer2;
    bool oscilloscope_isOpenRefer3;
    bool oscilloscope_isOpenRefer4;

    int oscilloscope_xMax;
    int oscilloscope_yMax;

    int oscilloscope_selectedCh;
};

#endif // lion_assistant_H
