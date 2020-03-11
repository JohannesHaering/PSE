#include <gtest/gtest.h>
#include "NeuralNetworkSetter.hpp"
#include "InferencingDistributorClassification.hpp"
#include "ViewFacade.hpp"

struct NeuralNetworkSetterTests : testing::Test 
{
	
	NeuralNetworkSetter* setter;
	Inferencer* inferencer;

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
	std::vector<std::string> paths = { "FOO", "FOO" };
	setter->setNeuralNetwork(paths);
	EXPECT_EQ(inferencer->getAmountNeuralNetworks(), 2);
}

