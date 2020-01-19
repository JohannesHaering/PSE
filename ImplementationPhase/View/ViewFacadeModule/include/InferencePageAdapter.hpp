#ifndef INFERENCE_PAGE_H_
#define INFERENCE_PAGE_H_

#include "Device.hpp"
#include "Result.hpp"
#include <string>
#include <vector>

class InferencePageAdapter {
    public: 
        void nextNeuralNetworkButtonEnable(bool enable);
        void prevNeuralNetworkButtonEnable(bool prevenable);

        void nextImageEnable(bool enable);
        void prevImageEnable(bool prevenable);

        std::string getOperatingMode();
        std::vector<std::string> getDevices();
        int getInputMode();
        std::string getNeuralNetworkPath();
        bool getShowResults();
        bool getSaveResults();
        int getImageAmount();
        std::vector<std::string> getInputPathes();
        std::vector<std::string> getAppendResult();
        void setPowerPrediction(int amount);
        void setPerformancePrediction(int amount);
        void showPage(bool flag);
        void startButtonEnable(bool flag);
        void setResult(Result result);
        std::vector<Device> getPlatforms();
		void setDevices(std::vector<Device> devices);
        void update();
		void setActive(bool flag);
};
#endif
