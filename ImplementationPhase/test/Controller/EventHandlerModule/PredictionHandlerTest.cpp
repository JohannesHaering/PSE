#include <gtest/gtest.h>
#include "PredictionHandler.hpp"
#include "InferencePageAdapter.hpp"

class InferencerPredictionMock : public InferencePageAdapter
{

public:
	InferencerPredictionMock()
	{
		powerPrediction = 0;
		performancePrediction = 0;
	}
	void setPowerPrediction(int amount)
	{
		powerPrediction = amount;
	}
	void setPerformancePrediction(int amount)
	{
		performancePrediction = amount;
	}
	int getPowerPrediction()
	{
		return powerPrediction;
	}
	int getPerformancePrediction()
	{
		return performancePrediction;
	}

private:
	int powerPrediction;
	int performancePrediction;

};

struct StartHandlerTests : testing::Test 
{
	
	PredictionHandler* handler;
	InferencerPredictionMock* page;

	StartHandlerTests() 
	{
		page = new InferencerPredictionMock();
		handler = new PredictionHandler(*page);
	}

	~StartHandlerTests() 
	{
		delete handler;
		delete page;
	}

};

TEST_F(StartHandlerTests, ActionTest)
{
	handler->onAction();
	EXPECT_TRUE(page->getPowerPrediction() > 0);
	EXPECT_TRUE(page->getPerformancePrediction() > 0);
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
