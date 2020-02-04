#ifndef OBJECTDETECTIONINFERENCEPAGE_H
#define OBJECTDETECTIONINFERENCEPAGE_H
#include "InferencePage.hpp"
#include <QDialog>

namespace Ui {
class ObjectDetectionInferencePage;
}

class ObjectDetectionInferencePage : public QDialog
{
    Q_OBJECT

public:
    explicit ObjectDetectionInferencePage(QWidget *parent = nullptr);
    ~ObjectDetectionInferencePage();
    int getOperatingMode();
    std::vector<Device> getDevices();
    int getInputMode();
    std::string getNeuralNetworkPath();
    bool getAppendResult();
    void setDevices(std::vector<Device>* devices);
    bool getShowResults();
    bool getSaveResults();
    void nextNNEnable(bool flag);
    void prevNNEnable(bool flag);
    void nextImageEnable(bool flag);
    void prevImageEnable(bool flag);
    void saveResultEnable(bool flag);
    void setPowerPrediction(float amount);
    void setPerformancePrediction(float amount);
    void startEnable(bool flag);
    void update();
    void resultsChanged(std::string nnName, std::string imgName, std::string imgPath, std::string resultPath);
    std::string getImageAmount();
private slots:
private:
    Ui::ObjectDetectionInferencePage *ui;
};

#endif // OBJECTDETECTIONINFERENCEPAGE_H
