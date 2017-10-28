#include "widget.h"
#include "ui_widget.h"
#include <QDir>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //程序路径
    myProcess = new QProcess(this);
    program =  QDir::currentPath()+QDir::separator()+"openjtag"+QDir::separator()+"oflash.exe";
    setView();

    connect(ui->openFile_2410,SIGNAL(clicked(bool)),this,SLOT(browser_2410()));
    connect(ui->burn_2410,SIGNAL(clicked(bool)),this,SLOT(burn_2410()));
    connect(ui->openFile_2440,SIGNAL(clicked(bool)),this,SLOT(browser_2440()));
    connect(ui->burn_2440,SIGNAL(clicked(bool)),this,SLOT(burn_2440()));
    connect(ui->openFile_6410,SIGNAL(clicked(bool)),this,SLOT(browser_6410()));
    connect(ui->burn_6410,SIGNAL(clicked(bool)),this,SLOT(burn_6410()));
    connect(myProcess,SIGNAL(finished(int)),this,SLOT(FinishSlot(int)));
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

void Widget::burn_2410()
{
    QStringList arguments;
    if(ui->storagePath_2410->currentIndex() == 0) //Nand Flash
    {
        arguments<<"0"<<"0"<<"0"<<"0"<<"0"<<ui->filePath_2410->toPlainText();
    }
    else  //Nor Flash
    {
        arguments<<"0"<<"0"<<"1"<<"0"<<"0"<<ui->filePath_2410->toPlainText();
    }

    if(myProcess != NULL && program != NULL)
    {
        myProcess->start(program, arguments);
    }
    qDebug() <<myProcess->readAllStandardOutput();
}

void Widget::browser_2440()
{
    QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择要烧录的文件"),"D:\\");
    ui->filePath_2440->setText(fileName);
}

void Widget::burn_2440()
{
    QStringList arguments;
    if(ui->storagePath_2440->currentIndex() == 0) //Nand Flash
    {
        arguments<<"0"<<"1"<<"0"<<"0"<<"0"<<ui->filePath_2440->toPlainText();
    }
    else  //Nor Flash
    {
        arguments<<"0"<<"1"<<"1"<<"0"<<"0"<<ui->filePath_2440->toPlainText();
    }

    if(myProcess != NULL && program != NULL)
    {
        myProcess->start(program, arguments);
    }
    //myProcess->waitForFinished();
    //qDebug() <<myProcess->readAllStandardOutput();
}

void Widget::browser_6410()
{
    QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择要烧录的文件"),"D:\\");
    ui->filePath_6410->setText(fileName);
}

void Widget::burn_6410()
{
    QStringList arguments;
    if(ui->storagePath_6410->currentIndex() == 0) //Nand Flash
    {
        arguments<<"0"<<"2"<<"0"<<"0"<<"0"<<ui->filePath_6410->toPlainText();
    }
    else  //Nor Flash
    {
        arguments<<"0"<<"2"<<"1"<<"0"<<"0"<<ui->filePath_6410->toPlainText();
    }

    if(myProcess != NULL && program != NULL)
    {
        myProcess->start(program, arguments);
    }
}

void Widget::FinishSlot(int value)
{
    qDebug() <<myProcess->readAllStandardOutput();
    QMessageBox::about(this,QStringLiteral("烧录完成"),QStringLiteral("烧录完成！"));
}
