#ifndef OBJECTDETECTIONINFERENCEPAGEADAPTER_H
#define OBJECTDETECTIONINFERENCEPAGEADAPTER_H
#include "inferencepageadapter.h"

class ObjectDetectionInferencePageAdapter : public InferencePageAdapter
{
public:
    ObjectDetectionInferencePageAdapter();
    std::string getOperatingMode();
    std::string getDevices();
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

};

#endif // OBJECTDETECTIONINFERENCEPAGEADAPTER_H
