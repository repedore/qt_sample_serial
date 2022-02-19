#ifndef SERIAL_H
#define SERIAL_H

#include <QSerialPort>

class SettingsDialog;

class Serial : public QObject
{
    Q_OBJECT
public:
    Serial(QObject *parent);
    ~Serial();

public slots:
    void sendSerial(QString str);
    void openSerialPort();
    void show();

private:
    SettingsDialog *m_settings = nullptr;
    QSerialPort *m_serial = nullptr;
};

#endif // SERIAL_H
