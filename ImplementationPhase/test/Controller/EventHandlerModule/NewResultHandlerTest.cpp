#include <gtest/gtest.h>
#include "NewResultHandler.hpp"
#include "NeuralNetworkPager.hpp"
#include "ImagePager.hpp"
#include "ViewFacade.hpp"
#include "InferencingDistributorClassification.hpp"

struct NewResultHandlerTests : testing::Test 
{
	
	NeuralNetworkPager* neuralNetworkPager;
	ImagePager* imagePager;
	NewResultHandler* handler;

	NewResultHandlerTests() {
		neuralNetworkPager = new NeuralNetworkPager(2, ViewFacade::getClassificationPage());
		imagePager = new ImagePager(2, ViewFacade::getClassificationPage());
		handler = new NewResultHandler(InferencingDistributorClassification(ViewFacade::getClassificationPage()), *neuralNetworkPager, *imagePager);
	}

	~NewResultHandlerTests() {
		delete neuralNetworkPager;
		delete imagePager;
		delete handler;
	}

};

TEST_F(NewResultHandlerTests, ActionTest)
{
	neuralNetworkPager->next();
	imagePager->next();
	handler->onAction();
	EXPECT_EQ(neuralNetworkPager->getCurrentPage(), 0);
	EXPECT_EQ(imagePager->getCurrentPage(), 0);
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}