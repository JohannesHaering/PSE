#include <gtest/gtest.h>
#include "InferencingDistributorClassification.hpp"

struct InferencingDistributorTests : testing::Test 
{
	
	InferencingDistributor* inferencer;

	InferencingDistributorTests() {
		inferencer = new InferencingDistributorClassification();
	}

	~InferencingDistributorTests() {
		delete inferencer;
	}

};

TEST_F(InferencingDistributorTests, TopologyBeginStartTest)
{
	EXPECT_FALSE(inferencer->canStart());
}

TEST_F(InferencingDistributorTests, TopologyCanStartTest)
{
	std::vector<NeuralNetworkAdapter> neuralNetworks = { NeuralNetworkAdapter(NeuralNetwork()) };
	inferencer->addNeuralNetwork(neuralNetworks);
	EXPECT_TRUE(inferencer->canStart());
}
