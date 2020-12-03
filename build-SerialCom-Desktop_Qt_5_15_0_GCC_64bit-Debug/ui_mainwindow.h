/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *comPort;
    QPlainTextEdit *message;
    QPushButton *openPortBtn;
    QLabel *label;
    QLabel *label_3;
    QPushButton *closePortBtn;
    QPushButton *sendBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(377, 258);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        comPort = new QComboBox(centralwidget);
        comPort->setObjectName(QString::fromUtf8("comPort"));
        comPort->setGeometry(QRect(100, 10, 79, 26));
        message = new QPlainTextEdit(centralwidget);
        message->setObjectName(QString::fromUtf8("message"));
        message->setGeometry(QRect(100, 60, 251, 111));
        openPortBtn = new QPushButton(centralwidget);
        openPortBtn->setObjectName(QString::fromUtf8("openPortBtn"));
        openPortBtn->setGeometry(QRect(200, 10, 80, 26));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 71, 18));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 60, 58, 18));
        closePortBtn = new QPushButton(centralwidget);
        closePortBtn->setObjectName(QString::fromUtf8("closePortBtn"));
        closePortBtn->setGeometry(QRect(290, 10, 80, 26));
        sendBtn = new QPushButton(centralwidget);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));
        sendBtn->setGeometry(QRect(170, 180, 80, 26));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 377, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        openPortBtn->setText(QCoreApplication::translate("MainWindow", "Open Port", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "COM PORT", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Message", nullptr));
        closePortBtn->setText(QCoreApplication::translate("MainWindow", "Close Port", nullptr));
        sendBtn->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
