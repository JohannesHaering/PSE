#ifndef INFERENCEPAGE_H
#define INFERENCEPAGE_H

#include <QDialog>
#include<string>
#include "imageclassificationcontrolpanel.h"
#include "classificationresultpanel.h"
namespace Ui {
class InferencePage;
}

class InferencePage : public QDialog
{
    Q_OBJECT

public:
    explicit InferencePage(QWidget *parent = nullptr);
    ~InferencePage();
    std::string getOperatingMode();
    std::string getDevices();
    std::string getInputMode();
    std::string getNeuralNetworkPath();
    bool getShowResults();
    bool getSaveResults();

    std::string getImageAmount();
    //+ getInputPathes() : string[]
    //+ getAppendResult() : string[]
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::InferencePage *ui;
};

#endif // INFERENCEPAGE_H
