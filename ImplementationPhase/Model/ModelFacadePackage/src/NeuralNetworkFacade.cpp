#include "NeuralNetworkFacade.hpp"
#include "TextFileIO.hpp"
#include "NeuralNetworkParser.hpp"
#include "NeuralNetwork.hpp"
#include "Data.hpp"

#include <string>
#include <list>

NeuralNetwork NeuralNetworkFacade::loadNeuralNetwork(std::string path)
{
    auto input = TextFileIO().readFile(path).getData();
    auto neuralNetwork = NeuralNetworkParser().parse(input);
    return neuralNetwork;
}

std::list<NeuralNetwork> NeuralNetworkFacade::loadNeuralNetworks(std::list<std::string> paths)
{
    std::list<NeuralNetwork> neuralNetworks;
    for (auto it = paths.begin(); it != paths.end(); ++it)
    {
        neuralNetworks.push_back(loadNeuralNetwork(*it));
    }
    return neuralNetworks;
}

bool NeuralNetworkFacade::saveNeuralNetwork(NeuralNetwork neuralNetwork, std::string path)
{
    auto output = NeuralNetworkParser().parseBack(neuralNetwork);
    return TextFileIO().writeFile(path, Data(output));
}

bool NeuralNetworkFacade::saveNeuralNetworks(std::list<NeuralNetwork> neuralNetworks, std::list<std::string> paths)
{
    bool succes = true;
    auto nIt = neuralNetworks.begin();
    auto pIt = paths.begin();
    for (; nIt != neuralNetworks.end() && pIt != paths.end(); ++nIt, ++pIt)
        succes &= saveNeuralNetwork(*nIt, *pIt);
    return succes;
}
