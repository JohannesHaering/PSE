#include <gtest/gtest.h>
#include "Distributor.hpp"
#include "InferencingDistributorClassification.hpp"
#include "ViewFacade.hpp"

struct DistributorTests : testing::Test
{

  InferencingDistributorClassification* distributor;

	DistributorTests() {
		distributor = new InferencingDistributorClassification(ViewFacade::getInstance()->getImageClassification());
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

