#include <gtest/gtest.h>
#include "StartHandler.hpp"

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

struct StartHandlerTests : testing::Test 
{
	
	StartHandler* handler;
	InferencerMock* inferencer;

	StartHandlerTests() {
		this->inferencer = new InferencerMock();
		this->handler = new StartHandler(*inferencer);
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

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}