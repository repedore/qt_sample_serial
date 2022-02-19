#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QStackedWidget"

#include "serial.h"
#include "debugging.h"
#include "devicecontrol.h"
#include "profilecontrol.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Serial *serial = new Serial(this);

//    connect(m_serial, &QSerialPort::readyRead, serial, &MainWindow::readData);
    connect(ui->pushButton_connect, SIGNAL(clicked()), serial, SLOT(openSerialPort()));
    connect(ui->pushButton_setting, SIGNAL(clicked()), serial, SLOT(show()));

    Debugging *widgetDebugging = new Debugging();
    connect(widgetDebugging, SIGNAL(send(QString)), serial,SLOT(sendSerial(QString)));
    DeviceControl *widgetDeviceControl = new DeviceControl();
    connect(widgetDeviceControl, SIGNAL(send(QString)), serial,SLOT(sendSerial(QString)));
    ProfileControl *widgetProfileControl = new ProfileControl();
    connect(widgetProfileControl, SIGNAL(send(QString)), serial,SLOT(sendSerial(QString)));

    ui->stackedWidget->addWidget(widgetDebugging);
    ui->stackedWidget->addWidget(widgetDeviceControl);
    ui->stackedWidget->addWidget(widgetProfileControl);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_0_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
