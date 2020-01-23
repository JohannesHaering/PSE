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
<<<<<<< HEAD
    std::string getOperatingMode();
    std::string neuralNetworkPaths;
    std::string imagePaths;
    std::string getInputMode();
=======
    int getOperatingMode();
    std::string neuralNetworkPaths;
    std::string imagePaths;
    int getInputMode();
>>>>>>> stefi_implementation
    std::string getImagePaths();    
    void setDevices(std::vector<Device>* devices);
    static DetectionControlPanel* getInstance();
private slots:
    void on_addImage_clicked();

    void on_chooseNeuralNetwork_clicked();

    void on_startObjectDet_clicked();

private:
    Ui::DetectionControlPanel *ui;
};

#endif // DETECTIONCONTROLPANEL_H
