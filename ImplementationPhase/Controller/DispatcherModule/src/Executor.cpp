#include "Executor.hpp"
#include "NetworkLayer.hpp"
#include "NeuralNetworkAdapter.hpp"
#include "MatrixDefine.hpp"
#include <vector>

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
