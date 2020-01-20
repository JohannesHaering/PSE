/********************************************************************************
** Form generated from reading UI file 'render.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENDER_H
#define UI_RENDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Render
{
public:
    QPushButton *start;
    QLabel *img;
    QPushButton *save;
    QPushButton *addImage;
    QPushButton *currentImageStart;
    QPushButton *trainingbutt;
    QPushButton *trainingsss;
    QPushButton *pushButton;

    void setupUi(QDialog *Render)
    {
        if (Render->objectName().isEmpty())
            Render->setObjectName(QString::fromUtf8("Render"));
        Render->resize(1204, 556);
        start = new QPushButton(Render);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(10, 520, 121, 31));
        img = new QLabel(Render);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(30, 20, 1150, 450));
        save = new QPushButton(Render);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(150, 510, 111, 41));
        addImage = new QPushButton(Render);
        addImage->setObjectName(QString::fromUtf8("addImage"));
        addImage->setGeometry(QRect(280, 502, 111, 41));
        currentImageStart = new QPushButton(Render);
        currentImageStart->setObjectName(QString::fromUtf8("currentImageStart"));
        currentImageStart->setGeometry(QRect(430, 522, 191, 21));
        trainingbutt = new QPushButton(Render);
        trainingbutt->setObjectName(QString::fromUtf8("trainingbutt"));
        trainingbutt->setGeometry(QRect(670, 520, 75, 23));
        trainingsss = new QPushButton(Render);
        trainingsss->setObjectName(QString::fromUtf8("trainingsss"));
        trainingsss->setGeometry(QRect(810, 522, 121, 31));
        pushButton = new QPushButton(Render);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(980, 520, 75, 23));

        retranslateUi(Render);

        QMetaObject::connectSlotsByName(Render);
    } // setupUi

    void retranslateUi(QDialog *Render)
    {
        Render->setWindowTitle(QApplication::translate("Render", "Dialog", nullptr));
        start->setText(QApplication::translate("Render", "start", nullptr));
        img->setText(QApplication::translate("Render", "TextLabel", nullptr));
        save->setText(QApplication::translate("Render", "save", nullptr));
        addImage->setText(QApplication::translate("Render", "add img", nullptr));
        currentImageStart->setText(QApplication::translate("Render", "currentImgstart", nullptr));
        trainingbutt->setText(QApplication::translate("Render", "traing", nullptr));
        trainingsss->setText(QApplication::translate("Render", "damnTraining", nullptr));
        pushButton->setText(QApplication::translate("Render", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Render: public Ui_Render {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDER_H
