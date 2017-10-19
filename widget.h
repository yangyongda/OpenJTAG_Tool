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
};

#endif // WIDGET_H
