#include "devicecontrol.h"
#include "ui_devicecontrol.h"

DeviceControl::DeviceControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceControl)
{
    ui->setupUi(this);
}

DeviceControl::~DeviceControl()
{
    delete ui;
}

void DeviceControl::on_pushButton_clicked()
{
    emit send(ui->lineEdit->text());
}

