#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QtSerialPort/QSerialPort"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openPortBtn_clicked();

    void on_closePortBtn_clicked();

    void on_sendBtn_clicked();

private:
    Ui::MainWindow *ui;
     QSerialPort *usbDevice;
     QSerialPortInfo *usbInfo;
     bool isSerialConnected = false;
     QString portName = "";
};
#endif // MAINWINDOW_H
