#ifndef INFERENCEPAGEADAPTER_H
#define INFERENCEPAGEADAPTER_H
#include "inferencepage.h"
<<<<<<< HEAD
#include "classificationresult.h"
=======
>>>>>>> stefi_implementation

class InferencePageAdapter : public ContentView
{
public:
    int getOperatingMode();
    std::vector<Device> getDevices();
<<<<<<< HEAD
    std::string getInputMode();
    std::string getNeuralNetworkPath();
    bool getShowResults();
    bool getSaveResults();
    std::string getImageAmount();
=======
    int getInputMode();
    std::string getNeuralNetworkPath();
    bool getShowResults();
    bool getSaveResults();
    int getImageAmount();
>>>>>>> stefi_implementation
    void nextNNEnable(bool flag);
    void prevNNEnable(bool flag);
    void nextImageEnable(bool flag);
    void prevImageEnable(bool flag);
    void saveResultEnable(bool flag);
    InferencePageAdapter();
    InferencePage* getInferencePage();
    void setDevices(std::vector<Device>* devices);
    void update();
    bool getAppendResult();
<<<<<<< HEAD
    void resultsChanged(std::string nnName, std::string imgName, std::string imgPath, ClassificationResult result);
=======
    void resultsChanged(std::string nnName, std::string imgName, cv::Mat mat, ClassificationResult result);
>>>>>>> stefi_implementation
private:
    InferencePage* inferPage;
};

#endif // INFERENCEPAGEADAPTER_H
