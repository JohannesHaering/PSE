/********************************************************************************
** Form generated from reading UI file 'detectionresultpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETECTIONRESULTPANEL_H
#define UI_DETECTIONRESULTPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetectionResultPanel
{
public:
    QLabel *resultLabel;
    QPushButton *nextNNButton;
    QPushButton *prevImgButton;
    QLabel *imageLabel;
    QPushButton *prevNNButton;
    QLabel *imgName;
    QLabel *nnName;
    QPushButton *nextImgButton;
    QPushButton *saveResultsButton;

    void setupUi(QWidget *DetectionResultPanel)
    {
        if (DetectionResultPanel->objectName().isEmpty())
            DetectionResultPanel->setObjectName(QString::fromUtf8("DetectionResultPanel"));
        DetectionResultPanel->resize(550, 480);
        resultLabel = new QLabel(DetectionResultPanel);
        resultLabel->setObjectName(QString::fromUtf8("resultLabel"));
        resultLabel->setGeometry(QRect(300, 120, 231, 241));
        nextNNButton = new QPushButton(DetectionResultPanel);
        nextNNButton->setObjectName(QString::fromUtf8("nextNNButton"));
        nextNNButton->setGeometry(QRect(420, 410, 111, 31));
        prevImgButton = new QPushButton(DetectionResultPanel);
        prevImgButton->setObjectName(QString::fromUtf8("prevImgButton"));
        prevImgButton->setGeometry(QRect(30, 410, 111, 31));
        imageLabel = new QLabel(DetectionResultPanel);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setGeometry(QRect(20, 130, 241, 231));
        prevNNButton = new QPushButton(DetectionResultPanel);
        prevNNButton->setObjectName(QString::fromUtf8("prevNNButton"));
        prevNNButton->setGeometry(QRect(300, 410, 111, 31));
        imgName = new QLabel(DetectionResultPanel);
        imgName->setObjectName(QString::fromUtf8("imgName"));
        imgName->setGeometry(QRect(30, 20, 91, 31));
        nnName = new QLabel(DetectionResultPanel);
        nnName->setObjectName(QString::fromUtf8("nnName"));
        nnName->setGeometry(QRect(30, 60, 81, 31));
        nextImgButton = new QPushButton(DetectionResultPanel);
        nextImgButton->setObjectName(QString::fromUtf8("nextImgButton"));
        nextImgButton->setGeometry(QRect(170, 410, 111, 31));
        saveResultsButton = new QPushButton(DetectionResultPanel);
        saveResultsButton->setObjectName(QString::fromUtf8("saveResultsButton"));
        saveResultsButton->setGeometry(QRect(230, 442, 101, 31));

        retranslateUi(DetectionResultPanel);

        QMetaObject::connectSlotsByName(DetectionResultPanel);
    } // setupUi

    void retranslateUi(QWidget *DetectionResultPanel)
    {
        DetectionResultPanel->setWindowTitle(QApplication::translate("DetectionResultPanel", "Form", nullptr));
        resultLabel->setText(QString());
        nextNNButton->setText(QApplication::translate("DetectionResultPanel", "Next NN", nullptr));
        prevImgButton->setText(QApplication::translate("DetectionResultPanel", "Previous Image", nullptr));
        imageLabel->setText(QString());
        prevNNButton->setText(QApplication::translate("DetectionResultPanel", "Previous NN", nullptr));
        imgName->setText(QString());
        nnName->setText(QString());
        nextImgButton->setText(QApplication::translate("DetectionResultPanel", "Next Image", nullptr));
        saveResultsButton->setText(QApplication::translate("DetectionResultPanel", "Save Results", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetectionResultPanel: public Ui_DetectionResultPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECTIONRESULTPANEL_H
