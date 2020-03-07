#include "Executor.hpp"
#include "ControllerFacade.hpp"
#include "NetworkLayer.hpp"
#include "NeuralNetworkAdapter.hpp"
#include <vector>
#include "Executor.hpp"
#include "/home/pselabw1920/Documents/mnist/include/mnist/mnist_reader.hpp"
#include "MatrixDefine.hpp"

Executor::Executor(NeuralNetworkAdapter* neuralNetwork) : neuralNetwork(neuralNetwork) {}


TENSOR(float) Executor::execute(TENSOR(float) input) {

    TENSOR(float) tmp = input;
    TENSOR(float) output;
    for (std::list<NetworkLayer*>::iterator layer = neuralNetwork->begin(); layer != neuralNetwork->end(); layer++)
    {
		  output = (*layer)->forward(tmp);
		  tmp = output;
    }
    return output;

}
