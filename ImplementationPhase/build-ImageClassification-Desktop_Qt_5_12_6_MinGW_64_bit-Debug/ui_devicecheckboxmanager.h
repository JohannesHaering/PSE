/********************************************************************************
** Form generated from reading UI file 'devicecheckboxmanager.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICECHECKBOXMANAGER_H
#define UI_DEVICECHECKBOXMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviceCheckBoxManager
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *DeviceCheckBoxManager)
    {
        if (DeviceCheckBoxManager->objectName().isEmpty())
            DeviceCheckBoxManager->setObjectName(QString::fromUtf8("DeviceCheckBoxManager"));
        DeviceCheckBoxManager->resize(170, 118);
        scrollArea = new QScrollArea(DeviceCheckBoxManager);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 171, 121));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(false);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 152, 119));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(DeviceCheckBoxManager);

        QMetaObject::connectSlotsByName(DeviceCheckBoxManager);
    } // setupUi

    void retranslateUi(QWidget *DeviceCheckBoxManager)
    {
        DeviceCheckBoxManager->setWindowTitle(QApplication::translate("DeviceCheckBoxManager", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviceCheckBoxManager: public Ui_DeviceCheckBoxManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICECHECKBOXMANAGER_H
