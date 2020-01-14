#include <gtest/gtest.h>
#include "StartHandler.hpp"

struct StartHandlerTests : testing::Test 
{
	
	StartHandler* handler;
	InferencerMock* inferencer;

	StartHandlerTests() {
		inferencer = new InferencerMock();
		handler = new StartHandler(*inferencer);
	}

	~StartHandlerTests() {
		delete handler;
	}

};

class InferencerMock : public Inferencer {

public:
	InferencerMock()
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

TEST_F(StartHandlerTests, ActionTest)
{
	EXPECT_FALSE(inferencer->getStartSignalGiven());
	handler->onAction();
	EXPECT_TRUE(inferencer->getStartSignalGiven());
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}