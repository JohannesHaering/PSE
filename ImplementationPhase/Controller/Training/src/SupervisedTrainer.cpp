#include "TrainingMethods.hpp"
#include "NeuralNetwork.hpp"
#include "NetworkLayer.hpp"
#include "ConvolutionLayer.hpp"
#include "PollingLayer.hpp"
#include "DenseLayer.hpp"
#include "ActivationLayer.hpp"

#include <string>
#include <vector>
#include <list>
#include <opencv2/opencv.hpp>
#include "SupervisedTrainer.hpp"


NeuralNetworkAdapter* SupervisedTrainer::newEpoch() {
	std::list<std::string> imageID = supplyer->getDataIds();
	cv::Mat image; 
	std::vector<float> outputVector;
	NeuralNetworkAdapter* newNetwork;
	for (std::list<std::string>::iterator it = imageID.begin(); it != imageID.end(); ++it) {
		image = supplyer->getImage(*it);
		outputVector = supplyer->getOutputVector(*it);
		newNetwork = backPropagate(image, outputVector, neuralNetwork);
	}
	return newNetwork;
}
