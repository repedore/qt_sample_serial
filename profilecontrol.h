#ifndef PROFILECONTROL_H
#define PROFILECONTROL_H

#include <QWidget>

namespace Ui {
class ProfileControl;
}

class ProfileControl : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileControl(QWidget *parent = nullptr);
    ~ProfileControl();

Q_SIGNALS:
    void send(QString str);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ProfileControl *ui;
};

#endif // PROFILECONTROL_H
