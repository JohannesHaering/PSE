#ifndef OBJECTDETECTIONINFERENCEPAGEADAPTER_H
#define OBJECTDETECTIONINFERENCEPAGEADAPTER_H
#include "InferencePageAdapter.hpp"
#include "ObjectDetectionInferencePage.hpp"

class ObjectDetectionInferencePageAdapter : public InferencePageAdapter
{
public:
    ObjectDetectionInferencePageAdapter();
    int getOperatingMode();
    std::vector<Device> getDevices();
    void setDevices(std::vector<Device>* devices);
    int getInputMode();
    std::string getNeuralNetworkPath();
    bool getShowResults();
    bool getSaveResults();
    std::string getImageAmount();
    void nextNNEnable(bool flag);
    void prevNNEnable(bool flag);
    void nextImageEnable(bool flag);
    void prevImageEnable(bool flag);
    void saveResultEnable(bool flag);
    ObjectDetectionInferencePage* getInferPage();
    void startEnable(bool flag);
    void update();
    void setPowerPrediction(float amount);
    void setPerformancePrediction(float amount);
    void resultsChanged(std::string nnName, std::string imgName, std::string imgPath, std::string resultPath);
private:
    ObjectDetectionInferencePage* inferPage;
};

#endif // OBJECTDETECTIONINFERENCEPAGEADAPTER_H
