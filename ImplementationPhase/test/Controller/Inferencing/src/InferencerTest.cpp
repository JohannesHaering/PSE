#include <gtest/gtest.h>
#include "InferencingDistributorClassification.hpp"
#include "ClassificationPageMock.cpp"

struct InferencerTest : testing::Test 
{
	
	InferencingDistributorClassification* inferencer;

	InferencerTest() {
	  ClassificationPageMock* page = new ClassificationPageMock();
    inferencer = new InferencingDistributorClassification(page);
	}

	~InferencerTest() {
		delete inferencer;
	}

};

TEST_F(InferencerTest, InferencerStartValueTest) 
{
	EXPECT_EQ(inferencer->getAmountNeuralNetworks(), 0);
}

TEST_F(InferencerTest, SettingNeuralNetworkTest)
{
	std::vector<NeuralNetworkAdapter> neuralNetworks = { NeuralNetworkAdapter(NeuralNetwork()) };
	inferencer->addNeuralNetwork(neuralNetworks);
	EXPECT_EQ(inferencer->getAmountNeuralNetworks(), 1);
}

