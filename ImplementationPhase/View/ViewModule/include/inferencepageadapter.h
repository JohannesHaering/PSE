#ifndef INFERENCEPAGEADAPTER_H
#define INFERENCEPAGEADAPTER_H
//#include "inferencepage.h"
#include <string>
#include "Device.hpp"
#include <vector>
#include "contentview.h"

class InferencePageAdapter : ContentView
{
public:
    std::string getOperatingMode();
    std::vector<Device> getDevices();
	void setDevices(std::vector<Device> devices);
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
	void startEnable(bool flag);
    InferencePageAdapter();
	void update();
    //InferencePage* getInferencePage();

};

#endif // INFERENCEPAGEADAPTER_H
