#include <gtest/gtest.h>
#include "Inferencer.hpp"

struct InferencerTest : testing::Test 
{
	
	Inferencer* inferencer;

	InferencerTest() {
		inferencer = new Inferencer();
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

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}