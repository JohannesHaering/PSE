/********************************************************************************
** Form generated from reading UI file 'imageclassificationcontrolpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGECLASSIFICATIONCONTROLPANEL_H
#define UI_IMAGECLASSIFICATIONCONTROLPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "devicecheckboxmanager.h"

QT_BEGIN_NAMESPACE

class Ui_ImageClassificationControlPanel
{
public:
    QCheckBox *showResults;
    QComboBox *imgAmount;
    QCheckBox *saveResults;
    QPushButton *chooseNeuralNetwork;
    DeviceCheckBoxManager *CheckBoxWidget;
    QComboBox *mode;
    QCheckBox *appendResults;
    QPushButton *startImgClass;
    QPushButton *addImage;

    void setupUi(QWidget *ImageClassificationControlPanel)
    {
        if (ImageClassificationControlPanel->objectName().isEmpty())
            ImageClassificationControlPanel->setObjectName(QString::fromUtf8("ImageClassificationControlPanel"));
        ImageClassificationControlPanel->resize(250, 480);
        showResults = new QCheckBox(ImageClassificationControlPanel);
        showResults->setObjectName(QString::fromUtf8("showResults"));
        showResults->setGeometry(QRect(20, 110, 111, 41));
        imgAmount = new QComboBox(ImageClassificationControlPanel);
        imgAmount->addItem(QString());
        imgAmount->addItem(QString());
        imgAmount->setObjectName(QString::fromUtf8("imgAmount"));
        imgAmount->setGeometry(QRect(30, 20, 141, 21));
        saveResults = new QCheckBox(ImageClassificationControlPanel);
        saveResults->setObjectName(QString::fromUtf8("saveResults"));
        saveResults->setGeometry(QRect(20, 150, 111, 41));
        chooseNeuralNetwork = new QPushButton(ImageClassificationControlPanel);
        chooseNeuralNetwork->setObjectName(QString::fromUtf8("chooseNeuralNetwork"));
        chooseNeuralNetwork->setGeometry(QRect(20, 190, 141, 31));
        CheckBoxWidget = new DeviceCheckBoxManager(ImageClassificationControlPanel);
        CheckBoxWidget->setObjectName(QString::fromUtf8("CheckBoxWidget"));
        CheckBoxWidget->setGeometry(QRect(20, 230, 191, 121));
        mode = new QComboBox(ImageClassificationControlPanel);
        mode->addItem(QString());
        mode->addItem(QString());
        mode->addItem(QString());
        mode->setObjectName(QString::fromUtf8("mode"));
        mode->setGeometry(QRect(20, 360, 141, 21));
        appendResults = new QCheckBox(ImageClassificationControlPanel);
        appendResults->setObjectName(QString::fromUtf8("appendResults"));
        appendResults->setGeometry(QRect(30, 380, 111, 41));
        startImgClass = new QPushButton(ImageClassificationControlPanel);
        startImgClass->setObjectName(QString::fromUtf8("startImgClass"));
        startImgClass->setGeometry(QRect(40, 422, 161, 41));
        addImage = new QPushButton(ImageClassificationControlPanel);
        addImage->setObjectName(QString::fromUtf8("addImage"));
        addImage->setGeometry(QRect(20, 60, 161, 31));

        retranslateUi(ImageClassificationControlPanel);

        QMetaObject::connectSlotsByName(ImageClassificationControlPanel);
    } // setupUi

    void retranslateUi(QWidget *ImageClassificationControlPanel)
    {
        ImageClassificationControlPanel->setWindowTitle(QApplication::translate("ImageClassificationControlPanel", "Form", nullptr));
        showResults->setText(QApplication::translate("ImageClassificationControlPanel", "Show Results", nullptr));
        imgAmount->setItemText(0, QApplication::translate("ImageClassificationControlPanel", "Single Image", nullptr));
        imgAmount->setItemText(1, QApplication::translate("ImageClassificationControlPanel", "More Images", nullptr));

        saveResults->setText(QApplication::translate("ImageClassificationControlPanel", "Save Results", nullptr));
        chooseNeuralNetwork->setText(QApplication::translate("ImageClassificationControlPanel", "Choose Neural Network", nullptr));
        mode->setItemText(0, QApplication::translate("ImageClassificationControlPanel", "High Performance Mode", nullptr));
        mode->setItemText(1, QApplication::translate("ImageClassificationControlPanel", "High Efficiency Mode", nullptr));
        mode->setItemText(2, QApplication::translate("ImageClassificationControlPanel", "Low Power Consumption Mode", nullptr));

        appendResults->setText(QApplication::translate("ImageClassificationControlPanel", "Append Results", nullptr));
        startImgClass->setText(QApplication::translate("ImageClassificationControlPanel", "Start Image Classification", nullptr));
        addImage->setText(QApplication::translate("ImageClassificationControlPanel", "Add Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageClassificationControlPanel: public Ui_ImageClassificationControlPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGECLASSIFICATIONCONTROLPANEL_H
