#include "widget.h"
#include "ui_widget.h"
#include <QDir>
#include <QFileDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //程序路径
    myProcess = new QProcess(this);
    program =  QDir::currentPath()+QDir::separator()+"openjtag"+QDir::separator()+"oflash";
    setView();

    connect(ui->openFile_2410,SIGNAL(clicked(bool)),this,SLOT(browser_2410()));
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

void Widget::browser_2410()
{
    QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择要烧录的文件"),"D:\\");
    ui->filePath_2410->setText(fileName);

}
