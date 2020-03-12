#include <gtest/gtest.h>
#include "PrevHandler.hpp"
#include "NeuralNetworkPager.hpp"
#include "ViewFacade.hpp"

struct PrevHandlerTests : testing::Test 
{
	
	NeuralNetworkPager* pager;
	PrevHandler* handler;

	PrevHandlerTests() {
		pager = new NeuralNetworkPager(2, ViewFacade::getInstance()->getImageClassification());
		handler = new PrevHandler(pager);
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
