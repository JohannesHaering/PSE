#include <gtest/gtest.h>
#include "NeuralNetworkSetter.hpp"
#include "InferencingDistributorClassification.hpp"
#include "ViewFacade.hpp"

struct NeuralNetworkSetterTests : testing::Test 
{
	
	NeuralNetworkSetter* setter;
	InferencingDistributorClassification* inferencer;

	NeuralNetworkSetterTests() {
		inferencer = new InferencingDistributorClassification(ViewFacade::getInstance()->getImageClassification());
		setter = new NeuralNetworkSetter(inferencer);
	}

	~NeuralNetworkSetterTests() {
		delete inferencer;
		delete setter;
	}

};

TEST_F(NeuralNetworkSetterTests, SetNeuralNetwork)
{
	std::vector<std::string> paths = { "/home/pselabw1920/Documents/trainednetworks/DenseSmall.txt" };
	setter->setNeuralNetwork(paths);
	EXPECT_EQ(inferencer->getAmountNeuralNetworks(), 1);
}

