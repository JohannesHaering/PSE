#include "NeuralNetworkFacade.hpp"
#include "TextFileIO.hpp"
#include "NeuralNetworkParser.hpp"
#include "NeuralNetwork.hpp"

#include <string>

NeuralNetwork NeuralNetworkFacade::loadNeuralNetwork(std::string path)
{
    auto input = TextFileIO().readFile(path).getData();
    auto neuralNetwork = NeuralNetworkParser().parse(input);
    return neuralNetwork;
}

bool NeuralNetworkFacade::saveNeuralNetwork(NeuralNetwork neuralNetwork, std::string path)
{
    auto output = NeuralNetworkParser().parseBack(neuralNetwork);
    return TextFileIO().writeFile(path, Data(output));
}