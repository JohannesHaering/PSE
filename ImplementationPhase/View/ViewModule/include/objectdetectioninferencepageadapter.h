#ifndef OBJECTDETECTIONINFERENCEPAGEADAPTER_H
#define OBJECTDETECTIONINFERENCEPAGEADAPTER_H
#include "inferencepageadapter.h"
#include "objectdetectioninferencepage.h"

class ObjectDetectionInferencePageAdapter : public InferencePageAdapter
{
public:
    ObjectDetectionInferencePageAdapter();
    std::string getOperatingMode();
    std::vector<Device> getDevices();
    void setDevices(std::vector<Device>* devices);
    std::string getInputMode();
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
    void update();
    void resultsChanged(std::string nnName, std::string imgName, std::string imgPath, std::string resultPath);
private:
    ObjectDetectionInferencePage* inferPage;
};

#endif // OBJECTDETECTIONINFERENCEPAGEADAPTER_H
