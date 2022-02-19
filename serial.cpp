#include "serial.h"
#include "qdebug.h"

#include "settingsdialog.h"

Serial::Serial(QObject *parent):
    QObject(parent),
    m_settings(new SettingsDialog),
    m_serial(new QSerialPort(this))
{

}

Serial::~Serial()
{
    delete m_settings;
}

void Serial::sendSerial(QString str)
{
    qDebug() << str;
    m_serial->write(str.toLocal8Bit());
}

void Serial::openSerialPort()
{
    const SettingsDialog::Settings p = m_settings->settings();
    m_serial->setPortName(p.name);
    m_serial->setBaudRate(p.baudRate);
    m_serial->setDataBits(p.dataBits);
    m_serial->setParity(p.parity);
    m_serial->setStopBits(p.stopBits);
    m_serial->setFlowControl(p.flowControl);
    if (m_serial->open(QIODevice::ReadWrite)) {
//        m_console->setEnabled(true);
//        m_console->setLocalEchoEnabled(p.localEchoEnabled);
//        m_ui->actionConnect->setEnabled(false);
//        m_ui->actionDisconnect->setEnabled(true);
//        m_ui->actionConfigure->setEnabled(false);
//        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
//                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
//                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
    } else {
//        QMessageBox::critical(this, tr("Error"), m_serial->errorString());

//        showStatusMessage(tr("Open error"));
    }
}

void Serial::show()
{
    m_settings->show();
}
