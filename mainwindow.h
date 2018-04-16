#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
class QSerialPort;
class SettingDialog;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton *btnCOM;
    QPlainTextEdit *console;
    QSerialPort *sport;

    SettingDialog *mSettingDialog;

    QLabel *mode;
    QLabel *modeValue;
    QLabel *value;
    QLCDNumber *number3;
    QLCDNumber *number2;
    QLCDNumber *number1;
    QLCDNumber *number0;

private slots:
    void setCOM();
    void readData();
    void closeCOM();
    void clearConsole();
    void showSettingDialog();
};

#endif // MAINWINDOW_H
