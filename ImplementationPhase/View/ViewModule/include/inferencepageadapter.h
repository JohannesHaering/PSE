#ifndef INFERENCEPAGEADAPTER_H
#define INFERENCEPAGEADAPTER_H
#include "inferencepage.h"

class InferencePageAdapter : public ContentView
{
public:
    int getOperatingMode();
    std::vector<Device> getDevices();
    int getInputMode();
    std::string getNeuralNetworkPath();
    bool getShowResults();
    bool getSaveResults();
    int getImageAmount();
    void nextNNEnable(bool flag);
    void prevNNEnable(bool flag);
    void nextImageEnable(bool flag);
    void prevImageEnable(bool flag);
    void saveResultEnable(bool flag);
    void startEnable(bool flag);
    InferencePageAdapter();
    InferencePage* getInferencePage();
    void setDevices(std::vector<Device>* devices);
    void update();
    bool getAppendResult();
    void resultsChanged(std::string nnName, std::string imgName, cv::Mat mat, ClassificationResult result);
private:
    InferencePage* inferPage;
};

#endif // INFERENCEPAGEADAPTER_H
