#include "settingdialog.h"
#include "ui_settingdialog.h"
#include <QSerialPort>
SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    ui->comboBox_2->setCurrentIndex(1);
}

SettingDialog::~SettingDialog()
{
    delete ui;
}

SettingDialog::Settings SettingDialog::settings()
{
    Settings setting;
    setting.name = ui->comboBox->currentText();
    if(ui->comboBox_2->currentText()=="19200")
    setting.baudRate = QSerialPort::Baud19200;
    setting.flowControl = QSerialPort::NoFlowControl;
    setting.dataBits = QSerialPort::Data7;
    setting.parity = QSerialPort::OddParity;
    setting.stopBits = QSerialPort::OneStop;
    return setting;
}
