#ifndef DEBUGGING_H
#define DEBUGGING_H

#include <QWidget>

namespace Ui {
class Debugging;
}

class Debugging : public QWidget
{
    Q_OBJECT

public:
    explicit Debugging(QWidget *parent = nullptr);
    ~Debugging();

Q_SIGNALS:
    void send(QString str);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Debugging *ui;
};

#endif // DEBUGGING_H
