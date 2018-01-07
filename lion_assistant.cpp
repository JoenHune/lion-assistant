#include "lion_assistant.h"
#include "ui_lion_assistant.h"

lion_assistant::lion_assistant(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lion_assistant)
{
    setWindowIcon(QIcon(QStringLiteral(":/icon/resources/lion_assistant.ico")));

    ui->setupUi(this);
    port = new QSerialPort(this);
    timer = new QTimer(this);
    timerScanComs = new QTimer(this);


    ui->btn_Send->setEnabled(false);
    ui->sb_Delay->setRange(0, 10000);

    initSerialPortSetting();
    connections();

    dataProcess_hasMsgHead = false;
    oscilloscope = ui->qCustomPlot;
    channel1 = oscilloscope->addGraph();
    channel2 = oscilloscope->addGraph();
    channel3 = oscilloscope->addGraph();
    channel4 = oscilloscope->addGraph();
    refer1 = oscilloscope->addGraph();
    refer2 = oscilloscope->addGraph();
    refer3 = oscilloscope->addGraph();
    refer4 = oscilloscope->addGraph();
    initialOscilloscope();

    oscilloscope_isOpenCh1 = true;
    oscilloscope_isOpenCh2 = true;
    oscilloscope_isOpenCh3 = true;
    oscilloscope_isOpenCh4 = true;
    oscilloscope_isOpenRefer1 = false;
    oscilloscope_isOpenRefer2 = false;
    oscilloscope_isOpenRefer3 = false;
    oscilloscope_isOpenRefer4 = false;

    channel1->setVisible(oscilloscope_isOpenCh1);
    channel2->setVisible(oscilloscope_isOpenCh2);
    channel3->setVisible(oscilloscope_isOpenCh3);
    channel4->setVisible(oscilloscope_isOpenCh4);
    refer1->setVisible(oscilloscope_isOpenRefer1);
    refer2->setVisible(oscilloscope_isOpenRefer2);
    refer3->setVisible(oscilloscope_isOpenRefer3);
    refer4->setVisible(oscilloscope_isOpenRefer4);

    ui->dial_vertical->setRange(1, 999);
    ui->dial_horizontal->setRange(10, 90);
    ui->vSlider_offset->setRange(MIN_SLIDERVALUE, MAX_SLIDERVALUE);
    oscilloscope_lastSliderValue = MID_SLIDERVALUE;

    oscilloscope_xMax = MAX_DATA_AMOUNT;
    oscilloscope_yMax = 3277;

    offset1 = 0;
    offset2 = 0;
    offset3 = 0;
    offset4 = 0;

    updateBtnIconChColor();
    on_btn_ch1_clicked();

    serial_isOpen = false;

    oscilloscope_lastSelectedChannel = 1;

    updateOscilloscope();
}

lion_assistant::~lion_assistant()
{
    timer->stop();
    port->close();

    delete ui;
}


/* Initialize the serial port setting UI. */
void lion_assistant::initSerialPortSetting(void)
{
    /* Insert the available serial ports into QComboBox. Keep infolist and ui->cmb_PortName in same order.*/
    portList = QSerialPortInfo::availablePorts();

    // 1s扫描一次串口
    timerScanComs->start(1000);

    /* Insert choices of baud rate into QComboBox. Keep this->baudRate and baudRate in same order. */
    this->baudRate << QSerialPort::Baud115200 << QSerialPort::Baud57600 << QSerialPort::Baud38400
                   << QSerialPort::Baud19200 << QSerialPort::Baud9600 << QSerialPort::Baud4800
                   << QSerialPort::Baud2400 << QSerialPort::Baud1200;
    QStringList baudRate;
    baudRate << tr("115200") << tr("57600") << tr("38400")
             << tr("19200") << tr("9600") << tr("4800")
             << tr("2400") << tr("1200");
    ui->cmb_BaudRate->addItems(baudRate);

    /* Insert choices of data bits into QComboBox. Keep this->dataBits and dataBits in same order. */
    this->dataBits << QSerialPort::Data8 << QSerialPort::Data7
                   << QSerialPort::Data6 << QSerialPort::Data5;
    QStringList dataBits;
    dataBits << tr("8") << tr("7") << tr("6") << tr("5");
    ui->cmb_DataBits->addItems(dataBits);

    /* Insert choices of parity into QComboBox. Keep this->parity and parity in same order. */
    this->parity << QSerialPort::NoParity << QSerialPort::OddParity << QSerialPort::EvenParity
                 << QSerialPort::SpaceParity << QSerialPort::MarkParity;
    QStringList parity;
    parity << tr("无校验") << tr("奇校验") << tr("偶校验")
           << tr("空校验") << tr("标记校验");
    ui->cmb_Parity->addItems(parity);

    /* Insert choices of stop bits into QComboBox. Keep this->stopBits and stopBits in same order. */
    this->stopBits << QSerialPort::OneStop << QSerialPort::OneAndHalfStop << QSerialPort::TwoStop;
    QStringList stopBits;
    stopBits << tr("1") << tr("1.5") << tr("2");
    ui->cmb_StopBits->addItems(stopBits);

}


/* Connect all signals and slots. */
void lion_assistant::connections(void)
{
    /* Close */
//    connect(ui->actionExit,&QAction::triggered,this,&lion_assistant::close);

    /* Show about. */
//    connect(ui->actionAbout,&QAction::triggered,[this]{QMessageBox::information(this,tr("关于"),
//                                                       tr("Copyright (C) hubenchang0515@outlook.com\n"
//                                                          "http://www.kurukurumi.com\n"
//                                                          "https://github.com/hubenchang0515/lion_assistant\n"));});

    /* Show about Qt. */
//    connect(ui->actionQt,&QAction::triggered,[this]{QMessageBox::aboutQt(this);});

    /* Open or close serial port. */
    connect(ui->btn_OpenSerial,&QPushButton::clicked,this,&lion_assistant::switchSerial);

    /* Open and save file. */
//    connect(ui->actionOpenFile,&QAction::triggered,this,&lion_assistant::openFile);
//    connect(ui->actionSaveFile,&QAction::triggered,this,&lion_assistant::saveAs);

    /* Clear */
    connect(ui->btn_Clear,&QPushButton::clicked,this,&lion_assistant::clear);

    /* Receive */
    connect(port,&QSerialPort::readyRead,this,&lion_assistant::receive);

    /* Start send. */
    connect(ui->btn_Send,&QPushButton::clicked,this,&lion_assistant::send);

    /* Transmit file. */
//   connect(ui->btn_SendFile,&QPushButton::clicked,this,&lion_assistant::transmitFile);

    /* Transmit data. */
    connect(timer,&QTimer::timeout,this,&lion_assistant::transmit);

    /* Stop transmit loop */
    connect(timer,&QTimer::timeout,[&]{looptimes--;if(looptimes<=0 || !ui->cb_AutoSent->isChecked()) timer->stop();});

    // 定时扫描可用串口
    connect(timerScanComs, &QTimer::timeout, this, &lion_assistant::scanComs);
}

/* Insert text into ui->tb_rx_msg with color(default black). */
void lion_assistant::insertDataDisplay(const QByteArray& text, const QColor& color)
{
    QTextCharFormat fmt;
    fmt.setForeground(color);
    ui->tb_rx_msg->setCurrentCharFormat(fmt);

    if (ui->tb_rx_msg->toPlainText().length() >= 3000)
        ui->tb_rx_msg->clear();

    ui->tb_rx_msg->insertPlainText(text);

    QScrollBar* scroll = ui->tb_rx_msg->verticalScrollBar();
    scroll->setSliderPosition(scroll->maximum());
}


/* Open or close the serial port. */
void lion_assistant::switchSerial(void)
{
    if(serial_isOpen)
    {
        /* If serial port is open,close it. */
        port->close();
        ui->btn_OpenSerial->setText(tr("打开串口"));
        serial_isOpen = false;

        /* Enable all QComboBox.*/
        ui->cmb_PortName->setEnabled(true);
        ui->cmb_BaudRate->setEnabled(true);
        ui->cmb_DataBits->setEnabled(true);
        ui->cmb_Parity->setEnabled(true);
        ui->cmb_StopBits->setEnabled(true);

        // 重新打开串口扫描
        timerScanComs->start(1000);
    }
    else
    {
        /* If serial port is closed,open it. */

        /* List and QComboBox are in same order,so they can use the same index. */
        port->setPort(portList[ui->cmb_PortName->currentIndex()]);
        port->setBaudRate(baudRate[ui->cmb_BaudRate->currentIndex()]);
        port->setDataBits(dataBits[ui->cmb_DataBits->currentIndex()]);
        port->setParity(parity[ui->cmb_Parity->currentIndex()]);
        port->setStopBits(stopBits[ui->cmb_StopBits->currentIndex()]);
        if(port->open(QSerialPort::ReadWrite))
        {
            ui->btn_OpenSerial->setText(tr("关闭串口"));
            serial_isOpen = true;
            /* Disable all QComboBox.*/
            ui->cmb_PortName->setEnabled(false);
            ui->cmb_BaudRate->setEnabled(false);
            ui->cmb_DataBits->setEnabled(false);
            ui->cmb_Parity->setEnabled(false);
            ui->cmb_StopBits->setEnabled(false);

            // 关闭串口扫描
            timerScanComs->stop();
        }
        else
        {
            QString message = "Connect to " + ui->cmb_PortName->currentText() + " failed : " + port->errorString();
            statusBar()->showMessage(message,5000);
        }
    }

    /* Enable or disable ui->btn_Send QPushButton. */
    ui->btn_Send->setEnabled(serial_isOpen);
    // ui->btn_SendFile->setEnabled(isPortOpen);
}

/* Receive data from serial port. */
void lion_assistant::receive(void)
{
    /* Receive data. */
    QByteArray data_src = port->readAll();
    QByteArray data_disp = data_src;

    /* Convert data to hexadecimal. */
    if(ui->rdb_HexDisp->isChecked())
    {
        data_disp = data_disp.toHex();
    }

    /* Add time to show. */
    if(ui->cb_ShowTime->isChecked())
    {
        QDateTime time = QDateTime::currentDateTime();
        data_disp = data_disp.prepend(time.toString("[yyyy-MM-dd hh:mm:ss] ").toLatin1());
    }
    /* Add newline to show. */
    if(ui->cb_AutoNewLine->isChecked())
    {
        data_disp.append("\n");
    }

    /* Show the data received. */
    if(ui->cb_ShowRx->isChecked())
    {
        insertDataDisplay(data_disp, ui->cb_DoubleColor->isChecked() ? Qt::blue : Qt::black);
    }

    /* Re-plot oscilloscope. */
    dataProcess(data_src.toHex());
    updateOscilloscope();
}

/* Start send. */
void lion_assistant::send(void)
{
    if(ui->cb_AutoSent->isChecked())
    {
        transmitCircularly();//send some times.
    }
    else
    {
        transmit();  //send once.
    }

}

/* Transmit data from serial port. */
void  lion_assistant::transmit()
{
    if(ui->rdb_HexadecimalSend->isChecked())
    {
        transmitHexadecimal();
    }
    else
    {
        transmitString();
    }
}

/* Transmit String from serial port. */
void lion_assistant::transmitString(void)
{
    /* Transmit data. */
    QString data = ui->tb_tx_msg->toPlainText();
    if(port->write(data.toStdString().c_str()) == -1)
    {
        statusBar()->showMessage("Send data failed : "+ port->errorString());
        return;
    }

    /* Add time to show. */
    if(ui->cb_ShowTime->isChecked())
    {
        QDateTime time = QDateTime::currentDateTime();
        data = time.toString("[yyyy-MM-dd hh:mm:ss] ") + data;
    }
    /* Add newline to show. */
    if(ui->cb_AutoNewLine->isChecked())
    {
        data += "\n";
    }

    /* Show the date sended. */
    if (ui->cb_ShowTx->isChecked())
    {
        insertDataDisplay(data.toLatin1(), ui->cb_DoubleColor->isChecked() ? QColor(10, 135, 40) : Qt::black);
    }
}

/* Transmit hexadecimal number from serial port. */
void lion_assistant::transmitHexadecimal(void)
{
    /* Check if the data is splited by withspace every 2 characters. */
    QString data = ui->tb_tx_msg->toPlainText();
    QRegExp regExp(" *([0-9A-Fa-f]{2} +)+[0-9A-Fa-f]{2} *");
    if(regExp.exactMatch(data))
    {
        /* Convert every 2 characters to hexadecimal. */
        QStringList dataList = data.split(QRegExp(" +"));
        QString newData,showData;
        foreach(const QString& i, dataList)
        {
            showData += i + " ";
            int n = i.toInt(0,16);
            newData += data.sprintf("%c",static_cast<char>(n));
        }

        /* Transmit data. */
        if(port->write(newData.toStdString().c_str()) == -1)
        {
            statusBar()->showMessage("Send data failed : "+ port->errorString());
            return;
        }

        /* Add time to show. */
        if(ui->cb_ShowTime->isChecked())
        {
            QDateTime time = QDateTime::currentDateTime();
            showData = time.toString("[yyyy-MM-dd hh:mm:ss] ") + " " + showData;
        }
        /* Add newline to show. */
        if(ui->cb_AutoNewLine->isChecked())
        {
            showData += "\n";
        }
        /* Show data. */
        insertDataDisplay(showData.toLatin1(),ui->cb_DoubleColor->isChecked() ? Qt::green : Qt::black);
    }
    else
    {
        statusBar()->showMessage("Data format is error",5000);
    }
}

/* Transmit data circularly by setting. */
void lion_assistant::transmitCircularly(void)
{
    delayms = ui->sb_Delay->text().toInt();
    // looptimes = ui->times->text().toInt();
    // if(looptimes>0)
    // {
        timer->start(delayms);
    // }
}

/* Transmit file from serial port. */
void lion_assistant::transmitFile(void)
{
    QString filename = QFileDialog::getOpenFileName(this,tr("打开"));
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
    {
        statusBar()->showMessage("Open file failed",5000);
    }
    else if(port->write(file.readAll()) == -1)
    {
        statusBar()->showMessage("Send data failed : "+ port->errorString(),5000);
    }
    else
    {
        QString message = "[Sended file <" + filename +">]\n";
        insertDataDisplay(message.toLatin1(),Qt::red);
    }
}

/* Read file's content to ui->dataToSend. */
void lion_assistant::openFile(void)
{
//    QString filename = QFileDialog::getOpenFileName(this,tr("打开"));
//    QFile file(filename);
//    if(!file.open(QFile::ReadOnly))
//    {
//        statusBar()->showMessage("Open file failed",5000);
//        return;
//    }
//    ui->dataToSend->setPlainText(file.readAll());
//    file.close();
}


/* Save content of ui->tb_rx_msg into file. */
void lion_assistant::saveAs(void)
{
    QString filename = QFileDialog::getSaveFileName(this,tr("保存"));
    QFile file(filename);
    if(!file.open(QFile::WriteOnly))
    {
        statusBar()->showMessage("Save file failed",5000);
        return;
    }
    QString text = ui->tb_rx_msg->toPlainText();
    file.write(text.toStdString().c_str());
    file.close();
}


/* Clear ui->tb_rx_msg */
void lion_assistant::clear(void)
{
    ui->tb_rx_msg->clear();
}

void lion_assistant::on_btn_TextUI_clicked()
{
    ui->stkWg_MainUI->setCurrentIndex(1);
}

void lion_assistant::on_btn_OscilUI_clicked()
{
    ui->stkWg_MainUI->setCurrentIndex(0);
    on_dial_vertical_actionTriggered();
    on_dial_horizontal_actionTriggered();
}

/**
 * Oscilloscope Initialization
 */
void lion_assistant::initialOscilloscope()
{
    // set some pens, brushes and backgrounds:
    oscilloscope->xAxis->setBasePen(QPen(Qt::white, 1));
    oscilloscope->yAxis->setBasePen(QPen(Qt::white, 1));
    oscilloscope->xAxis->setTickPen(QPen(Qt::white, 1));
    oscilloscope->yAxis->setTickPen(QPen(Qt::white, 1));
    oscilloscope->xAxis->setSubTickPen(QPen(Qt::white, 1));
    oscilloscope->yAxis->setSubTickPen(QPen(Qt::white, 1));
    oscilloscope->xAxis->setTickLabels(false);
    oscilloscope->yAxis->setTickLabels(false);
    oscilloscope->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    oscilloscope->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    oscilloscope->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    oscilloscope->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    oscilloscope->xAxis->grid()->setSubGridVisible(true);
    oscilloscope->yAxis->grid()->setSubGridVisible(true);
    oscilloscope->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    oscilloscope->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    oscilloscope->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    oscilloscope->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    oscilloscope->setBackground(plotGradient);

    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    oscilloscope->axisRect()->setBackground(axisRectGradient);

    oscilloscope->replot();
}

// 转换函数
double byteArr2d(QByteArray src)
{
    double rst = 0;
    for (int i = 0; i < src.length(); i++)
    {
        if (src[i].operator >=('a'))
        {
            rst = rst * 16 + src[i] - 'a' + 10;
        }
        else
        {
            rst = rst * 16 + src[i] - '0';
        }
    }
    return (rst - 32768) / 10;
}

void lion_assistant::dataProcess(QByteArray data)
{
//    ui->statusBar->showMessage(data.mid(0, 4));

    int len = data.length();
    int current = 0;

    while (current < len)
    {
        if (!dataProcess_hasMsgHead)
        {
            if (data.mid(current, 4) == MSG_HEAD)
            {
                dataProcess_hasMsgHead = true;
                dataProcess_MsgBuffer.append(data.mid(current, 4));
                current += 4;
            }
            else {
                current += 1;
            }
        }
        else {
            dataProcess_MsgBuffer.append(data.at(current));

            if (dataProcess_MsgBuffer.length() == MSG_LENGTH)
            {
                if (data1.length() > MAX_DATA_AMOUNT) data1.removeFirst();
                if (data2.length() > MAX_DATA_AMOUNT) data2.removeFirst();
                if (data3.length() > MAX_DATA_AMOUNT) data3.removeFirst();
                if (data4.length() > MAX_DATA_AMOUNT) data4.removeFirst();

                data1.append(byteArr2d(dataProcess_MsgBuffer.mid(4, 4)));
                data2.append(byteArr2d(dataProcess_MsgBuffer.mid(8, 4)));
                data3.append(byteArr2d(dataProcess_MsgBuffer.mid(12, 4)));
                data4.append(byteArr2d(dataProcess_MsgBuffer.mid(16, 4)));

//                ui->statusBar->showMessage(QByteArray::number(data1.last()));
                dataProcess_MsgBuffer.clear();
                dataProcess_hasMsgHead = false;
            }

            current += 1;
        }
    }
}

void lion_assistant::updateOscilloscope()
{
    int len = data1.length();
    double xMin = 0;
    double xMax = oscilloscope_xMax;
    if (oscilloscope_xMax < len)
    {
        xMin = len - oscilloscope_xMax;
        xMax = len;
    }
    oscilloscope->xAxis->setRange(xMin, xMax);
    oscilloscope->yAxis->setRange(-oscilloscope_yMax,oscilloscope_yMax);

    QVector<double> x(len + 1),
                    referX(xMax + 1),
                    refer1Y(xMax + 1), refer2Y(xMax + 1), refer3Y(xMax + 1), refer4Y(xMax + 1),

                    data1D = data1,
                    data2D = data2,
                    data3D = data3,
                    data4D = data4;

    for (int i = 0; i <= xMax; i++)
    {
        if (i < len)
        {
            x[i] = i;
            data1D[i] += offset1;
            data2D[i] += offset2;
            data3D[i] += offset3;
            data4D[i] += offset4;
        }

        referX[i] = i;
        refer1Y[i] = offset1;
        refer2Y[i] = offset2;
        refer3Y[i] = offset3;
        refer4Y[i] = offset4;
    }

    channel1->setData(x, data1D);
    channel2->setData(x, data2D);
    channel3->setData(x, data3D);
    channel4->setData(x, data4D);

    refer1->setData(referX, refer1Y);
    refer2->setData(referX, refer2Y);
    refer3->setData(referX, refer3Y);
    refer4->setData(referX, refer4Y);

//    refer1->setData(x, data1D);
//    refer2->setData(x, data2D);
//    refer3->setData(x, data3D);
//    refer4->setData(x, data4D);

    // 红色
    channel1->setPen(QPen(QColor(255, 20, 20), 2));
    // 青色
    channel2->setPen(QPen(QColor(20, 250, 160), 2));
    // 蓝色
    channel3->setPen(QPen(QColor(20, 135, 250), 2));
    // 紫色
    channel4->setPen(QPen(QColor(220, 20, 250), 2));

    // Plan A: All reference lines are yellow
//    refer1->setPen(QPen(QColor(250, 200, 20), 1, Qt::DotLine));
//    refer2->setPen(QPen(QColor(250, 200, 20), 1, Qt::DotLine));
//    refer3->setPen(QPen(QColor(250, 200, 20), 1, Qt::DotLine));
//    refer4->setPen(QPen(QColor(250, 200, 20), 1, Qt::DotLine));

    // Plan B: Each reference line's color is same as its data line
    refer1->setPen(QPen(QColor(255, 20, 20), 1, Qt::DotLine));
    refer2->setPen(QPen(QColor(20, 250, 160), 1, Qt::DotLine));
    refer3->setPen(QPen(QColor(20, 135, 250), 1, Qt::DotLine));
    refer4->setPen(QPen(QColor(220, 20, 250), 1, Qt::DotLine));

    oscilloscope->replot();
}

void lion_assistant::on_btn_ch1_clicked()
{
    oscilloscope_selectedChannel = 1;

    ui->vSlider_offset->setValue(calculateSliderValue(offset1));
    updateBtnDataLineText();
    updateBtnReferLineText();
    updateBtnIconChColor();
    ui->cb_selectAllChannel->setChecked(false);
}

void lion_assistant::on_btn_ch2_clicked()
{
    oscilloscope_selectedChannel = 2;

    ui->vSlider_offset->setValue(calculateSliderValue(offset2));
    updateBtnDataLineText();
    updateBtnReferLineText();
    updateBtnIconChColor();
    ui->cb_selectAllChannel->setChecked(false);
}

void lion_assistant::on_btn_ch3_clicked()
{
    oscilloscope_selectedChannel = 3;

    ui->vSlider_offset->setValue(calculateSliderValue(offset3));
    updateBtnDataLineText();
    updateBtnReferLineText();
    updateBtnIconChColor();
    ui->cb_selectAllChannel->setChecked(false);
}

void lion_assistant::on_btn_ch4_clicked()
{
    oscilloscope_selectedChannel = 4;

    ui->vSlider_offset->setValue(calculateSliderValue(offset4));
    updateBtnDataLineText();
    updateBtnReferLineText();
    updateBtnIconChColor();
    ui->cb_selectAllChannel->setChecked(false);
}

void lion_assistant::on_btn_oscilClear_clicked()
{
    data1.clear();
    data2.clear();
    data3.clear();
    data4.clear();
    updateOscilloscope();
}

void lion_assistant::on_dial_vertical_actionTriggered()
{
    int dialValue = ui->dial_vertical->value();
    oscilloscope_yMax = int(3277 * (1000 - dialValue) / 100);

    updateOscilloscope();
}

void lion_assistant::on_dial_horizontal_actionTriggered()
{
    int dialValue = ui->dial_horizontal->value();
    oscilloscope_xMax = int(1000 * (100 - dialValue) / 100);

    updateOscilloscope();
}

int lion_assistant::calculateSliderValue(double offset)
{
    return int(offset * 50 / oscilloscope_yMax + MID_SLIDERVALUE);
}

void lion_assistant::updateOffset(double &offset, int sliderValueChanged)
{
    ui->statusBar->showMessage(QString::number(sliderValueChanged));
    double change = 2 * oscilloscope_yMax * sliderValueChanged / 100;

    if (calculateSliderValue(offset + change) > MAX_SLIDERVALUE)
        offset = 2 * oscilloscope_yMax * (MAX_SLIDERVALUE - MID_SLIDERVALUE) / 100;
    else if (calculateSliderValue(offset + change) < 0)
        offset = 2 * oscilloscope_yMax * (MIN_SLIDERVALUE - MID_SLIDERVALUE) / 100;
    else offset += change;
}

void lion_assistant::on_vSlider_offset_actionTriggered()
{
    int sliderValue = ui->vSlider_offset->value();

    switch (oscilloscope_selectedChannel) {
    case 1:
        offset1 = 2 * oscilloscope_yMax * (sliderValue - MID_SLIDERVALUE) / 100;
        break;
    case 2:
        offset2 = 2 * oscilloscope_yMax * (sliderValue - MID_SLIDERVALUE) / 100;
        break;
    case 3:
        offset3 = 2 * oscilloscope_yMax * (sliderValue - MID_SLIDERVALUE) / 100;
        break;
    case 4:
        offset4 = 2 * oscilloscope_yMax * (sliderValue - MID_SLIDERVALUE) / 100;
        break;
    case 5:
        if (ui->cb_selectAllChannel->isChecked())
        {
            updateOffset(offset1, sliderValue - oscilloscope_lastSliderValue);
            updateOffset(offset2, sliderValue - oscilloscope_lastSliderValue);
            updateOffset(offset3, sliderValue - oscilloscope_lastSliderValue);
            updateOffset(offset4, sliderValue - oscilloscope_lastSliderValue);
        }
        oscilloscope_lastSliderValue = sliderValue;
        break;
    default:
        break;
    }

    updateOscilloscope();
}

void lion_assistant::on_btn_referLine_clicked()
{
    switch (oscilloscope_selectedChannel) {
    case 1:
        oscilloscope_isOpenRefer1 = !oscilloscope_isOpenRefer1;
        refer1->setVisible(oscilloscope_isOpenRefer1);
        updateBtnReferLineText();
        break;
    case 2:
        oscilloscope_isOpenRefer2 = !oscilloscope_isOpenRefer2;
        refer2->setVisible(oscilloscope_isOpenRefer2);
        updateBtnReferLineText();
        break;
    case 3:
        oscilloscope_isOpenRefer3 = !oscilloscope_isOpenRefer3;
        refer3->setVisible(oscilloscope_isOpenRefer3);
        updateBtnReferLineText();
        break;
    case 4:
        oscilloscope_isOpenRefer4 = !oscilloscope_isOpenRefer4;
        refer4->setVisible(oscilloscope_isOpenRefer4);
        updateBtnReferLineText();
        break;
    case 5:
        oscilloscope_isOpenRefer1 = !oscilloscope_isOpenRefer1;
        oscilloscope_isOpenRefer2 =  oscilloscope_isOpenRefer1;
        oscilloscope_isOpenRefer3 =  oscilloscope_isOpenRefer1;
        oscilloscope_isOpenRefer4 =  oscilloscope_isOpenRefer1;
        refer1->setVisible(oscilloscope_isOpenRefer1);
        refer2->setVisible(oscilloscope_isOpenRefer2);
        refer3->setVisible(oscilloscope_isOpenRefer3);
        refer4->setVisible(oscilloscope_isOpenRefer4);
        updateBtnIconChColor();
        updateBtnReferLineText();
        break;
    default:
        break;
    }

    updateOscilloscope();
}

void lion_assistant::on_btn_zeroOffset_clicked()
{
    switch (oscilloscope_selectedChannel) {
    case 1:
        offset1 = 0;
        break;
    case 2:
        offset2 = 0;
        break;
    case 3:
        offset3 = 0;
        break;
    case 4:
        offset4 = 0;
        break;
    case 5:
        offset1 = 0;
        offset2 = 0;
        offset3 = 0;
        offset4 = 0;
        break;
    default:
        break;
    }

    ui->vSlider_offset->setValue(MID_SLIDERVALUE);

    updateOscilloscope();
}

void lion_assistant::on_btn_dataLine_clicked()
{
    switch (oscilloscope_selectedChannel) {
    case 1:
        oscilloscope_isOpenCh1 = !oscilloscope_isOpenCh1;
        channel1->setVisible(oscilloscope_isOpenCh1);
        updateBtnIconChColor();
        updateBtnDataLineText();
        break;
    case 2:
        oscilloscope_isOpenCh2 = !oscilloscope_isOpenCh2;
        channel2->setVisible(oscilloscope_isOpenCh2);
        updateBtnIconChColor();
        updateBtnDataLineText();
        break;
    case 3:
        oscilloscope_isOpenCh3 = !oscilloscope_isOpenCh3;
        channel3->setVisible(oscilloscope_isOpenCh3);
        updateBtnIconChColor();
        updateBtnDataLineText();
        break;
    case 4:
        oscilloscope_isOpenCh4 = !oscilloscope_isOpenCh4;
        channel4->setVisible(oscilloscope_isOpenCh4);
        updateBtnIconChColor();
        updateBtnDataLineText();
        break;
    case 5:
        oscilloscope_isOpenCh1 = !oscilloscope_isOpenCh1;
        oscilloscope_isOpenCh2 =  oscilloscope_isOpenCh1;
        oscilloscope_isOpenCh3 =  oscilloscope_isOpenCh1;
        oscilloscope_isOpenCh4 =  oscilloscope_isOpenCh1;
        channel1->setVisible(oscilloscope_isOpenCh1);
        channel2->setVisible(oscilloscope_isOpenCh2);
        channel3->setVisible(oscilloscope_isOpenCh3);
        channel4->setVisible(oscilloscope_isOpenCh4);
        updateBtnIconChColor();
        updateBtnDataLineText();
        break;
    default:
        break;
    }

    updateOscilloscope();
}

void lion_assistant::updateBtnIconChColor()
{
    QString iconCh1Color = "background-color: rgb(255, 20, 20);",
            iconCh2Color = "background-color: rgb(20, 250, 160);",
            iconCh3Color = "background-color: rgb(20, 135, 250);",
            iconCh4Color = "background-color: rgb(220, 20, 250);",
            iconNoColor = "background-color: rgb(200, 200, 200);",
            iconBorderY = "",
            iconBorderN = "border: none;",

            iconCh1Style,
            iconCh2Style,
            iconCh3Style,
            iconCh4Style;

    switch (oscilloscope_selectedChannel)
    {
        case 1:
            iconCh1Style = iconBorderY;
            iconCh2Style = iconBorderN;
            iconCh3Style = iconBorderN;
            iconCh4Style = iconBorderN;
        break;
        case 2:
            iconCh1Style = iconBorderN;
            iconCh2Style = iconBorderY;
            iconCh3Style = iconBorderN;
            iconCh4Style = iconBorderN;
            break;
        case 3:
            iconCh1Style = iconBorderN;
            iconCh2Style = iconBorderN;
            iconCh3Style = iconBorderY;
            iconCh4Style = iconBorderN;
            break;
        case 4:
            iconCh1Style = iconBorderN;
            iconCh2Style = iconBorderN;
            iconCh3Style = iconBorderN;
            iconCh4Style = iconBorderY;
            break;
        case 5:
            iconCh1Style = iconBorderN;
            iconCh2Style = iconBorderN;
            iconCh3Style = iconBorderN;
            iconCh4Style = iconBorderN;
            break;
        default:
            break;
    }

    oscilloscope_isOpenCh1 ? iconCh1Style += iconCh1Color : iconCh1Style += iconNoColor;
    oscilloscope_isOpenCh2 ? iconCh2Style += iconCh2Color : iconCh2Style += iconNoColor;
    oscilloscope_isOpenCh3 ? iconCh3Style += iconCh3Color : iconCh3Style += iconNoColor;
    oscilloscope_isOpenCh4 ? iconCh4Style += iconCh4Color : iconCh4Style += iconNoColor;

    ui->btn_iconCh1->setStyleSheet(iconCh1Style);
    ui->btn_iconCh2->setStyleSheet(iconCh2Style);
    ui->btn_iconCh3->setStyleSheet(iconCh3Style);
    ui->btn_iconCh4->setStyleSheet(iconCh4Style);
}

void lion_assistant::updateBtnDataLineText()
{
    switch (oscilloscope_selectedChannel) {
    case 1:
        if (oscilloscope_isOpenCh1) ui->btn_dataLine->setText("隐藏波形");
        else                        ui->btn_dataLine->setText("显示波形");
        break;
    case 2:
        if (oscilloscope_isOpenCh2) ui->btn_dataLine->setText("隐藏波形");
        else                        ui->btn_dataLine->setText("显示波形");
        break;
    case 3:
        if (oscilloscope_isOpenCh3) ui->btn_dataLine->setText("隐藏波形");
        else                        ui->btn_dataLine->setText("显示波形");
        break;
    case 4:
        if (oscilloscope_isOpenCh4) ui->btn_dataLine->setText("隐藏波形");
        else                        ui->btn_dataLine->setText("显示波形");
        break;
    case 5:
        if (oscilloscope_isOpenCh1
         || oscilloscope_isOpenCh2
         || oscilloscope_isOpenCh3
         || oscilloscope_isOpenCh4)
            ui->btn_dataLine->setText("隐藏波形");
        else
            ui->btn_dataLine->setText("显示波形");
    default:
        break;
    }
}

void lion_assistant::updateBtnReferLineText()
{
    switch (oscilloscope_selectedChannel) {
    case 1:
        if (oscilloscope_isOpenRefer1) ui->btn_referLine->setText("隐藏基线");
        else                           ui->btn_referLine->setText("显示基线");
        break;
    case 2:
        if (oscilloscope_isOpenRefer2) ui->btn_referLine->setText("隐藏基线");
        else                           ui->btn_referLine->setText("显示基线");
        break;
    case 3:
        if (oscilloscope_isOpenRefer3) ui->btn_referLine->setText("隐藏基线");
        else                           ui->btn_referLine->setText("显示基线");
        break;
    case 4:
        if (oscilloscope_isOpenRefer4) ui->btn_referLine->setText("隐藏基线");
        else                           ui->btn_referLine->setText("显示基线");
        break;
    case 5:
        if (oscilloscope_isOpenRefer1
         || oscilloscope_isOpenRefer2
         || oscilloscope_isOpenRefer3
         || oscilloscope_isOpenRefer4)
            ui->btn_referLine->setText("隐藏基线");
        else
            ui->btn_referLine->setText("显示基线");
        break;
    default:
        break;
    }
}

void lion_assistant::on_btn_SendPID_clicked()
{
    QString Requirement,
            opt1 = ui->tx_option1->toPlainText(),
            opt2 = ui->tx_option2->toPlainText();

    double P = ui->tx_Pvalue->value(),
           I = ui->tx_Ivalue->value(),
           D = ui->tx_Dvalue->value();

    Requirement = "p" + QString::number(P) + "p"
                + "i" + QString::number(I) + "i"
                + "d" + QString::number(D) + "d";

    if (ui->cb_option1->isChecked())
        Requirement += opt1;
    if (ui->cb_option2->isChecked())
        Requirement += opt2;

    if(port->write(Requirement.toStdString().c_str()) == -1)
    {
        statusBar()->showMessage("Send PID failed : " + port->errorString(), 5000);
        return;
    }
}

void lion_assistant::on_btn_Mark_clicked()
{
    double P = ui->tx_Pvalue->value(),
           I = ui->tx_Ivalue->value(),
           D = ui->tx_Dvalue->value();

    QString opt1 = ui->tx_option1->toPlainText(),
            opt2 = ui->tx_option2->toPlainText(),
            mark = "P = " + QString::number(P) + " | "
                 + "I = " + QString::number(I) + " | "
                 + "D = " + QString::number(D);

    if (ui->cb_option1->isChecked())
        mark += " | opt1 = " + opt1;
    if (ui->cb_option2->isChecked())
        mark += " | opt2 = " + opt2;

    ui->list_PIDvalue->addItem(mark);
}

void lion_assistant::on_list_PIDvalue_itemDoubleClicked(QListWidgetItem *item)
{
    double P, I, D;

    foreach(QString value, item->text().split("|"))
    {
        value.trimmed();
        value.replace(" ", "");
        switch (value[0].toLatin1())
        {
            case 'P':
                P = value.mid(2).toDouble();
                ui->tx_Pvalue->setValue(P);
            break;
            case 'I':
                I = value.mid(2).toDouble();
                ui->tx_Ivalue->setValue(I);
            break;
            case 'D':
                D = value.mid(2).toDouble();
                ui->tx_Dvalue->setValue(D);
            break;
            default:
                if (value[3] == '1')
                {
                    ui->tx_option1->setPlainText(value.mid(5));
                    ui->cb_option1->setChecked(true);
                }
                else
                {
                    ui->tx_option2->setPlainText(value.mid(5));
                    ui->cb_option2->setChecked(true);
                }
            break;
        }
    }
}

void lion_assistant::scanComs()
{
    bool serial_isAvailable = false;
    if (!serial_isOpen)
    {
        ui->cmb_PortName->clear();

        // 遍历可选串口信息
        foreach (const QSerialPortInfo &portInfo, QSerialPortInfo::availablePorts())
        {
            QSerialPort serial;
            serial.setPort(portInfo);

            // 尝试以读写的方式打开串口
            if (serial.open(QIODevice::ReadWrite))
            {
                // 成功开启，将可用串口加到可选列表中
                ui->cmb_PortName->addItem(portInfo.portName());

                // 关闭自动开启，等待认为打开
                serial.close();

                // 设置串口可用flag
                serial_isAvailable = true;
            }
        }

        serial_isAvailable ? ui->btn_OpenSerial->setEnabled(true)
                           : ui->btn_OpenSerial->setEnabled(false);
    }
}

void lion_assistant::on_list_PIDvalue_itemClicked(QListWidgetItem *item)
{
    QString itemText = item->text(),
            text2clipboard;

    // 避免多次点击占满粘贴板
    if (oscilloscope_lastItemText == itemText)
        return;

    oscilloscope_lastItemText = itemText;

    itemText.trimmed();
    itemText.replace(" ", "");

    text2clipboard = "[Lion Assistant]\n";
    text2clipboard += QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + "\n";
    text2clipboard += "-------------------\n";

    foreach(QString value, item->text().split("|"))
    {
        value.trimmed();
        value.replace(" ", "");

        switch (value[0].toLatin1())
        {
            case 'P':
                text2clipboard += "P = " + value.mid(2) + "\n";
            break;
            case 'I':
                text2clipboard += "I = " + value.mid(2) + "\n";
            break;
            case 'D':
                text2clipboard += "D = " + value.mid(2) + "\n";
            break;
            default:
                if (value[3] == '1')
                {
                    text2clipboard += "opt1 = " + value.mid(5) + "\n";
                }
                else
                {
                    text2clipboard += "opt2 = " + value.mid(5) + "\n";
                }
            break;
        }
    }

    text2clipboard += "Comment: \n";

    clipboard->setText(text2clipboard);
}

void lion_assistant::on_cb_selectAllChannel_clicked(bool checked)
{
    // 勾选
    if (checked)
    {
        oscilloscope_lastSelectedChannel = oscilloscope_selectedChannel;
        oscilloscope_selectedChannel = 5;
        updateBtnIconChColor();
        updateBtnDataLineText();
        updateBtnReferLineText();

        oscilloscope_lastSliderValue = MID_SLIDERVALUE;
        ui->vSlider_offset->setValue(MID_SLIDERVALUE);
    }

    // 取消勾选
    else switch(oscilloscope_lastSelectedChannel)
    {
        case 1: on_btn_ch1_clicked(); break;
        case 2: on_btn_ch2_clicked(); break;
        case 3: on_btn_ch3_clicked(); break;
        case 4: on_btn_ch4_clicked(); break;
        default: break;
    }
}

void lion_assistant::on_sb_Delay_valueChanged()
{
    transmitCircularly();
}
