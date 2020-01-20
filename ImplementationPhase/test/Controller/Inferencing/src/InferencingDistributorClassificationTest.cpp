#include <gtest/gtest.h>
#include "InferencingDistributorClassification.hpp"
#include "ViewFacade.hpp"
#include "InferencePage.hpp"

class ClassificationPageMock : public InferencePage {

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

struct InferencingDistributorTests : testing::Test 
{
	
	InferencingDistributor* inferencer;
	ClassificationPageMock* page;

	InferencingDistributorTests() {
		page = new ClassificationPageMock();
		inferencer = new InferencingDistributorClassification(*page);
	}

	~InferencingDistributorTests() {
		delete inferencer;
	}

};

TEST_F(InferencingDistributorTests, InferencerShowSaveFalseStartTest)
{
	page->setShowResults(false);
	page->setSaveResults(false);
	std::vector<NeuralNetworkAdapter> neuralNetworks = { NeuralNetworkAdapter(NeuralNetwork()) };
	inferencer->addNeuralNetwork(neuralNetworks);
	std::vector<std::string> paths = { "FOO", "FOO" };
	inferencer->setInput(paths);
	EXPECT_FALSE(inferencer->canStart());
}

TEST_F(InferencingDistributorTests, TopologyCanStartTest)
{
	page->setShowResults(true);
	page->setSaveResults(false);
	std::vector<NeuralNetworkAdapter> neuralNetworks = { NeuralNetworkAdapter(NeuralNetwork()) };
	inferencer->addNeuralNetwork(neuralNetworks);
	std::vector<std::string> paths = { "FOO", "FOO" };
	inferencer->setInput(paths);
	EXPECT_TRUE(inferencer->canStart());
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}