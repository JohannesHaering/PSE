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
		InferencePageAdapter* classificationPage = ViewFacade::getInstance()->getImageClassification();
		neuralNetworkPager = new NeuralNetworkPager(2, classificationPage);
		imagePager = new ImagePager(2, classificationPage);
		handler = new NewResultHandler(new InferencingDistributorClassification(classificationPage), neuralNetworkPager, imagePager);
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
