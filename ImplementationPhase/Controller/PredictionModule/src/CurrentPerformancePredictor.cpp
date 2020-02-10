#include "PerformancePredictorFromFile.hpp"
#include "CurrentPerformancePredictor.hpp"
#include "Predictor.hpp"
#include "ImageFacade.hpp"
#include "NeuralNetworkFacade.hpp"
#include "NeuralNetworkAdapter.hpp"
#include "Device.hpp"
#include "Channel.hpp"
#include "CPUChannel.hpp"
#include "FPGAChannel.hpp"
#include "GPUChannel.hpp"
#include "ASICChannel.hpp"

#include <string>
#include <map>
#include <list>
#include <iostream>
#include <fstream>
#include <utility>
#include <chrono>
#include <opencv2/opencv.hpp>

std::map<std::string, float> CurrentPerformancePredictor::predict(std::list<std::string> deviceIds)
{
	std::map<std::string, float> savedValues = Predictor::predict(deviceIds);

	NeuralNetworkAdapter neuralNetwork = NeuralNetworkFacade().loadNeuralNetwork(nerualNetworkPath);
	std::list<NeuralNetworkAdapter> neuralNetworkList;
	neuralNetworkList.push_back(neuralNetwork);

	//cv::Mat image = ImageFacade().getImage(imagePath, neuralNetwork.getWidth(), neuralNetwork.getHeight(), neuralNetwork.getChannelNumb());
	cv::Mat image = ImageFacade().getImage(imagePath, *neuralNetwork.getFirstLayer()->getInputDimensions(), *neuralNetwork.getFirstLayer()->getInputDimensions(), 3);
	std::list<cv::Mat> imageList;
	imageList.push_back(image);

	std::list<std::string> cpus;
	std::list<std::string> fpgas;
	std::list<std::string> gpus;
	std::list<std::string> asics;

	int state;

	std::ifstream file(filePath);
	std::string temp;
	std::list<std::string> values;

	while (std::getline(file, temp))
	{
		if (temp.compare("CPU") == 0)
		{
			state = 0;
			continue;
		}
		if (temp.compare("FPGA") == 0)
		{
			state = 1;
			continue;
		}
		if (temp.compare("GPU") == 0)
		{
			state = 2;
			continue;
		}
		if (temp.compare("ASIC") == 0)
		{
			state = 3;
			continue;
		}

		if (state == 0)
		{
			cpus.push_back(temp);
		}
		if (state == 1)
		{
			fpgas.push_back(temp);
		}
		if (state == 2)
		{
			gpus.push_back(temp);
		}
		if (state == 3)
		{
			asics.push_back(temp);
		}
	}
	file.close();

	std::map<std::string, float> cpuMap = Predictor::parseToFloat(cpus);
	std::map<std::string, float> fpgaMap = Predictor::parseToFloat(fpgas);
	std::map<std::string, float> gpuMap = Predictor::parseToFloat(gpus);
	std::map<std::string, float> asicMap = Predictor::parseToFloat(asics);

	std::list<Device> devices;

	// Create devices
	for (auto it = deviceIds.begin(); it != deviceIds.end(); ++it)
	{
		if (cpuMap.find(*it) != cpuMap.end())
		{
			devices.push_back(Device(*it, "CPU", 0, 0));
			continue;
		}
		if (fpgaMap.find(*it) != fpgaMap.end())
		{
			devices.push_back(Device(*it, "FPGA", 0, 0));
			continue;
		}
		if (gpuMap.find(*it) != gpuMap.end())
		{
			devices.push_back(Device(*it, "GPU", 0, 0));
			continue;
		}
		if (asicMap.find(*it) != asicMap.end())
		{
			devices.push_back(Device(*it, "ASIC", 0, 0));
			continue;
		}
	}

	// Make test classification and count the time for that
	for (auto it = devices.begin(); it != devices.end(); ++it)
	{
		// Create device speficic channel
		Channel* currentChannel;
		if (it->getType().compare("CPU") == 0)
		{
			currentChannel = (Channel*) new CPUChannel(*it, neuralNetworkList);
			cpuMap.find((*it).getName())->second = measureTime(currentChannel, neuralNetworkList, imageList);
		}
		if (it->getType().compare("FPGA") == 0)
		{
			currentChannel = (Channel*) new FPGAChannel(*it, neuralNetworkList);
			fpgaMap.find((*it).getName())->second = measureTime(currentChannel, neuralNetworkList, imageList);
		}
		if (it->getType().compare("GPU") == 0)
		{
			currentChannel = (Channel*) new GPUChannel(*it, neuralNetworkList);
			gpuMap.find((*it).getName())->second = measureTime(currentChannel, neuralNetworkList, imageList);
		}
		if (it->getType().compare("ASIC") == 0)
		{
			currentChannel = (Channel*) new ASICChannel(*it, neuralNetworkList);
			asicMap.find((*it).getName())->second = measureTime(currentChannel, neuralNetworkList, imageList);
		}
    }

    // Write back to file and create one big map
    std::map<std::string, float> prediction;

    std::ofstream outputFile(filePath);
	outputFile << "CPU";
    for(auto it = cpuMap.begin(); it != cpuMap.end(); ++it){
		outputFile << it->first + "=" + std::to_string(it->second);
        prediction.insert(*it);
    }
	outputFile << "FPGA";
    for(auto it = fpgaMap.begin(); it != fpgaMap.end(); ++it){
        outputFile << it->first + "=" + std::to_string(it->second);
        prediction.insert(*it);
    }
	outputFile << "GPU";
    for(auto it = gpuMap.begin(); it != gpuMap.end(); ++it){
        outputFile << it->first + "=" + std::to_string(it->second);
        prediction.insert(*it);
    }
	outputFile << "ASIC";
    for(auto it = asicMap.begin(); it != asicMap.end(); ++it){
        outputFile << it->first + "=" + std::to_string(it->second);
        prediction.insert(*it);
    }
    outputFile.close();
	return prediction;
}

float CurrentPerformancePredictor::measureTime(Channel* channel, std::list<NeuralNetworkAdapter> neuralNetworks, std::list<cv::Mat> images)
{
    auto t1 = std::chrono::high_resolution_clock::now();
    channel->sendImageList(images);
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = (float)std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    return duration;
}
