/********************************************************************************
** Form generated from reading UI file 'lion_assistant.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LION_ASSISTANT_H
#define UI_LION_ASSISTANT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_lion_assistant
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_11;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *VLayout_serialSetting;
    QSpacerItem *verticalSpacer_5;
    QGroupBox *groupBox;
    QComboBox *cmb_PortName;
    QLabel *label_2;
    QComboBox *cmb_BaudRate;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *cmb_DataBits;
    QLabel *label_5;
    QComboBox *cmb_Parity;
    QLabel *label_6;
    QComboBox *cmb_StopBits;
    QPushButton *btn_OpenSerial;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_TextUI;
    QPushButton *btn_OscilUI;
    QSpacerItem *verticalSpacer_3;
    QGridLayout *gridLayout_5;
    QStackedWidget *stkWg_MainUI;
    QWidget *page_2;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_18;
    QWidget *widget;
    QPushButton *btn_ch4;
    QDial *dial_horizontal;
    QPushButton *btn_dataLine;
    QPushButton *btn_ch1;
    QLabel *label_slider_vertical;
    QPushButton *btn_ch3;
    QDial *dial_vertical;
    QPushButton *btn_oscilClear;
    QLabel *label_slider_vertical_2;
    QPushButton *btn_ch2;
    QSlider *vSlider_offset;
    QPushButton *btn_zeroOffset;
    QPushButton *btn_iconCh1;
    QPushButton *btn_iconCh2;
    QPushButton *btn_iconCh3;
    QPushButton *btn_iconCh4;
    QPushButton *btn_referLine;
    QCheckBox *cb_selectAllChannel;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QListWidget *list_PIDvalue;
    QPlainTextEdit *tx_option1;
    QCheckBox *cb_option1;
    QCheckBox *cb_option2;
    QPushButton *btn_Mark;
    QPlainTextEdit *tx_option2;
    QPushButton *btn_SendPID;
    QWidget *widget_4;
    QDoubleSpinBox *tx_Ivalue;
    QLabel *label_Ivalue;
    QWidget *widget_3;
    QDoubleSpinBox *tx_Pvalue;
    QLabel *label_Pvalue;
    QWidget *widget_5;
    QDoubleSpinBox *tx_Dvalue;
    QLabel *label_value;
    QPushButton *btn_exportMark;
    QPushButton *btn_importMark;
    QPushButton *btn_clearMark;
    QCustomPlot *qCustomPlot;
    QSpacerItem *verticalSpacer_7;
    QWidget *page;
    QGridLayout *gridLayout_10;
    QSpacerItem *verticalSpacer_8;
    QGridLayout *gridLayout_9;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_7;
    QPushButton *btn_Send;
    QGroupBox *groupBox_3;
    QRadioButton *rdb_HexadecimalSend;
    QRadioButton *radioButton_5;
    QCheckBox *cb_AutoSent;
    QSpinBox *sb_Delay;
    QLabel *label_8;
    QWidget *widget_6;
    QPushButton *btn_Clear;
    QGroupBox *groupBox_2;
    QRadioButton *rdb_ASCIIDisp;
    QRadioButton *rdb_HexDisp;
    QCheckBox *cb_AutoNewLine;
    QCheckBox *cb_ShowTx;
    QCheckBox *cb_ShowTime;
    QCheckBox *cb_DoubleColor;
    QCheckBox *cb_ShowRx;
    QTextBrowser *tb_rx_msg;
    QPlainTextEdit *tb_tx_msg;
    QSpacerItem *verticalSpacer_9;
    QVBoxLayout *verticalLayout_12;
    QSpacerItem *verticalSpacer_6;
    QFrame *line_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *lion_assistant)
    {
        if (lion_assistant->objectName().isEmpty())
            lion_assistant->setObjectName(QStringLiteral("lion_assistant"));
        lion_assistant->resize(876, 656);
        lion_assistant->setMinimumSize(QSize(876, 620));
        centralWidget = new QWidget(lion_assistant);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_11 = new QGridLayout(centralWidget);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        horizontalSpacer_2 = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        VLayout_serialSetting = new QVBoxLayout();
        VLayout_serialSetting->setSpacing(6);
        VLayout_serialSetting->setObjectName(QStringLiteral("VLayout_serialSetting"));
        VLayout_serialSetting->setSizeConstraint(QLayout::SetMinimumSize);
        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        VLayout_serialSetting->addItem(verticalSpacer_5);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 171));
        cmb_PortName = new QComboBox(groupBox);
        cmb_PortName->setObjectName(QStringLiteral("cmb_PortName"));
        cmb_PortName->setGeometry(QRect(60, 20, 91, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 41, 21));
        cmb_BaudRate = new QComboBox(groupBox);
        cmb_BaudRate->setObjectName(QStringLiteral("cmb_BaudRate"));
        cmb_BaudRate->setGeometry(QRect(60, 50, 91, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 50, 41, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 80, 41, 21));
        cmb_DataBits = new QComboBox(groupBox);
        cmb_DataBits->setObjectName(QStringLiteral("cmb_DataBits"));
        cmb_DataBits->setGeometry(QRect(60, 80, 91, 20));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 110, 41, 21));
        cmb_Parity = new QComboBox(groupBox);
        cmb_Parity->setObjectName(QStringLiteral("cmb_Parity"));
        cmb_Parity->setGeometry(QRect(60, 110, 91, 20));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 140, 41, 21));
        cmb_StopBits = new QComboBox(groupBox);
        cmb_StopBits->setObjectName(QStringLiteral("cmb_StopBits"));
        cmb_StopBits->setGeometry(QRect(60, 140, 91, 20));

        VLayout_serialSetting->addWidget(groupBox);

        btn_OpenSerial = new QPushButton(centralWidget);
        btn_OpenSerial->setObjectName(QStringLiteral("btn_OpenSerial"));
        btn_OpenSerial->setMinimumSize(QSize(160, 0));

        VLayout_serialSetting->addWidget(btn_OpenSerial);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        VLayout_serialSetting->addItem(verticalSpacer);

        btn_TextUI = new QPushButton(centralWidget);
        btn_TextUI->setObjectName(QStringLiteral("btn_TextUI"));

        VLayout_serialSetting->addWidget(btn_TextUI);

        btn_OscilUI = new QPushButton(centralWidget);
        btn_OscilUI->setObjectName(QStringLiteral("btn_OscilUI"));

        VLayout_serialSetting->addWidget(btn_OscilUI);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        VLayout_serialSetting->addItem(verticalSpacer_3);


        gridLayout_11->addLayout(VLayout_serialSetting, 0, 1, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        stkWg_MainUI = new QStackedWidget(centralWidget);
        stkWg_MainUI->setObjectName(QStringLiteral("stkWg_MainUI"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        gridLayout_8 = new QGridLayout(page_2);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        widget = new QWidget(page_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(301, 171));
        widget->setMaximumSize(QSize(301, 171));
        btn_ch4 = new QPushButton(widget);
        btn_ch4->setObjectName(QStringLiteral("btn_ch4"));
        btn_ch4->setGeometry(QRect(100, 100, 51, 23));
        dial_horizontal = new QDial(widget);
        dial_horizontal->setObjectName(QStringLiteral("dial_horizontal"));
        dial_horizontal->setGeometry(QRect(170, 0, 111, 111));
        btn_dataLine = new QPushButton(widget);
        btn_dataLine->setObjectName(QStringLiteral("btn_dataLine"));
        btn_dataLine->setGeometry(QRect(70, 149, 61, 23));
        btn_ch1 = new QPushButton(widget);
        btn_ch1->setObjectName(QStringLiteral("btn_ch1"));
        btn_ch1->setGeometry(QRect(100, 10, 51, 23));
        label_slider_vertical = new QLabel(widget);
        label_slider_vertical->setObjectName(QStringLiteral("label_slider_vertical"));
        label_slider_vertical->setGeometry(QRect(20, 110, 51, 16));
        btn_ch3 = new QPushButton(widget);
        btn_ch3->setObjectName(QStringLiteral("btn_ch3"));
        btn_ch3->setGeometry(QRect(100, 70, 51, 23));
        dial_vertical = new QDial(widget);
        dial_vertical->setObjectName(QStringLiteral("dial_vertical"));
        dial_vertical->setGeometry(QRect(-10, 0, 111, 111));
        btn_oscilClear = new QPushButton(widget);
        btn_oscilClear->setObjectName(QStringLiteral("btn_oscilClear"));
        btn_oscilClear->setGeometry(QRect(0, 149, 61, 23));
        label_slider_vertical_2 = new QLabel(widget);
        label_slider_vertical_2->setObjectName(QStringLiteral("label_slider_vertical_2"));
        label_slider_vertical_2->setGeometry(QRect(200, 110, 51, 16));
        btn_ch2 = new QPushButton(widget);
        btn_ch2->setObjectName(QStringLiteral("btn_ch2"));
        btn_ch2->setGeometry(QRect(100, 40, 51, 23));
        vSlider_offset = new QSlider(widget);
        vSlider_offset->setObjectName(QStringLiteral("vSlider_offset"));
        vSlider_offset->setGeometry(QRect(280, 9, 22, 131));
        vSlider_offset->setValue(50);
        vSlider_offset->setOrientation(Qt::Vertical);
        btn_zeroOffset = new QPushButton(widget);
        btn_zeroOffset->setObjectName(QStringLiteral("btn_zeroOffset"));
        btn_zeroOffset->setGeometry(QRect(210, 149, 61, 23));
        btn_iconCh1 = new QPushButton(widget);
        btn_iconCh1->setObjectName(QStringLiteral("btn_iconCh1"));
        btn_iconCh1->setEnabled(false);
        btn_iconCh1->setGeometry(QRect(154, 14, 16, 16));
        btn_iconCh2 = new QPushButton(widget);
        btn_iconCh2->setObjectName(QStringLiteral("btn_iconCh2"));
        btn_iconCh2->setEnabled(false);
        btn_iconCh2->setGeometry(QRect(154, 44, 16, 16));
        btn_iconCh3 = new QPushButton(widget);
        btn_iconCh3->setObjectName(QStringLiteral("btn_iconCh3"));
        btn_iconCh3->setEnabled(false);
        btn_iconCh3->setGeometry(QRect(154, 74, 16, 16));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_iconCh3->sizePolicy().hasHeightForWidth());
        btn_iconCh3->setSizePolicy(sizePolicy);
        btn_iconCh4 = new QPushButton(widget);
        btn_iconCh4->setObjectName(QStringLiteral("btn_iconCh4"));
        btn_iconCh4->setEnabled(false);
        btn_iconCh4->setGeometry(QRect(154, 104, 16, 16));
        btn_referLine = new QPushButton(widget);
        btn_referLine->setObjectName(QStringLiteral("btn_referLine"));
        btn_referLine->setGeometry(QRect(140, 149, 61, 23));
        cb_selectAllChannel = new QCheckBox(widget);
        cb_selectAllChannel->setObjectName(QStringLiteral("cb_selectAllChannel"));
        cb_selectAllChannel->setGeometry(QRect(284, 152, 16, 16));
        cb_selectAllChannel->setChecked(false);
        btn_ch4->raise();
        dial_horizontal->raise();
        btn_ch1->raise();
        label_slider_vertical->raise();
        btn_ch3->raise();
        dial_vertical->raise();
        btn_oscilClear->raise();
        label_slider_vertical_2->raise();
        btn_ch2->raise();
        btn_dataLine->raise();
        vSlider_offset->raise();
        btn_zeroOffset->raise();
        btn_iconCh1->raise();
        btn_iconCh2->raise();
        btn_iconCh3->raise();
        btn_iconCh4->raise();
        btn_referLine->raise();
        cb_selectAllChannel->raise();

        horizontalLayout_18->addWidget(widget);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer);

        widget_2 = new QWidget(page_2);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(301, 171));
        widget_2->setMaximumSize(QSize(301, 171));
        list_PIDvalue = new QListWidget(widget_2);
        list_PIDvalue->setObjectName(QStringLiteral("list_PIDvalue"));
        list_PIDvalue->setGeometry(QRect(0, 120, 301, 51));
        tx_option1 = new QPlainTextEdit(widget_2);
        tx_option1->setObjectName(QStringLiteral("tx_option1"));
        tx_option1->setGeometry(QRect(0, 50, 141, 31));
        cb_option1 = new QCheckBox(widget_2);
        cb_option1->setObjectName(QStringLiteral("cb_option1"));
        cb_option1->setGeometry(QRect(0, 30, 81, 16));
        cb_option2 = new QCheckBox(widget_2);
        cb_option2->setObjectName(QStringLiteral("cb_option2"));
        cb_option2->setGeometry(QRect(160, 30, 81, 16));
        btn_Mark = new QPushButton(widget_2);
        btn_Mark->setObjectName(QStringLiteral("btn_Mark"));
        btn_Mark->setGeometry(QRect(185, 91, 55, 23));
        tx_option2 = new QPlainTextEdit(widget_2);
        tx_option2->setObjectName(QStringLiteral("tx_option2"));
        tx_option2->setGeometry(QRect(160, 50, 141, 31));
        btn_SendPID = new QPushButton(widget_2);
        btn_SendPID->setObjectName(QStringLiteral("btn_SendPID"));
        btn_SendPID->setGeometry(QRect(246, 91, 56, 23));
        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(104, 5, 91, 20));
        widget_4->setMaximumSize(QSize(91, 20));
        tx_Ivalue = new QDoubleSpinBox(widget_4);
        tx_Ivalue->setObjectName(QStringLiteral("tx_Ivalue"));
        tx_Ivalue->setGeometry(QRect(20, 0, 71, 20));
        tx_Ivalue->setMinimumSize(QSize(60, 0));
        tx_Ivalue->setDecimals(5);
        tx_Ivalue->setMaximum(9999.99);
        tx_Ivalue->setSingleStep(0.001);
        label_Ivalue = new QLabel(widget_4);
        label_Ivalue->setObjectName(QStringLiteral("label_Ivalue"));
        label_Ivalue->setGeometry(QRect(0, 0, 15, 20));
        label_Ivalue->setAlignment(Qt::AlignCenter);
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(-1, 5, 91, 20));
        widget_3->setMaximumSize(QSize(91, 20));
        tx_Pvalue = new QDoubleSpinBox(widget_3);
        tx_Pvalue->setObjectName(QStringLiteral("tx_Pvalue"));
        tx_Pvalue->setGeometry(QRect(20, 0, 71, 20));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tx_Pvalue->sizePolicy().hasHeightForWidth());
        tx_Pvalue->setSizePolicy(sizePolicy1);
        tx_Pvalue->setMinimumSize(QSize(70, 0));
        tx_Pvalue->setMaximum(9999.99);
        label_Pvalue = new QLabel(widget_3);
        label_Pvalue->setObjectName(QStringLiteral("label_Pvalue"));
        label_Pvalue->setGeometry(QRect(-1, 0, 15, 20));
        label_Pvalue->setAlignment(Qt::AlignCenter);
        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(209, 5, 91, 20));
        widget_5->setMaximumSize(QSize(91, 20));
        tx_Dvalue = new QDoubleSpinBox(widget_5);
        tx_Dvalue->setObjectName(QStringLiteral("tx_Dvalue"));
        tx_Dvalue->setGeometry(QRect(20, 0, 71, 20));
        tx_Dvalue->setMinimumSize(QSize(60, 0));
        tx_Dvalue->setMaximum(9999.99);
        tx_Dvalue->setSingleStep(10);
        label_value = new QLabel(widget_5);
        label_value->setObjectName(QStringLiteral("label_value"));
        label_value->setGeometry(QRect(0, 0, 15, 20));
        label_value->setAlignment(Qt::AlignCenter);
        btn_exportMark = new QPushButton(widget_2);
        btn_exportMark->setObjectName(QStringLiteral("btn_exportMark"));
        btn_exportMark->setGeometry(QRect(61, 91, 55, 23));
        btn_importMark = new QPushButton(widget_2);
        btn_importMark->setObjectName(QStringLiteral("btn_importMark"));
        btn_importMark->setGeometry(QRect(123, 91, 55, 23));
        btn_clearMark = new QPushButton(widget_2);
        btn_clearMark->setObjectName(QStringLiteral("btn_clearMark"));
        btn_clearMark->setGeometry(QRect(0, 91, 55, 23));

        horizontalLayout_18->addWidget(widget_2);


        gridLayout_8->addLayout(horizontalLayout_18, 2, 0, 1, 1);

        qCustomPlot = new QCustomPlot(page_2);
        qCustomPlot->setObjectName(QStringLiteral("qCustomPlot"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(qCustomPlot->sizePolicy().hasHeightForWidth());
        qCustomPlot->setSizePolicy(sizePolicy2);
        qCustomPlot->setMinimumSize(QSize(610, 231));
        qCustomPlot->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_8->addWidget(qCustomPlot, 0, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_8->addItem(verticalSpacer_7, 1, 0, 1, 1);

        stkWg_MainUI->addWidget(page_2);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        gridLayout_10 = new QGridLayout(page);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        verticalSpacer_8 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_10->addItem(verticalSpacer_8, 1, 0, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer_2, 2, 0, 1, 1);

        widget_7 = new QWidget(page);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setMinimumSize(QSize(141, 141));
        widget_7->setMaximumSize(QSize(141, 141));
        btn_Send = new QPushButton(widget_7);
        btn_Send->setObjectName(QStringLiteral("btn_Send"));
        btn_Send->setGeometry(QRect(0, 119, 141, 23));
        groupBox_3 = new QGroupBox(widget_7);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 0, 141, 111));
        rdb_HexadecimalSend = new QRadioButton(groupBox_3);
        rdb_HexadecimalSend->setObjectName(QStringLiteral("rdb_HexadecimalSend"));
        rdb_HexadecimalSend->setGeometry(QRect(80, 20, 51, 21));
        radioButton_5 = new QRadioButton(groupBox_3);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(10, 20, 51, 21));
        radioButton_5->setChecked(true);
        cb_AutoSent = new QCheckBox(groupBox_3);
        cb_AutoSent->setObjectName(QStringLiteral("cb_AutoSent"));
        cb_AutoSent->setGeometry(QRect(10, 50, 121, 21));
        sb_Delay = new QSpinBox(groupBox_3);
        sb_Delay->setObjectName(QStringLiteral("sb_Delay"));
        sb_Delay->setGeometry(QRect(30, 80, 71, 22));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(110, 80, 21, 21));

        gridLayout_9->addWidget(widget_7, 3, 0, 1, 1);

        widget_6 = new QWidget(page);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMinimumSize(QSize(141, 232));
        widget_6->setMaximumSize(QSize(141, 232));
        btn_Clear = new QPushButton(widget_6);
        btn_Clear->setObjectName(QStringLiteral("btn_Clear"));
        btn_Clear->setGeometry(QRect(0, 210, 141, 23));
        groupBox_2 = new QGroupBox(widget_6);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 141, 201));
        rdb_ASCIIDisp = new QRadioButton(groupBox_2);
        rdb_ASCIIDisp->setObjectName(QStringLiteral("rdb_ASCIIDisp"));
        rdb_ASCIIDisp->setGeometry(QRect(10, 20, 51, 21));
        rdb_ASCIIDisp->setChecked(true);
        rdb_HexDisp = new QRadioButton(groupBox_2);
        rdb_HexDisp->setObjectName(QStringLiteral("rdb_HexDisp"));
        rdb_HexDisp->setGeometry(QRect(80, 20, 51, 21));
        cb_AutoNewLine = new QCheckBox(groupBox_2);
        cb_AutoNewLine->setObjectName(QStringLiteral("cb_AutoNewLine"));
        cb_AutoNewLine->setGeometry(QRect(10, 140, 71, 21));
        cb_ShowTx = new QCheckBox(groupBox_2);
        cb_ShowTx->setObjectName(QStringLiteral("cb_ShowTx"));
        cb_ShowTx->setGeometry(QRect(10, 80, 71, 21));
        cb_ShowTime = new QCheckBox(groupBox_2);
        cb_ShowTime->setObjectName(QStringLiteral("cb_ShowTime"));
        cb_ShowTime->setGeometry(QRect(10, 110, 71, 21));
        cb_DoubleColor = new QCheckBox(groupBox_2);
        cb_DoubleColor->setObjectName(QStringLiteral("cb_DoubleColor"));
        cb_DoubleColor->setGeometry(QRect(10, 170, 101, 21));
        cb_ShowRx = new QCheckBox(groupBox_2);
        cb_ShowRx->setObjectName(QStringLiteral("cb_ShowRx"));
        cb_ShowRx->setGeometry(QRect(10, 50, 71, 21));

        gridLayout_9->addWidget(widget_6, 1, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_9, 0, 2, 3, 1);

        tb_rx_msg = new QTextBrowser(page);
        tb_rx_msg->setObjectName(QStringLiteral("tb_rx_msg"));
        tb_rx_msg->setMinimumSize(QSize(0, 201));

        gridLayout_10->addWidget(tb_rx_msg, 0, 0, 1, 1);

        tb_tx_msg = new QPlainTextEdit(page);
        tb_tx_msg->setObjectName(QStringLiteral("tb_tx_msg"));

        gridLayout_10->addWidget(tb_tx_msg, 2, 0, 1, 1);

        verticalSpacer_9 = new QSpacerItem(10, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_10->addItem(verticalSpacer_9, 0, 1, 1, 1);

        stkWg_MainUI->addWidget(page);

        gridLayout_5->addWidget(stkWg_MainUI, 0, 0, 1, 1);


        gridLayout_11->addLayout(gridLayout_5, 0, 4, 1, 1);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalSpacer_6 = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_12->addItem(verticalSpacer_6);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setMinimumSize(QSize(10, 0));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_12->addWidget(line_3);

        verticalSpacer_4 = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_12->addItem(verticalSpacer_4);


        gridLayout_11->addLayout(verticalLayout_12, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        lion_assistant->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(lion_assistant);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        lion_assistant->setStatusBar(statusBar);

        retranslateUi(lion_assistant);

        stkWg_MainUI->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(lion_assistant);
    } // setupUi

    void retranslateUi(QMainWindow *lion_assistant)
    {
        lion_assistant->setWindowTitle(QApplication::translate("lion_assistant", "lion_assistant", nullptr));
        groupBox->setTitle(QApplication::translate("lion_assistant", "\344\270\262\345\217\243\350\256\276\347\275\256", nullptr));
        label_2->setText(QApplication::translate("lion_assistant", "\344\270\262\345\217\243\345\217\267", nullptr));
        label_3->setText(QApplication::translate("lion_assistant", "\346\263\242\347\211\271\347\216\207", nullptr));
        label_4->setText(QApplication::translate("lion_assistant", "\346\225\260\346\215\256\344\275\215", nullptr));
        label_5->setText(QApplication::translate("lion_assistant", "\346\240\241\351\252\214\344\275\215", nullptr));
        label_6->setText(QApplication::translate("lion_assistant", "\345\201\234\346\255\242\344\275\215", nullptr));
        btn_OpenSerial->setText(QApplication::translate("lion_assistant", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        btn_TextUI->setText(QApplication::translate("lion_assistant", "\346\226\207\346\234\254\350\260\203\350\257\225", nullptr));
        btn_OscilUI->setText(QApplication::translate("lion_assistant", "PID\350\260\203\350\257\225", nullptr));
        btn_ch4->setText(QApplication::translate("lion_assistant", "CH4", nullptr));
        btn_dataLine->setText(QApplication::translate("lion_assistant", "\346\230\276\347\244\272\346\263\242\345\275\242", nullptr));
        btn_ch1->setText(QApplication::translate("lion_assistant", "CH1", nullptr));
        label_slider_vertical->setText(QApplication::translate("lion_assistant", "\345\236\202\347\233\264\347\274\251\346\224\276", nullptr));
        btn_ch3->setText(QApplication::translate("lion_assistant", "CH3", nullptr));
        btn_oscilClear->setText(QApplication::translate("lion_assistant", "\346\270\205\347\251\272\346\225\260\346\215\256", nullptr));
        label_slider_vertical_2->setText(QApplication::translate("lion_assistant", "\346\260\264\345\271\263\347\274\251\346\224\276", nullptr));
        btn_ch2->setText(QApplication::translate("lion_assistant", "CH2", nullptr));
        btn_zeroOffset->setText(QApplication::translate("lion_assistant", "\345\237\272\347\272\277\345\275\222\351\233\266", nullptr));
        btn_iconCh1->setText(QString());
        btn_iconCh2->setText(QString());
        btn_iconCh3->setText(QString());
        btn_iconCh4->setText(QString());
        btn_referLine->setText(QApplication::translate("lion_assistant", "\346\230\276\347\244\272\345\237\272\347\272\277", nullptr));
        cb_selectAllChannel->setText(QString());
        tx_option1->setPlainText(QString());
        cb_option1->setText(QApplication::translate("lion_assistant", "\351\231\204\345\212\240\346\225\260\346\215\2561", nullptr));
        cb_option2->setText(QApplication::translate("lion_assistant", "\351\231\204\345\212\240\346\225\260\346\215\2562", nullptr));
        btn_Mark->setText(QApplication::translate("lion_assistant", "\346\224\266\350\227\217", nullptr));
        btn_SendPID->setText(QApplication::translate("lion_assistant", "\345\217\221\351\200\201", nullptr));
        label_Ivalue->setText(QApplication::translate("lion_assistant", "I", nullptr));
        label_Pvalue->setText(QApplication::translate("lion_assistant", "P", nullptr));
        label_value->setText(QApplication::translate("lion_assistant", "D", nullptr));
        btn_exportMark->setText(QApplication::translate("lion_assistant", "\345\257\274\345\205\245", nullptr));
        btn_importMark->setText(QApplication::translate("lion_assistant", "\345\257\274\345\207\272", nullptr));
        btn_clearMark->setText(QApplication::translate("lion_assistant", "\346\270\205\347\251\272", nullptr));
        btn_Send->setText(QApplication::translate("lion_assistant", "\345\217\221\351\200\201", nullptr));
        groupBox_3->setTitle(QApplication::translate("lion_assistant", "\345\217\221\351\200\201\350\256\276\347\275\256", nullptr));
        rdb_HexadecimalSend->setText(QApplication::translate("lion_assistant", "Hex", nullptr));
        radioButton_5->setText(QApplication::translate("lion_assistant", "ASCII", nullptr));
        cb_AutoSent->setText(QApplication::translate("lion_assistant", "\350\207\252\345\212\250\345\217\221\351\200\201\346\227\266\351\227\264\351\227\264\351\232\224", nullptr));
        label_8->setText(QApplication::translate("lion_assistant", "ms", nullptr));
        btn_Clear->setText(QApplication::translate("lion_assistant", "\346\270\205\351\231\244\346\225\260\346\215\256", nullptr));
        groupBox_2->setTitle(QApplication::translate("lion_assistant", "\346\216\245\346\224\266\350\256\276\347\275\256", nullptr));
        rdb_ASCIIDisp->setText(QApplication::translate("lion_assistant", "ASCII", nullptr));
        rdb_HexDisp->setText(QApplication::translate("lion_assistant", "Hex", nullptr));
        cb_AutoNewLine->setText(QApplication::translate("lion_assistant", "\350\207\252\345\212\250\346\215\242\350\241\214", nullptr));
        cb_ShowTx->setText(QApplication::translate("lion_assistant", "\346\230\276\347\244\272\345\217\221\351\200\201", nullptr));
        cb_ShowTime->setText(QApplication::translate("lion_assistant", "\346\230\276\347\244\272\346\227\266\351\227\264", nullptr));
        cb_DoubleColor->setText(QApplication::translate("lion_assistant", "\345\217\214\350\211\262\346\230\276\347\244\272\346\224\266\345\217\221", nullptr));
        cb_ShowRx->setText(QApplication::translate("lion_assistant", "\346\230\276\347\244\272\346\216\245\346\224\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lion_assistant: public Ui_lion_assistant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LION_ASSISTANT_H
