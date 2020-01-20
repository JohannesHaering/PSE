/********************************************************************************
** Form generated from reading UI file 'objectdetectioninferencepage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBJECTDETECTIONINFERENCEPAGE_H
#define UI_OBJECTDETECTIONINFERENCEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include "detectioncontrolpanel.h"
#include "detectionresultpanel.h"

QT_BEGIN_NAMESPACE

class Ui_ObjectDetectionInferencePage
{
public:
    DetectionControlPanel *controlPanel;
    DetectionResultPanel *resultPanel;
    QPushButton *start;

    void setupUi(QDialog *ObjectDetectionInferencePage)
    {
        if (ObjectDetectionInferencePage->objectName().isEmpty())
            ObjectDetectionInferencePage->setObjectName(QString::fromUtf8("ObjectDetectionInferencePage"));
        ObjectDetectionInferencePage->resize(800, 480);
        controlPanel = new DetectionControlPanel(ObjectDetectionInferencePage);
        controlPanel->setObjectName(QString::fromUtf8("controlPanel"));
        controlPanel->setGeometry(QRect(0, 0, 250, 480));
        resultPanel = new DetectionResultPanel(ObjectDetectionInferencePage);
        resultPanel->setObjectName(QString::fromUtf8("resultPanel"));
        resultPanel->setGeometry(QRect(250, 0, 550, 480));
        start = new QPushButton(resultPanel);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(454, 10, 91, 41));

        retranslateUi(ObjectDetectionInferencePage);

        QMetaObject::connectSlotsByName(ObjectDetectionInferencePage);
    } // setupUi

    void retranslateUi(QDialog *ObjectDetectionInferencePage)
    {
        ObjectDetectionInferencePage->setWindowTitle(QApplication::translate("ObjectDetectionInferencePage", "Object Detection", nullptr));
        start->setText(QApplication::translate("ObjectDetectionInferencePage", "start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ObjectDetectionInferencePage: public Ui_ObjectDetectionInferencePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBJECTDETECTIONINFERENCEPAGE_H
