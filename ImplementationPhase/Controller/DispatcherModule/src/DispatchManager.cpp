#include "DispatchManager.hpp"
#include "Channel.hpp"
#include "Mode.hpp"
#include "NeuralNetworkAdapter.hpp"
//#include "Device.hpp"

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

void DispatchManager::setNeuralNetworkList(std::list<NeuralNetworkAdapter> neuralNetworkList) { this->neuralNetworkList = neuralNetworkList; }

std::list<NeuralNetworkAdapter> DispatchManager::getNeuralNetworkList() { return neuralNetworkList; }

std::list<Mode*> DispatchManager::getModeList() 
{
	//TODO
	std::list<Mode*> modeList;
	return modeList;
}

ResultManager DispatchManager::dispatchImages(std::list<cv::Mat> imageList) 
{
	//TODO
	std::list<Result> resultList;
	ResultManager resultMgr(resultList);
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
