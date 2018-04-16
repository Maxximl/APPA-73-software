#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H
#include <QDialog>
#include <QSerialPort>
class QString;
namespace Ui {
class SettingDialog;

}

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = 0);
    ~SettingDialog();

    struct Settings {
            QString name;
            QSerialPort::BaudRate baudRate;

            QSerialPort::DataBits dataBits;

            QSerialPort::Parity parity;

            QSerialPort::StopBits stopBits;

            QSerialPort::FlowControl flowControl;

    };

private:
    Ui::SettingDialog *ui;
public:
   void getPortName();

   Settings settings();

};

#endif // SETTINGDIALOG_H
