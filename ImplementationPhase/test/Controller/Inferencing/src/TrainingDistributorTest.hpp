#include <gtest/gtest.h>
#include "TrainingDistributor.hpp"

struct TrainingDistributorTests : testing::Test 
{
	
	TrainingDistributor* distributor;

	TrainingDistributorTests() {
		distributor = new TrainingDistributor();
	}

	~TrainingDistributorTests() {
		delete distributor;
	}

};

TEST_F(TrainingDistributorTests, TrainingNothingStartTest)
{
	EXPECT_FALSE(distributor->canStart());
}

TEST_F(TrainingDistributorTests, TrainingImagesStartTest)
{
	std::vector<std::string> paths = { "FOO", "FOO" };
	distributor->setInput(paths);
	EXPECT_FALSE(distributor->canStart());
}

TEST_F(TrainingDistributorTests, TrainingNetworkStartTest)
{
	std::vector<NeuralNetworkAdapter> neuralNetworks = { NeuralNetworkAdapter(NeuralNetwork()) };
	distributor->addNeuralNetwork(neuralNetworks);
	EXPECT_FALSE(distributor->canStart());
}


TEST_F(TrainingDistributorTests, TrainingCanStartTest)
{
	std::vector<NeuralNetworkAdapter> neuralNetworks = { NeuralNetworkAdapter(NeuralNetwork()) };
	distributor->addNeuralNetwork(neuralNetworks);
	std::vector<std::string> paths = { "FOO", "FOO" };
	distributor->setInput(paths);
	EXPECT_TRUE(distributor->canStart());
}

