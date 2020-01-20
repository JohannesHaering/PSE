/********************************************************************************
** Form generated from reading UI file 'topology.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPOLOGY_H
#define UI_TOPOLOGY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Topology
{
public:
    QPushButton *chooseTopology;
    QPushButton *saveVisualisation;
    QLabel *topologyGraphic;

    void setupUi(QDialog *Topology)
    {
        if (Topology->objectName().isEmpty())
            Topology->setObjectName(QString::fromUtf8("Topology"));
        Topology->resize(757, 528);
        chooseTopology = new QPushButton(Topology);
        chooseTopology->setObjectName(QString::fromUtf8("chooseTopology"));
        chooseTopology->setGeometry(QRect(180, 60, 321, 61));
        saveVisualisation = new QPushButton(Topology);
        saveVisualisation->setObjectName(QString::fromUtf8("saveVisualisation"));
        saveVisualisation->setGeometry(QRect(180, 360, 321, 61));
        topologyGraphic = new QLabel(Topology);
        topologyGraphic->setObjectName(QString::fromUtf8("topologyGraphic"));
        topologyGraphic->setGeometry(QRect(130, 150, 541, 191));

        retranslateUi(Topology);

        QMetaObject::connectSlotsByName(Topology);
    } // setupUi

    void retranslateUi(QDialog *Topology)
    {
        Topology->setWindowTitle(QApplication::translate("Topology", "Dialog", nullptr));
        chooseTopology->setText(QApplication::translate("Topology", "Choose Topology to show", nullptr));
        saveVisualisation->setText(QApplication::translate("Topology", "Save Visualisation", nullptr));
        topologyGraphic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Topology: public Ui_Topology {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPOLOGY_H
