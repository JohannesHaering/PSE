/********************************************************************************
** Form generated from reading UI file 'training.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINING_H
#define UI_TRAINING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Training
{
public:
    QPushButton *chooseNeuralNetwork;
    QPushButton *chooseDataset;
    QPushButton *train;
    QLineEdit *learningRate;
    QLabel *learningRateLabel;
    QLineEdit *precision;
    QLineEdit *name;
    QLabel *precisionLabel;
    QLabel *desiredNameLabel;
    QComboBox *comboBox;
    QLabel *trainingGraphic;

    void setupUi(QDialog *Training)
    {
        if (Training->objectName().isEmpty())
            Training->setObjectName(QString::fromUtf8("Training"));
        Training->resize(800, 480);
        chooseNeuralNetwork = new QPushButton(Training);
        chooseNeuralNetwork->setObjectName(QString::fromUtf8("chooseNeuralNetwork"));
        chooseNeuralNetwork->setGeometry(QRect(40, 30, 171, 31));
        chooseDataset = new QPushButton(Training);
        chooseDataset->setObjectName(QString::fromUtf8("chooseDataset"));
        chooseDataset->setGeometry(QRect(40, 70, 171, 31));
        train = new QPushButton(Training);
        train->setObjectName(QString::fromUtf8("train"));
        train->setGeometry(QRect(40, 390, 171, 31));
        learningRate = new QLineEdit(Training);
        learningRate->setObjectName(QString::fromUtf8("learningRate"));
        learningRate->setGeometry(QRect(90, 200, 171, 21));
        learningRateLabel = new QLabel(Training);
        learningRateLabel->setObjectName(QString::fromUtf8("learningRateLabel"));
        learningRateLabel->setGeometry(QRect(10, 200, 71, 16));
        precision = new QLineEdit(Training);
        precision->setObjectName(QString::fromUtf8("precision"));
        precision->setGeometry(QRect(100, 230, 171, 21));
        name = new QLineEdit(Training);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(80, 260, 191, 21));
        precisionLabel = new QLabel(Training);
        precisionLabel->setObjectName(QString::fromUtf8("precisionLabel"));
        precisionLabel->setGeometry(QRect(10, 230, 91, 16));
        desiredNameLabel = new QLabel(Training);
        desiredNameLabel->setObjectName(QString::fromUtf8("desiredNameLabel"));
        desiredNameLabel->setGeometry(QRect(10, 260, 81, 16));
        comboBox = new QComboBox(Training);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(40, 120, 181, 21));
        trainingGraphic = new QLabel(Training);
        trainingGraphic->setObjectName(QString::fromUtf8("trainingGraphic"));
        trainingGraphic->setGeometry(QRect(370, 60, 381, 281));

        retranslateUi(Training);

        QMetaObject::connectSlotsByName(Training);
    } // setupUi

    void retranslateUi(QDialog *Training)
    {
        Training->setWindowTitle(QApplication::translate("Training", "Training", nullptr));
        chooseNeuralNetwork->setText(QApplication::translate("Training", "Choose Neural Network", nullptr));
        chooseDataset->setText(QApplication::translate("Training", "Choose Dataset", nullptr));
        train->setText(QApplication::translate("Training", "Train", nullptr));
        learningRate->setText(QString());
        learningRateLabel->setText(QApplication::translate("Training", "Learning Rate", nullptr));
        precision->setText(QString());
        name->setText(QString());
        precisionLabel->setText(QApplication::translate("Training", "Desired Precision", nullptr));
        desiredNameLabel->setText(QApplication::translate("Training", "Desired Name", nullptr));
        comboBox->setItemText(0, QApplication::translate("Training", "Transfer Learning", nullptr));
        comboBox->setItemText(1, QApplication::translate("Training", "Complete Learning", nullptr));

        trainingGraphic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Training: public Ui_Training {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINING_H
