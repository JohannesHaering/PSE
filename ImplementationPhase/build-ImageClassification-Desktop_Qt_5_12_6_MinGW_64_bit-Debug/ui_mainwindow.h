/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *imageClassification;
    QPushButton *topology;
    QPushButton *training;
    QPushButton *objectDetection;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 480);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        imageClassification = new QPushButton(centralwidget);
        imageClassification->setObjectName(QString::fromUtf8("imageClassification"));
        imageClassification->setGeometry(QRect(280, 80, 211, 41));
        topology = new QPushButton(centralwidget);
        topology->setObjectName(QString::fromUtf8("topology"));
        topology->setGeometry(QRect(280, 260, 211, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        topology->setFont(font);
        training = new QPushButton(centralwidget);
        training->setObjectName(QString::fromUtf8("training"));
        training->setGeometry(QRect(280, 200, 211, 41));
        objectDetection = new QPushButton(centralwidget);
        objectDetection->setObjectName(QString::fromUtf8("objectDetection"));
        objectDetection->setGeometry(QRect(280, 140, 211, 41));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 160, 75, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        imageClassification->setText(QApplication::translate("MainWindow", "Image Classification", nullptr));
        topology->setText(QApplication::translate("MainWindow", "Topology", nullptr));
        training->setText(QApplication::translate("MainWindow", "Training", nullptr));
        objectDetection->setText(QApplication::translate("MainWindow", "Object Detection", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "render", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
