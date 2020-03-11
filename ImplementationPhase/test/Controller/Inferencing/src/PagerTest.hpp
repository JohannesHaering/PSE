#include <gtest/gtest.h>
#include "NeuralNetworkPager.hpp"
#include "ViewFacade.hpp"

struct NeuralNetworkPagerTests : testing::Test 
{
	
	Pager* pager;

	NeuralNetworkPagerTests() {
		pager = new NeuralNetworkPager(2, ViewFacade::getInstance()->getImageClassification());
	}

	~NeuralNetworkPagerTests() {
		delete pager;
	}

};

TEST_F(NeuralNetworkPagerTests, PagerStartsAtZeroTest)
{
	EXPECT_EQ(pager->getCurrentPage(), 0);
}

TEST_F(NeuralNetworkPagerTests, PagerMinimumTest)
{
	EXPECT_FALSE(pager->prevEnable());
}

TEST_F(NeuralNetworkPagerTests, PagerMaximumTest)
{
	pager->next();
	pager->next();
	EXPECT_FALSE(pager->nextEnable());
}


TEST_F(NeuralNetworkPagerTests, PagerNextTest)
{
	pager->next();
	EXPECT_EQ(pager->getCurrentPage(), 1);
}

TEST_F(NeuralNetworkPagerTests, PagerPrevTest)
{
	pager->next();
	pager->prev();
	EXPECT_EQ(pager->getCurrentPage(), 0);
}

TEST_F(NeuralNetworkPagerTests, ResetTest)
{
	pager->reset(1);
	EXPECT_EQ(pager->getCurrentPage(), 0);
	pager->next();
	EXPECT_FALSE(pager->nextEnable());
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
