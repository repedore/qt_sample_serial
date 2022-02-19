#include "profilecontrol.h"
#include "ui_profilecontrol.h"

ProfileControl::ProfileControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfileControl)
{
    ui->setupUi(this);
}

ProfileControl::~ProfileControl()
{
    delete ui;
}

void ProfileControl::on_pushButton_clicked()
{
    emit send(ui->lineEdit->text());
}

