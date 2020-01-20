#include "PerformancePredictorFromFile.hpp"
#include "CurrentPerformancePredictor.hpp"
#include "Predictor.hpp"
#include "ImageFacade.hpp"
#include "NeuralNetworkFacade.hpp"
#include "NeuralNetwork.hpp"

#include <string>
#include <map>
#include <list>
#include <iostream>
#include <fstream>
#include <utility>
#include <opencv2/opencv.hpp>

std::map<std::string, float> CurrentPerformancePredictor::predict(std::list<std::string> deviceIds)
{
    std::map<std::string, float> savedValues = Predictor::predict(deviceIds);

    NeuralNetwork neuralNetwork = NeuralNetworkFacade.loadNeuralNetwork(nerualNetworkPath);
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
            cpus.std::list<std::string>::push_back(temp);
        }
        if (state == 1)
        {
            fpgas.std::list<std::string>::push_back(temp);
        }
        if (state == 2)
        {
            gpus.std::list<std::string>::push_back(temp);
        }
        if (state == 3)
        {
            asics.std::list<std::string>::push_back(temp);
        }
    }

    std::map<std::string, float> cpuMap = Predictor::parseToFloat(cpus);
    std::map<std::string, float> fpgaMap = Predictor::parseToFloat(fpgas);
    std::map<std::string, float> gpuMap = Predictor::parseToFloat(gpus);
    std::map<std::string, float> asicMap = Predictor::parseToFloat(asics);

    std::map<std::string, float> cpuMapFiltered;
    std::map<std::string, float> fpgaMapFiltered;
    std::map<std::string, float> gpuMapFiltered;
    std::map<std::string, float> asicMapFiltered;

    // Filter

    // Create single predicters 

    file.close();
}
