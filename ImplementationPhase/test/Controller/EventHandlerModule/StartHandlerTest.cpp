#include <gtest/gtest.h>
#include "StartHandler.hpp"
#include "InferencingDistributorClassification.hpp"
#include "ViewFacade.hpp"
#include <QApplication>
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

struct StartHandlerTests : testing::Test 
{
	
	StartHandler* handler;
	InferencerMock* inferencer;

	StartHandlerTests() {
		this->inferencer = new InferencerMock();
		this->handler = new StartHandler(inferencer);
	}

	~StartHandlerTests() {
		delete handler;
	}

};

TEST_F(StartHandlerTests, ActionTest)
{
	EXPECT_FALSE(inferencer->getStartSignalGiven());
	handler->onAction();
	EXPECT_TRUE(inferencer->getStartSignalGiven());
}

