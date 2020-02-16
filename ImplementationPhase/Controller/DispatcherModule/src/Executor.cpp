#include "Executor.hpp"
#include "ControllerFacade.hpp"
#include "NetworkLayer.hpp"
#include "NeuralNetworkAdapter.hpp"
#include <vector>
#include "Executor.hpp"
#include "/home/pselabw1920/Documents/mnist/include/mnist/mnist_reader.hpp"



Executor::Executor(NeuralNetworkAdapter* neuralNetwork) : neuralNetwork(neuralNetwork) {}


TENSOR(float) Executor::execute(TENSOR(float) input) {

    TENSOR(float) tmp = input;

    for (NetworkLayer *layer = neuralNetwork->begin(); layer != neuralNetwork->end(); layer++)
    {
		  output = layer->forward(tmp);
		  tmp = output;
	  }
    std::cout << "returning from forward" << std::endl;
    return output;
    
}
