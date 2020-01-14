#include <gtest/gtest.h>
#include "PrevHandler.hpp"
#include "NeuralNetworkPager.hpp"
#include "ViewFacade.hpp"

struct PrevHandlerTests : testing::Test 
{
	
	NeuralNetworkPager* pager;
	PrevHandler* handler;

	PrevHandlerTests() {
		pager = new NeuralNetworkPager(2, ViewFacade::getClassificationPage());
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

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}