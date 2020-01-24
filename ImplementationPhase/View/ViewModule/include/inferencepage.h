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
    int getOperatingMode();
    std::vector<Device> getDevices();
    void setDevices(std::vector<Device>* devices);
    int getInputMode();
    std::string getNeuralNetworkPath();
    bool getShowResults();
    bool getSaveResults();
    void nextNNEnable(bool flag);
    void prevNNEnable(bool flag);
    void nextImageEnable(bool flag);
    void prevImageEnable(bool flag);
    void saveResultEnable(bool flag);
    void startEnable(bool flag);
    void update();
    void setPowerPrediction(float amount);
    void setPerformancePrediction(float amount);
    void resultsChanged(std::string nnName, std::string imgName, cv::Mat mat, ClassificationResult result);
    bool getAppendResult();
private slots:

private:
    Ui::InferencePage *ui;
};

#endif // INFERENCEPAGE_H
