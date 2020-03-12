#include <gtest/gtest.h>
#include "Executor.hpp"

#include "MatrixDefine.hpp"
#include "NeuralNetworkFacade.hpp"
#include "NeuralNetworkAdapter.hpp"
#include "NeuralNetwork.hpp"
#include "MNISTDataParser.hpp"

#define TestNeuralNetworkPath "/home/pselabw1920/Documents/trainednetworks/DenseSmall.txt"

TEST(ExecutorTest, ConstructorTest) {
    NeuralNetworkFacade NNFacade = NeuralNetworkFacade();
    NeuralNetworkAdapter neuralNetwork = NeuralNetworkAdapter(NNFacade.loadNeuralNetwork(TestNeuralNetworkPath));
    Executor *executor = new Executor(&neuralNetwork);
    ASSERT_NE(executor, nullptr);
}

TEST(ExecutorTest, setModes) {
    NeuralNetworkFacade NNFacade = NeuralNetworkFacade();
    NeuralNetworkAdapter neuralNetwork = NeuralNetworkAdapter(NNFacade.loadNeuralNetwork(TestNeuralNetworkPath));
    MNISTDataParser MNISTGen = MNISTDataParser(1);
    Executor executor = Executor(&neuralNetwork);
    TENSOR(float) input = MNISTGen.parseTraining();
    ASSERT_NE(&input, nullptr);
    TENSOR(float) output = executor.execute(input);
    EXPECT_EQ(input.size(), output.size()); //batchSize should stay constant
}
