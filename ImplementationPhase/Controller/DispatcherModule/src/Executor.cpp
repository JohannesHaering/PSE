#include "Executor.hpp"
#include "ControllerFacade.hpp"
#include "NetworkLayer.hpp"
#include "NeuralNetworkAdapter.hpp"
#include <vector>
#include "Executor.hpp"
#include "/home/pselabw1920/Documents/mnist/include/mnist/mnist_reader.hpp"



Executor::Executor(NeuralNetworkAdapter* neuralNetwork) : neuralNetwork(neuralNetwork) {}


TENSOR(float) Executor::execute(TENSOR(float) input) {

    TENSOR(float) temp = input;
    NetworkLayer* lastlayer = neuralNetwork->getLastLayer();                                                                                                                                 
    for (NetworkLayer* layer = neuralNetwork->getFirstLayer();; layer = neuralNetwork->getNextLayer())
    {
       temp = layer->forward(temp);  
       if (layer == lastlayer) break;
    }
    return temp;
    
}
