#include "DispatchManager.hpp"
#include <vector>
#include "Channel.hpp"
#include "Mode.hpp"
#include "HighPerformanceMode.hpp"
#include "LowPowerMode.hpp"
#include "HighEfficiencyMode.hpp"
#include "NeuralNetworkAdapter.hpp"
#include "Executor.hpp"
//#include "Device.hpp"
#include "ClassificationResult.hpp"
#include "ImageFacade.hpp" 
#include "ResultFacade.hpp"

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
	//Todo ? I guess it's done for now
	std::list<Mode*> modeList;
    modeList.push_back(new LowPowerMode());
    modeList.push_back(new HighEfficiencyMode());
    modeList.push_back(new HighPerformanceMode());
	return modeList;
}

ResultManager DispatchManager::dispatchImages(std::vector<std::string> directories) 
{
	//TODO
  	std::list<Result*> resultList;
    std::vector<std::vector<floats>> inputimages;
    ImageFacade* imagefacade = new ImageFacade();
    ResultFacade* resultfacade = new ResultFacade();
    cv::Mat currentImage;
    std::list<std::string> labels = std::list<std::string>{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    std::vector<float> currentInputVecotor;
    std::vector<float> outputvector;
    Executor executor;
    for (int i = 0; i < neuralNetworks.size(); i++) {
      for (int j = 0; j < directories.size(); j++) {
        currentImage = imagefacade.getImage(directories[j], neuralNetworks[i].getWidth(), neuralNetworks[i].getHeight(), neuralNetwork[i].getChannels());
        currentInputVector = imagefacade.parseFloatsGreyScale(currentImage);
        executor = new Executor(neuralNetworks[i]);
        outputvector = executor->execute(currentInputVector);
        Result* newres = resultFacade->parseClassificationResult(directories[j], neuralNetworkList[i].getName(), labels, outputvector);
        resultList.push_back(newres);
        std::cout<<outputvector[0] + "," + outputvector[1];
      }
    }
  	ResultManager resultMgr = ResultManager(resultList);
  	return resultMgr;
}

std::vector<Device> DispatchManager::getAvailableDevices() {
    //TODO
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
    return devices;
}
