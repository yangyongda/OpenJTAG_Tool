#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setView();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setView()
{
    setWindowTitle("OpenJTAG Tool");
    //设置为固定宽高
    this->setMinimumWidth(590);
    this->setMaximumWidth(590);
    this->setMinimumHeight(400);
    this->setMaximumHeight(400);
}
