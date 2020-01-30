#ifndef IMAGECLASSIFICATIONCONTROLPANEL_H
#define IMAGECLASSIFICATIONCONTROLPANEL_H

#include <QWidget>
#include <string>
#include "ContentView.hpp"
#include "Device.hpp"
namespace Ui {
class ImageClassificationControlPanel;
}

class ImageClassificationControlPanel : public QWidget, public ContentView
{
    Q_OBJECT

public:
    explicit ImageClassificationControlPanel(QWidget *parent = nullptr);
    ~ImageClassificationControlPanel();
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
    static ImageClassificationControlPanel* getInstance();
    void setDevices(std::vector<Device>* devices);
    bool getAppendResult();
    void startEnable(bool flag);
    void setPowerPrediction(float amount);
    void setPerformancePrediction(float amount);
    void updateValues();
private slots:
    void on_chooseNeuralNetwork_clicked();
    void on_addImage_clicked();
    void on_startImgClass_clicked();
    void on_deviceSearch_clicked();

private:
    float powerPrediction;
    float performancePrediction;
    ContentView *contView;
    Ui::ImageClassificationControlPanel *ui;
};

#endif // IMAGECLASSIFICATIONCONTROLPANEL_H
