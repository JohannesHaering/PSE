#include <gtest/gtest.h>
#include "Inferencer.hpp"

TEST(SetTest, SettingNeuralNetworkTest)
{
	Inferencer distributor = Inferencer();
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}