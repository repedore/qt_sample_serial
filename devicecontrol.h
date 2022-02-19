#ifndef DEVICECONTROL_H
#define DEVICECONTROL_H

#include <QWidget>

namespace Ui {
class DeviceControl;
}

class DeviceControl : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceControl(QWidget *parent = nullptr);
    ~DeviceControl();

Q_SIGNALS:
    void send(QString str);

private slots:
    void on_pushButton_clicked();

private:
    Ui::DeviceControl *ui;
};

#endif // DEVICECONTROL_H
