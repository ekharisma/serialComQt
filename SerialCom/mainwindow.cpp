#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "QMessageBox"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    usbDevice = new QSerialPort(this);
    QSerialPortInfo info;
//    qDebug() << "Port info : " << info.;
    Q_FOREACH(info, QSerialPortInfo::availablePorts()) {
        ui->comPort->addItem(info.portName());
        portName = info.portName();
    }
    connect(usbDevice, SIGNAL(readyRead()), this, SLOT(isSerialDataAvailable()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readFromSerial(){
    stringBuffer += usbDevice->readLine();
    qDebug() << "String buffer : " << stringBuffer ;
}

void MainWindow::isSerialDataAvailable() {
    readFromSerial();
    if (stringBuffer.indexOf('\n') != -1) {
        qDebug() << "Message from arduino : " << stringBuffer;
        QChar parsedMessage = stringBuffer[2];
        ui->message->setPlainText(parsedMessage);
        stringBuffer = "";
    }
}

void MainWindow::on_openPortBtn_clicked()
{
    if (!isSerialConnected) {
        usbDevice->setPortName(portName);
        if (usbDevice->open(QIODevice::ReadWrite)) {
            if(!usbDevice->setBaudRate(QSerialPort::Baud9600))
                qDebug()<<usbDevice->errorString();

            if(!usbDevice->setDataBits(QSerialPort::Data8))
                qDebug()<<usbDevice->errorString();

            if(!usbDevice->setParity(QSerialPort::NoParity))
                qDebug()<<usbDevice->errorString();

            if(!usbDevice->setStopBits(QSerialPort::OneStop))
                qDebug()<<usbDevice->errorString();

            if(!usbDevice->setFlowControl(QSerialPort::NoFlowControl))
                qDebug()<<usbDevice->errorString();
            isSerialConnected = true;
            qDebug() << "Connected";
            readFromSerial();
        } else {
            QMessageBox msg;
            msg.setText(usbDevice->errorString());
            msg.exec();
        }
    } else {
        QMessageBox msg;
        msg.setText(usbDevice->errorString());
        msg.exec();
    }
}

void MainWindow::on_closePortBtn_clicked()
{
    if (isSerialConnected) {
        usbDevice->close();
        isSerialConnected = false;
        qDebug() << "Disconnected";

    }
    else {
        QMessageBox msg;
        msg.setText("No Device Connected");
    }
}

void MainWindow::on_sendBtn_clicked()
{
    QString message = ui->message->toPlainText();
    qDebug() << "Pesan : " << message;
    usbDevice->write(message.toLocal8Bit());
    qDebug() << "Pesan cvt " << message.toLocal8Bit();
}
