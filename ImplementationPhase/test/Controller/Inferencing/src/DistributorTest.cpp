#include <gtest/gtest.h>
#include "Distributor.hpp"

struct DistributorTests : testing::Test
{

	Distributor* distributor;

	DistributorTests() {
		distributor = new Distributor();
	}

	~DistributorTests() {
		delete distributor;
	}

};

TEST_F(DistributorTests, DistributorStartValueTest)
{
	EXPECT_EQ(distributor->getAmountImages(), 0);
}

TEST_F(DistributorTests, SettingImagesTest)
{
	std::vector<std::string> paths = { "FOO", "FOO" };
	distributor->setInput(paths);
	EXPECT_EQ(distributor->getAmountImages(), 2);
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}