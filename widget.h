#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QProcess>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    void setView();
    QString program;
    QProcess * myProcess;

private slots:
    void browser_2410();
    void burn_2410();
    void browser_2440();
    void burn_2440();
    void browser_6410();
    void burn_6410();
    void FinishSlot(int);

};

#endif // WIDGET_H
