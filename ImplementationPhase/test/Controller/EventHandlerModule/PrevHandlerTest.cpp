#include <gtest/gtest.h>
#include "PrevHandler.hpp"
#include "NeuralNetworkPager.hpp"
#include "viewfacade.h"

struct PrevHandlerTests : testing::Test 
{
	
	NeuralNetworkPager* pager;
	PrevHandler* handler;

	PrevHandlerTests() {
		pager = new NeuralNetworkPager(2, *ViewFacade::getInstance()->getImageClassification());
		handler = new PrevHandler(*pager);
	}

	~PrevHandlerTests() {
		delete pager;
		delete handler;
	}

};

TEST_F(PrevHandlerTests, ActionTest)
{
	pager->next();
	handler->onAction();
	EXPECT_EQ(pager->getCurrentPage(), 0);
}

TEST_F(PrevHandlerTests, ExceptionTest)
{
	EXPECT_DEATH(pager->prev(), "Already zero");
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}