#pragma once

#include <gtest/gtest.h>
#include "InferencingDistributorClassification.hpp"
#include "ViewFacade.hpp"
#include "InferencePageAdapter.hpp"

class DClassificationPageMock : public InferencePageAdapter {

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
	DClassificationPageMock* page;

	InferencingDistributorTests() {
		page = new DClassificationPageMock();
		inferencer = new InferencingDistributorClassification(page);
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
