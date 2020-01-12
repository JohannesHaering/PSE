#include "NeuralNetworkAdapter.hpp"
#include "NeuralNetworkLayer.hpp"
#include "NeuralNetwork.hpp"

		NeuralNetworkAdapter::NeuralNetworkAdapter(NeuralNetwork neuralNetwork) : neuralNetwork(neuralNetwork){}

        void NeuralNetworkAdapter::addLayer(NeuralNetworkLayer layer) { neuralNetwork.addLayer(layer); }

		NeuralNetworkLayer NeuralNetworkAdapter::getFirstLayer() { return neuralNetwork.getFirstLayer(); }

		NeuralNetworkLayer NeuralNetworkAdapter::getLastLayer() { return neuralNetwork.getLastLayer(); }

		NeuralNetworkLayer NeuralNetworkAdapter::getNextLayer() { return neuralNetwork.getNextLayer(); }

		NeuralNetworkLayer NeuralNetworkAdapter::getPreviousLayer() { return neuralNetwork.getPreviousLayer(); }