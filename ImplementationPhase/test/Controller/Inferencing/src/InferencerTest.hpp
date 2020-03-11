#include <gtest/gtest.h>
#include "InferencingDistributorClassification.hpp"

class ClassificationPageMock : public InferencePageAdapter {

public:
	bool getShowResults()
	{
		return showResults;
	}
	bool getSaveResults()
	{
		return saveResults;
	}
	void setShowResults(bool enable)
	{
		showResults = enable;
	}
	void setSaveResults(bool enable)
	{
		saveResults = enable;
	}

private:
	bool showResults;
	bool saveResults;

};

struct InferencerTest : testing::Test 
{
	
	InferencingDistributorClassification* inferencer;

	InferencerTest() {
	  ClassificationPageMock* page = new ClassificationPageMock();
    inferencer = new InferencingDistributorClassification(page);
	}

	~InferencerTest() {
		delete inferencer;
	}

};

TEST_F(InferencerTest, InferencerStartValueTest) 
{
	EXPECT_EQ(inferencer->getAmountNeuralNetworks(), 0);
}

TEST_F(InferencerTest, SettingNeuralNetworkTest)
{
	std::vector<NeuralNetworkAdapter> neuralNetworks = { NeuralNetworkAdapter(NeuralNetwork()) };
	inferencer->addNeuralNetwork(neuralNetworks);
	EXPECT_EQ(inferencer->getAmountNeuralNetworks(), 1);
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
