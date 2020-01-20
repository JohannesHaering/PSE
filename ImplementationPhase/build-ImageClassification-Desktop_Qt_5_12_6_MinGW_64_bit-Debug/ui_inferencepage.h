/********************************************************************************
** Form generated from reading UI file 'inferencepage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFERENCEPAGE_H
#define UI_INFERENCEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include "classificationresultpanel.h"
#include "imageclassificationcontrolpanel.h"

QT_BEGIN_NAMESPACE

class Ui_InferencePage
{
public:
    ImageClassificationControlPanel *controlPanel;
    ClassificationResultPanel *resultPanel;

    void setupUi(QDialog *InferencePage)
    {
        if (InferencePage->objectName().isEmpty())
            InferencePage->setObjectName(QString::fromUtf8("InferencePage"));
        InferencePage->resize(800, 480);
        controlPanel = new ImageClassificationControlPanel(InferencePage);
        controlPanel->setObjectName(QString::fromUtf8("controlPanel"));
        controlPanel->setGeometry(QRect(0, 0, 250, 480));
        resultPanel = new ClassificationResultPanel(InferencePage);
        resultPanel->setObjectName(QString::fromUtf8("resultPanel"));
        resultPanel->setGeometry(QRect(250, 0, 550, 480));

        retranslateUi(InferencePage);

        QMetaObject::connectSlotsByName(InferencePage);
    } // setupUi

    void retranslateUi(QDialog *InferencePage)
    {
        InferencePage->setWindowTitle(QApplication::translate("InferencePage", "Image Classification", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InferencePage: public Ui_InferencePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFERENCEPAGE_H
