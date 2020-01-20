/********************************************************************************
** Form generated from reading UI file 'detectioncontrolpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETECTIONCONTROLPANEL_H
#define UI_DETECTIONCONTROLPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "devicecheckboxmanager.h"

QT_BEGIN_NAMESPACE

class Ui_DetectionControlPanel
{
public:
    QCheckBox *saveResults;
    QCheckBox *showResults;
    QPushButton *addImage;
    DeviceCheckBoxManager *CheckBoxWidget;
    QCheckBox *appendResults;
    QPushButton *startObjectDet;
    QComboBox *imgAmount;
    QPushButton *chooseNeuralNetwork;
    QComboBox *mode;

    void setupUi(QWidget *DetectionControlPanel)
    {
        if (DetectionControlPanel->objectName().isEmpty())
            DetectionControlPanel->setObjectName(QString::fromUtf8("DetectionControlPanel"));
        DetectionControlPanel->resize(250, 480);
        saveResults = new QCheckBox(DetectionControlPanel);
        saveResults->setObjectName(QString::fromUtf8("saveResults"));
        saveResults->setGeometry(QRect(30, 110, 111, 41));
        showResults = new QCheckBox(DetectionControlPanel);
        showResults->setObjectName(QString::fromUtf8("showResults"));
        showResults->setGeometry(QRect(30, 80, 111, 41));
        addImage = new QPushButton(DetectionControlPanel);
        addImage->setObjectName(QString::fromUtf8("addImage"));
        addImage->setGeometry(QRect(20, 40, 161, 31));
        CheckBoxWidget = new DeviceCheckBoxManager(DetectionControlPanel);
        CheckBoxWidget->setObjectName(QString::fromUtf8("CheckBoxWidget"));
        CheckBoxWidget->setGeometry(QRect(20, 210, 141, 121));
        appendResults = new QCheckBox(DetectionControlPanel);
        appendResults->setObjectName(QString::fromUtf8("appendResults"));
        appendResults->setGeometry(QRect(30, 360, 111, 41));
        startObjectDet = new QPushButton(DetectionControlPanel);
        startObjectDet->setObjectName(QString::fromUtf8("startObjectDet"));
        startObjectDet->setGeometry(QRect(30, 412, 161, 41));
        imgAmount = new QComboBox(DetectionControlPanel);
        imgAmount->addItem(QString());
        imgAmount->addItem(QString());
        imgAmount->setObjectName(QString::fromUtf8("imgAmount"));
        imgAmount->setGeometry(QRect(20, 10, 141, 21));
        chooseNeuralNetwork = new QPushButton(DetectionControlPanel);
        chooseNeuralNetwork->setObjectName(QString::fromUtf8("chooseNeuralNetwork"));
        chooseNeuralNetwork->setGeometry(QRect(20, 160, 141, 31));
        mode = new QComboBox(DetectionControlPanel);
        mode->addItem(QString());
        mode->addItem(QString());
        mode->addItem(QString());
        mode->setObjectName(QString::fromUtf8("mode"));
        mode->setGeometry(QRect(20, 340, 141, 21));

        retranslateUi(DetectionControlPanel);

        QMetaObject::connectSlotsByName(DetectionControlPanel);
    } // setupUi

    void retranslateUi(QWidget *DetectionControlPanel)
    {
        DetectionControlPanel->setWindowTitle(QApplication::translate("DetectionControlPanel", "Form", nullptr));
        saveResults->setText(QApplication::translate("DetectionControlPanel", "Save Results", nullptr));
        showResults->setText(QApplication::translate("DetectionControlPanel", "Show Results", nullptr));
        addImage->setText(QApplication::translate("DetectionControlPanel", "Add Image", nullptr));
        appendResults->setText(QApplication::translate("DetectionControlPanel", "Append Results", nullptr));
        startObjectDet->setText(QApplication::translate("DetectionControlPanel", "Start Object Detection", nullptr));
        imgAmount->setItemText(0, QApplication::translate("DetectionControlPanel", "Single Image", nullptr));
        imgAmount->setItemText(1, QApplication::translate("DetectionControlPanel", "More Images", nullptr));

        chooseNeuralNetwork->setText(QApplication::translate("DetectionControlPanel", "Choose Neural Network", nullptr));
        mode->setItemText(0, QApplication::translate("DetectionControlPanel", "High Performance Mode", nullptr));
        mode->setItemText(1, QApplication::translate("DetectionControlPanel", "High Efficiency Mode", nullptr));
        mode->setItemText(2, QApplication::translate("DetectionControlPanel", "Low Power Consumption Mode", nullptr));

    } // retranslateUi

};

namespace Ui {
    class DetectionControlPanel: public Ui_DetectionControlPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECTIONCONTROLPANEL_H
