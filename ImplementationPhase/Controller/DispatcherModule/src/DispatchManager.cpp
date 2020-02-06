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
    ClassProbability prob1 = ClassProbability("elefant", 0.1f);
    ClassProbability prob2 = ClassProbability("dog", 0.5f);
    ClassProbability prob3 = ClassProbability("pikachu", 0.9f);

    std::list<ClassProbability> classlist = std::list<ClassProbability>{prob1, prob2, prob3};

    ClassificationResult* res = new ClassificationResult("/home/pselabw1920/Downloads/Highlander-kitten-lying-1030x772.jpg", "das beschte netz", classlist);
    resultList.push_back(res);
    //Executor* executor = new Executor(neuralNetworkList[0], );
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
