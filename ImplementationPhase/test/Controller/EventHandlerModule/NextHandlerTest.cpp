#include <gtest/gtest.h>
#include "NextHandler.hpp"
#include "NeuralNetworkPager.hpp"
#include "ViewFacade.hpp"

struct NextHandlerTests : testing::Test 
{
	
	NeuralNetworkPager* pager;
	NextHandler* handler;

	NextHandlerTests() {
		pager = new NeuralNetworkPager(2, *ViewFacade::getInstance()->getImageClassification());
		handler = new NextHandler(*pager);
	}

	~NextHandlerTests() {
		delete pager;
		delete handler;
	}

};

TEST_F(NextHandlerTests, ActionTest)
{
	handler->onAction();
	EXPECT_EQ(pager->getCurrentPage(), 1);
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
