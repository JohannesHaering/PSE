#ifndef DETECTIONCONTROLPANEL_H
#define DETECTIONCONTROLPANEL_H

#include <QWidget>
#include "classificationresultpanel.h"
#include "contentview.h"
#include "device.h"
namespace Ui {
class DetectionControlPanel;
}

class DetectionControlPanel : public QWidget, public ContentView
{
    Q_OBJECT

public:
    explicit DetectionControlPanel(QWidget *parent = nullptr);
    ~DetectionControlPanel();
    std::vector<Device> getDevices();
    bool getCheckBoxAppendResults();
    bool getShowResultsCheckBox();
    bool getSaveResultsCheckBox();
    std::string getNeuralNetworkPath();
    int getOperatingMode();
    std::string neuralNetworkPaths;
    std::string imagePaths;
    int getInputMode();
    std::string getImagePaths();    
    void setDevices(std::vector<Device>* devices);
    static DetectionControlPanel* getInstance();
    void startEnable(bool flag);
private slots:
    void on_addImage_clicked();

    void on_chooseNeuralNetwork_clicked();

    void on_startObjectDet_clicked();

private:
    Ui::DetectionControlPanel *ui;
};

#endif // DETECTIONCONTROLPANEL_H
