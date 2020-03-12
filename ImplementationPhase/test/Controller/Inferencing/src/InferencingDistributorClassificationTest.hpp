#pragma once

#include <gtest/gtest.h>
#include "InferencingDistributorClassification.hpp"
#include "ViewFacade.hpp"
#include "InferencePageAdapter.hpp"
#include "ClassificationPageMock.cpp"

struct InferencingDistributorTests : testing::Test 
{
	
	InferencingDistributorClassification* inferencer;
	ClassificationPageMock* page;

	InferencingDistributorTests() {
		page = new ClassificationPageMock();
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
	EXPECT_TRUE(inferencer->canStart());
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
