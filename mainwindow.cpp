#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QtWidgets>
#include <SettingDialog/settingdialog.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),mSettingDialog(new SettingDialog(this))
{
    ui->setupUi(this);
       QVBoxLayout *lBox = new QVBoxLayout;
       QVBoxLayout *rBox = new QVBoxLayout;
       QHBoxLayout *hBox = new QHBoxLayout;
       QHBoxLayout *lcdBox = new QHBoxLayout;
       mode = new QLabel("Режим: ");
       modeValue = new QLabel;
       number0 = new QLCDNumber;
       number1 = new QLCDNumber;
       number2 = new QLCDNumber;
       number3 = new QLCDNumber;
       number0->setStyleSheet("background : lightgreen; color : black;");
       number1->setStyleSheet("background : lightgreen; color : black;");
       number2->setStyleSheet("background : lightgreen; color : black;");
       number3->setStyleSheet("background : lightgreen; color : black;");
       number0->setSegmentStyle(QLCDNumber::Flat);
       number1->setSegmentStyle(QLCDNumber::Flat);
       number2->setSegmentStyle(QLCDNumber::Flat);
       number3->setSegmentStyle(QLCDNumber::Flat);
       value = new QLabel("Значение: ");
       lcdBox->addWidget(number3);
       lcdBox->addWidget(number2);
       lcdBox->addWidget(number1);
       lcdBox->addWidget(number0);
       lBox->addWidget(mode);
       rBox->addWidget(modeValue);
       lBox->addWidget(value);
       rBox->addLayout(lcdBox);

       hBox->addLayout(lBox);
       hBox->addLayout(rBox);
       hBox->addStretch();



       console = new QPlainTextEdit;

       sport = new QSerialPort;
       QVBoxLayout *mainLayout = new QVBoxLayout;
       centralWidget()->setLayout(mainLayout);
       mainLayout->addLayout(hBox);
       mainLayout->addWidget(console);

       ui->disconnect_action->setEnabled(false);

       connect(ui->connect_action,SIGNAL(triggered()),this,SLOT(setCOM()));
       connect(ui->disconnect_action,SIGNAL(triggered()),this,SLOT(closeCOM()));
       connect(ui->clear_action,SIGNAL(triggered()),this,SLOT(clearConsole()));
       connect(ui->settings_action,SIGNAL(triggered()),this,SLOT(showSettingDialog()));
       connect(ui->exit_action,SIGNAL(triggered()),this,SLOT(close()));

       connect(sport,SIGNAL(readyRead()),this,SLOT(readData()));

       setWindowTitle("APPA 73");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setCOM()
{   SettingDialog::Settings setting = mSettingDialog->settings();
    sport->setPortName(setting.name);
    sport->setBaudRate(setting.baudRate);

    sport->setDataBits(setting.dataBits);
    sport->setParity(setting.parity);
    sport->setStopBits(setting.stopBits);
    sport->setFlowControl(setting.flowControl);
    if(sport->open(QIODevice::ReadWrite))
    {
        ui->statusBar->showMessage("Порт успешно открыт!");
    }
    else
    {
        ui->statusBar->showMessage("Не удалось открыть порт");
    }
    ui->disconnect_action->setEnabled(true);
    ui->connect_action->setEnabled(false);
}

void MainWindow::readData()
{
    const QByteArray data = sport->readAll();
    console->insertPlainText(data);
    QScrollBar *sb = console->verticalScrollBar();
    sb->setValue(sb->maximum());
    switch(data[5])
    {
    case 59: modeValue->setText("Voltage");
        break;
    case 61: modeValue->setText("μA Current");
        break;
    case 63: modeValue->setText("mA Current");
        break;
    case 48: modeValue->setText("Auto A current");
        break;
    case 57: modeValue->setText("Manual A Current");
        break;
    case 51: modeValue->setText("Сопротивление");
        break;
    case 53:modeValue->setText("Continuity");
        break;
    case 49: modeValue->setText("Diode");
        break;
    case 50: modeValue->setText("Frequency");
        break;
    case 54: modeValue->setText("Capacitor");
        break;
    case 52: modeValue->setText("Temperature");
        break;
    case 62: modeValue->setText("ADP0");
        break;
    case 60: modeValue->setText("ADP1");
        break;
    case 56: modeValue->setText("ADP2");
        break;
    case 58: modeValue->setText("ADP3");
    default: modeValue->setText("None");
    }

    switch(data[4])
    {
    case 48: number0->display(0);
        break;
    case 49: number0->display(1);
        break;
    case 50: number0->display(2);
        break;
    case 51: number0->display(3);
        break;
    case 52: number0->display(4);
        break;
    case 53: number0->display(5);
        break;
    case 54: number0->display(6);
        break;
    case 55: number0->display(7);
        break;
    case 56: number0->display(8);
        break;
    case 57: number0->display(9);
        break;

    }
    switch(data[3])
    {
    case 48: number1->display(0);
        break;
    case 49: number1->display(1);
        break;
    case 50: number1->display(2);
        break;
    case 51: number1->display(3);
        break;
    case 52: number1->display(4);
        break;
    case 53: number1->display(5);
        break;
    case 54: number1->display(6);
        break;
    case 55: number1->display(7);
        break;
    case 56: number1->display(8);
        break;
    case 57: number1->display(9);
        break;

    }
    switch(data[2])
    {
    case 48: number2->display(0);
        break;
    case 49: number2->display(1);
        break;
    case 50: number2->display(2);
        break;
    case 51: number2->display(3);
        break;
    case 52: number2->display(4);
        break;
    case 53: number2->display(5);
        break;
    case 54: number2->display(6);
        break;
    case 55: number2->display(7);
        break;
    case 56: number2->display(8);
        break;
    case 57: number2->display(9);
        break;

    }
    switch(data[1])
    {
    case 48: number3->display(0);
        break;
    case 49: number3->display(1);
        break;
    case 50: number3->display(2);
        break;
    case 51: number3->display(3);
        break;
    case 52: number3->display(4);
        break;
    case 53: number3->display(5);
        break;
    case 54: number3->display(6);
        break;
    case 55: number3->display(7);
        break;
    case 56: number3->display(8);
        break;
    case 57: number3->display(9);
        break;

    }
}

void MainWindow::closeCOM()
{
    sport->close();
    ui->disconnect_action->setEnabled(false);
    ui->statusBar->showMessage("Порт закрыт");
    ui->connect_action->setEnabled(true);
}

void MainWindow::clearConsole()
{
    console->clear();
}

void MainWindow::showSettingDialog()
{
    mSettingDialog->show();
}
