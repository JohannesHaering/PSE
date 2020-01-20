/********************************************************************************
** Form generated from reading UI file 'classificationresultpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSIFICATIONRESULTPANEL_H
#define UI_CLASSIFICATIONRESULTPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClassificationResultPanel
{
public:
    QLabel *nnName;
    QLabel *imgName;
    QPushButton *prevImgButton;
    QPushButton *nextNNButton;
    QPushButton *prevNNButton;
    QPushButton *nextImgButton;
    QLabel *imageLabel;
    QLabel *resultLabel;
    QPushButton *saveResultButton;

    void setupUi(QWidget *ClassificationResultPanel)
    {
        if (ClassificationResultPanel->objectName().isEmpty())
            ClassificationResultPanel->setObjectName(QString::fromUtf8("ClassificationResultPanel"));
        ClassificationResultPanel->resize(550, 480);
        nnName = new QLabel(ClassificationResultPanel);
        nnName->setObjectName(QString::fromUtf8("nnName"));
        nnName->setGeometry(QRect(40, 10, 91, 31));
        imgName = new QLabel(ClassificationResultPanel);
        imgName->setObjectName(QString::fromUtf8("imgName"));
        imgName->setGeometry(QRect(40, 50, 81, 31));
        prevImgButton = new QPushButton(ClassificationResultPanel);
        prevImgButton->setObjectName(QString::fromUtf8("prevImgButton"));
        prevImgButton->setGeometry(QRect(50, 402, 111, 31));
        nextNNButton = new QPushButton(ClassificationResultPanel);
        nextNNButton->setObjectName(QString::fromUtf8("nextNNButton"));
        nextNNButton->setGeometry(QRect(430, 400, 111, 31));
        prevNNButton = new QPushButton(ClassificationResultPanel);
        prevNNButton->setObjectName(QString::fromUtf8("prevNNButton"));
        prevNNButton->setGeometry(QRect(310, 400, 111, 31));
        nextImgButton = new QPushButton(ClassificationResultPanel);
        nextImgButton->setObjectName(QString::fromUtf8("nextImgButton"));
        nextImgButton->setGeometry(QRect(180, 400, 111, 31));
        imageLabel = new QLabel(ClassificationResultPanel);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setGeometry(QRect(0, 110, 250, 250));
        resultLabel = new QLabel(ClassificationResultPanel);
        resultLabel->setObjectName(QString::fromUtf8("resultLabel"));
        resultLabel->setGeometry(QRect(280, 110, 250, 250));
        saveResultButton = new QPushButton(ClassificationResultPanel);
        saveResultButton->setObjectName(QString::fromUtf8("saveResultButton"));
        saveResultButton->setGeometry(QRect(230, 440, 101, 31));

        retranslateUi(ClassificationResultPanel);

        QMetaObject::connectSlotsByName(ClassificationResultPanel);
    } // setupUi

    void retranslateUi(QWidget *ClassificationResultPanel)
    {
        ClassificationResultPanel->setWindowTitle(QApplication::translate("ClassificationResultPanel", "Form", nullptr));
        nnName->setText(QString());
        imgName->setText(QString());
        prevImgButton->setText(QApplication::translate("ClassificationResultPanel", "Previous Image", nullptr));
        nextNNButton->setText(QApplication::translate("ClassificationResultPanel", "Next NN", nullptr));
        prevNNButton->setText(QApplication::translate("ClassificationResultPanel", "Previous NN", nullptr));
        nextImgButton->setText(QApplication::translate("ClassificationResultPanel", "Next Image", nullptr));
        imageLabel->setText(QString());
        resultLabel->setText(QString());
        saveResultButton->setText(QApplication::translate("ClassificationResultPanel", "Save Result", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClassificationResultPanel: public Ui_ClassificationResultPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSIFICATIONRESULTPANEL_H
