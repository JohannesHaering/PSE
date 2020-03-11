#pragma once

#include <gtest/gtest.h>
#include "StartHandler.hpp"
#include "InferencingDistributorClassification.hpp"
#include "ViewFacade.hpp"

class InferencerMock : public InferencingDistributorClassification {

public:
	InferencerMock() : InferencingDistributorClassification(ViewFacade::getInstance()->getImageClassification())
	{
		startSignalGiven = false;
	}
	void startProcess()
	{
		startSignalGiven = true;
	}
	bool getStartSignalGiven()
	{
		return startSignalGiven;
	}

private:
	bool startSignalGiven;

};

struct FStartHandlerTests : testing::Test 
{
	
	StartHandler* handler;
	InferencerMock* inferencer;

	FStartHandlerTests() {
		this->inferencer = new InferencerMock();
		this->handler = new StartHandler(inferencer);
	}

	~FStartHandlerTests() {
		delete handler;
	}

};

TEST_F(FStartHandlerTests, ActionTest)
{
	EXPECT_FALSE(inferencer->getStartSignalGiven());
	handler->onAction();
	EXPECT_TRUE(inferencer->getStartSignalGiven());
}
