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
#include "Device.hpp"
#include "DeviceType.hpp"

#include <opencv2/opencv.hpp>
#include <CL/cl2.hpp>
#include <iostream>

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
    ImageFacade* imagefacade = new ImageFacade();
    cv::Mat image;
    TENSOR(float) currentInput;
    TENSOR(float) output; std::list<Result*> resultList;
    ResultFacade* resultfacade = new ResultFacade();
    std::list<std::string> dirlist = std::list<std::string>(directories.begin(), directories.end());

    std::list<std::tuple<DeviceType, NeuralNetworkAdapter, TENSOR(float), std::vector<std::string>>> distribution = mode->getImageDistribution(dirlist);
    Executor* executor;

    for (auto it : distribution) {
      DeviceType type = std::get<0>(it);
      NeuralNetworkAdapter network = std::get<1>(it);
      TENSOR(float) input = std::get<2>(it);
      if (input.size() == 0) {
        throw std::invalid_argument( "Can't dispatch no images." );
      }
      std::vector<std::string> directories = std::get<3>(it);
      network.setMode(type);
      executor = new Executor(&network);
      output = executor->execute(input);
      for (int i = 0; i < directories.size(); i++) {
        Result* newres = resultfacade->parseClassificationResult(directories[i], network.getName(), network.getLabels(), output[i][0][0]);
        resultList.push_back(newres);
      }
    }
    /*
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
    }*/
  	  ResultManager resultMgr = ResultManager(resultList);
  /*
      std::cout << mode->getModeName() << " " << distribution.size() << std::endl;
      for (auto it : distribution) {
        std::cout << std::get<0>(it) << std::endl;
        std::cout << std::get<1>(it).getName() << std::endl;
        std::cout << std::get<2>(it).size() << std::endl;
      }*/
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
    return devices;
}
