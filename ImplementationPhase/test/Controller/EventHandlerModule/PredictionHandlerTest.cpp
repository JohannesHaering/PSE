#include <gtest/gtest.h>
#include "PredictionHandler.hpp"
#include "InferencePageAdapter.hpp"
#include <QApplication>
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

struct PredictionTests : testing::Test 
{
	
	PredictionHandler* handler;
	InferencerPredictionMock* page;

	PredictionTests() 
	{
		page = new InferencerPredictionMock();
		handler = new PredictionHandler(page);
	}

	~PredictionTests() 
	{
		delete handler;
		delete page;
	}

};

TEST_F(PredictionTests, ActionTest)
{
	//handler->onAction();
	//EXPECT_TRUE(page->getPowerPrediction() > 0);
	//EXPECT_TRUE(page->getPerformancePrediction() > 0);
}

