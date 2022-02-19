#include "debugging.h"
#include "ui_debugging.h"

Debugging::Debugging(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Debugging)
{
    ui->setupUi(this);
}

Debugging::~Debugging()
{
    delete ui;
}

void Debugging::on_pushButton_clicked()
{
    emit send(ui->lineEdit->text());
}

