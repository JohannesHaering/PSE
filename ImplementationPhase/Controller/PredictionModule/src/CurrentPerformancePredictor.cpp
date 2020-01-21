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
#include "GPUChanel.hpp"
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

    NeuralNetworkAdapter neuralNetwork = NeuralNetworkFacade.loadNeuralNetwork(nerualNetworkPath);
    std::list<NeuralNetwork> neuralNetworkList;
    neuralNetworkList.push_back(neuralNetwork);

    cv::Mat image = ImageFacade().getImage(imagePath, neuralNetwork.getWidth(), neuralNetwork.getHEight(), neuralNetwork.getChannelNumb());
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
        if (temp == "CPU")
        {
            state = 0;
            continue;
        }
        if (temp == "FPGA")
        {
            state = 1;
            continue;
        }
        if (temp == "GPU")
        {
            state = 2;
            continue;
        }
        if (temp == "ASIC")
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
            devices.push_back(Device(*it, "CPU", 0, 0, 0));
            continue;
        }
        if (fpgaMap.find(*it) != fpgaMap.end())
        {
            devices.push_back(Device(*it, "FPGA", 0, 0, 0));
            continue;
        }
        if (gpuMap.find(*it) != gpuMap.end())
        {
            devices.push_back(Device(*it, "GPU", 0, 0, 0));
            continue;
        }
        if (asicMap.find(*it) != asicMap.end())
        {
            devices.push_back(Device(*it, "ASIC", 0, 0, 0));
            continue;
        }
    }

    // Make test classification and count the time for that
    for (auto it = devices.begin(); it != devices.end(); ++it)
    {
        // Create device speficic channel
        Channel currentChannel;
        switch ((*it).getType())
        {
        case "CPU":
            currentChannel = CPUChannel(*it, neuralNetworkList);
            cpuMap.find((*it).getName())->second = measureTime(currentChannel, neuralNetworkList, imageList);
            break;
        case "FPGA":
            currentChannel = FPGAChannel(*it, neuralNetworkList);
            fpgaMap.find((*it).getName())->second = measureTime(currentChannel, neuralNetworkList, imageList);
            break;
        case "GPU":
            currentChannel = GPUChannel(*it, neuralNetworkList);
            gpuMap.find((*it).getName())->second = measureTime(currentChannel, neuralNetworkList, imageList);
            break;
        case "ASIC":
            currentChannel = ASICChannel(*it, neuralNetworkList);
            asicMap.find((*it).getName())->second = measureTime(currentChannel, neuralNetworkList, imageList);
            break;
        default:
            break;
        }
    }

    // Write back to file and create one big map
    std::map<std::string, float> prediction;

    std::ofstream outputFile(filePath);
    outputFile << "CPU"
    for(auto it = cpuMap.begin(); it != cpuMap.end(); ++it){
        outputFile << it->first + "=" it->second;
        prediction.insert(it);
    }
    outputFile << "FPGA"
    for(auto it = fpgaMap.begin(); it != fpgaMap.end(); ++it){
        outputFile << it->first + "=" it->second;
        prediction.insert(it);
    }
    outputFile << "GPU"
    for(auto it = gpuMap.begin(); it != gpuMap.end(); ++it){
        outputFile << it->first + "=" it->second;
        prediction.insert(it);
    }
    outputFile << "ASIC"
    for(auto it = asicMap.begin(); it != asicMap.end(); ++it){
        outputFile << it->first + "=" it->second;
        prediction.insert(it);
    }
    outputFile.close();

}

float CurrentPerformancePredictor::measureTime(Channel channel, std::list<NeuralNetworkAdapter> neuralNetworks, std::list<cv::Mat> images)
{
    auto t1 = std::chrono::high_resolution_clock::now();
    currentChannel.sendImageList(imageList);
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = (float)std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    return duration;
}
