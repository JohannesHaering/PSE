#include <gtest/gtest.h>
#include <vector>
#include <list>
#include <string>

#include "NeuralNetworkFacade.hpp"
#include "NeuralNetwork.hpp"
#include "ReLuLayer.hpp"

TEST(LoadNeuralNetworkTest, valid)
{
    auto path = "C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\TestNeuralNetworkRead.txt";
    NeuralNetwork neuralNetwork = NeuralNetworkFacade().loadNeuralNetwork(path);
    EXPECT_EQ("nn", neuralNetwork.getName());
}

TEST(LoadNeuralNetworksTest, valid)
{
    auto path = "C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\TestNeuralNetworkRead.txt";
    std::list<std::string> paths = std::list<std::string>();
    paths.push_back(path);
    NeuralNetwork neuralNetwork = *NeuralNetworkFacade().loadNeuralNetworks(paths).begin();
    EXPECT_EQ("nn", neuralNetwork.getName());
}

TEST(SaveNeuralNetworkTest, valid)
{
    NeuralNetwork network = NeuralNetwork("nn", 64, 64, 3);
    ReLuLayer*layer = new ReLuLayer();
    network.addLayer(layer);
    auto path = "C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\TestNeuralNetworkWrite.txt";
    auto succes = NeuralNetworkFacade().saveNeuralNetwork(network, path);
    EXPECT_EQ(true, succes);
}

TEST(SaveNeuralNetworksTest, valid)
{
    auto nns = std::list<NeuralNetwork>();
    auto paths = std::list<std::string>();
    NeuralNetwork network = NeuralNetwork("nn", 64, 64, 3);
    ReLuLayer*layer = new ReLuLayer();
    network.addLayer(layer);
    auto path = "C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\TestNeuralNetworkWrite.txt";
    nns.push_back(network);
    paths.push_back(path);
    auto succes = NeuralNetworkFacade().saveNeuralNetworks(nns, paths);
    EXPECT_EQ(true, succes);
}
