#include "DispatchManager.hpp"
#include <vector>
#include "Channel.hpp"
#include "Mode.hpp"
#include "HighPerformanceMode.hpp"
#include "LowPowerMode.hpp"
#include "HighEfficiencyMode.hpp"
#include "NeuralNetworkAdapter.hpp"
#include "Executor.hpp"
#include "ClassificationResult.hpp"
#include "ImageFacade.hpp" 
#include "ResultFacade.hpp"
#include "Executor.hpp"
#include "MatrixDefine.hpp"

#include <inference_engine.hpp>
#include <ie_core.hpp>
#include <opencv2/opencv.hpp>
#include <CL/cl2.hpp>

//DispatchManager::DispatchManager() {}
//DispatchManager::DispatchManager(DispatchManager const& copy); //not implemented
//DispatchManager::DispatchManager& operator=(DispatchManager const& copy); //not implemented

DispatchManager &DispatchManager::getInstance()
{
	static DispatchManager instance;
    return instance;
}

Mode* DispatchManager::getMode() { return mode; }

void DispatchManager::setMode(Mode *operatingMode) { this->mode = operatingMode; }

void DispatchManager::setNeuralNetworkList(std::vector<NeuralNetworkAdapter> neuralNetworkList) { this->neuralNetworkList = neuralNetworkList; }

std::vector<NeuralNetworkAdapter> DispatchManager::getNeuralNetworkList() { return neuralNetworkList; }

std::list<Mode*> DispatchManager::getModeList() 
{
	std::list<Mode*> modeList;
    modeList.push_back(new LowPowerMode());
    modeList.push_back(new HighEfficiencyMode());
    modeList.push_back(new HighPerformanceMode());
	return modeList;
}

ResultManager DispatchManager::dispatchImages(std::vector<std::string> directories) 
{
  	std::list<Result*> resultList;
    ImageFacade* imagefacade = new ImageFacade();
    ResultFacade* resultfacade = new ResultFacade();
    cv::Mat image;
    TENSOR(float) currentInput;
    TENSOR(float) output;
    Executor* executor;
    for (int i = 0; i < neuralNetworkList.size(); i++) {
      for (int j = 0; j < directories.size(); j++) {
        image = imagefacade->getImage(directories[j], neuralNetworkList[i].getWidth(), neuralNetworkList[i].getHeight(), neuralNetworkList[i].getChannels());
        std::cout<<"loaded image" << std::endl;
        std::vector<cv::Mat> images = std::vector<cv::Mat>();
        images.push_back(image);
        currentInput = imagefacade->createImageTensor( images, neuralNetworkList[i].getWidth(), neuralNetworkList[i].getHeight());
        std::cout<<"OK"<<std::endl;
        executor = new Executor(&neuralNetworkList[i]);
        output = executor->execute(currentInput);
        Result* newres = resultfacade->parseClassificationResult(directories[j], neuralNetworkList[i].getName(), neuralNetworkList[i].getLabels(), output[0][0][0]);
        resultList.push_back(newres);
      }
    }
  	ResultManager resultMgr = ResultManager(resultList);
  	return resultMgr;
}

std::vector<Device> DispatchManager::getAvailableDevices() {
	std::vector<Device> devices;
    Device cpu = Device("CPU", "generic cpu", 24, 1.0);
	std::vector<cl::Platform> platforms;
	cl::Platform::get(&platforms);
	for (auto &p : platforms) {
		std::string platver = p.getInfo<CL_PLATFORM_VERSION>();
		if (platver.find("OpenCL 2.") != std::string::npos) {
			devices.push_back(Device(p.getInfo<CL_PLATFORM_PROFILE>(), p.getInfo<CL_PLATFORM_NAME>(), 24, 1.0));
		}
	}
	InferenceEngine::Core core;
	std::vector<std::string> asicDevices= core.GetAvailableDevices();
    for(std::vector<std::string>::iterator it = asicDevices.begin(); it != asicDevices.end(); ++it) {
            devices.push_back(Device(*it,*it,24,1.0));
    }
    return devices;
}
