#ifndef EXECUTOR_H_
#define EXECUTOR_H_

#include <vector>
#include <string>
#include "NetworkLayer.hpp"
#include "NeuralNetworkAdapter.hpp"

class Executor
{
public:
	Executor(NeuralNetworkAdapter* neuralNetwork);
    std::vector<float> execute(std::vector<float> input);
private:
    std::vector<std::string> inputData;
	void loadDataset();
	NeuralNetworkAdapter* neuralNetwork;
    
    std::vector<std::vector<float>> dataset_train_images;
    std::vector<std::vector<float>> dataset_test_images;
    std::vector<std::vector<float>> dataset_train_labels;
    std::vector<std::vector<float>> dataset_test_labels;
};
#endif
