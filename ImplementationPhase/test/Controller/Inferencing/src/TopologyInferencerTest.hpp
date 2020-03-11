#include <gtest/gtest.h>
#include "TopologyInferencer.hpp"

struct TopologyInferencerTests : testing::Test 
{
	
	TopologyInferencer* inferencer;

	TopologyInferencerTests() {
		inferencer = new TopologyInferencer();
	}

	~TopologyInferencerTests() {
		delete inferencer;
	}

};

TEST_F(TopologyInferencerTests, TopologyBeginStartTest)
{
	EXPECT_FALSE(inferencer->canStart());
}

TEST_F(TopologyInferencerTests, TopologyCanStartTest)
{
	std::vector<NeuralNetworkAdapter> neuralNetworks = { NeuralNetworkAdapter(NeuralNetwork()) };
	inferencer->addNeuralNetwork(neuralNetworks);
	EXPECT_TRUE(inferencer->canStart());
}
