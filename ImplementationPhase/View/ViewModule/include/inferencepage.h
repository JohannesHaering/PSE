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
<<<<<<< HEAD
    std::string getOperatingMode();
    std::vector<Device> getDevices();
    void setDevices(std::vector<Device>* devices);
    std::string getInputMode();
    std::string getNeuralNetworkPath();
    bool getShowResults();
    bool getSaveResults();
    std::string getImageAmount();
=======
    int getOperatingMode();
    std::vector<Device> getDevices();
    void setDevices(std::vector<Device>* devices);
    int getInputMode();
    std::string getNeuralNetworkPath();
    bool getShowResults();
    bool getSaveResults();
>>>>>>> stefi_implementation
    void nextNNEnable(bool flag);
    void prevNNEnable(bool flag);
    void nextImageEnable(bool flag);
    void prevImageEnable(bool flag);
    void saveResultEnable(bool flag);
    void update();
<<<<<<< HEAD
    void resultsChanged(std::string nnName, std::string imgName, std::string imgPath, ClassificationResult result);
    //+ getInputPathes() : string[]
=======
    void resultsChanged(std::string nnName, std::string imgName, cv::Mat mat, ClassificationResult result);
>>>>>>> stefi_implementation
    bool getAppendResult();
private slots:

private:
    Ui::InferencePage *ui;
};

#endif // INFERENCEPAGE_H
