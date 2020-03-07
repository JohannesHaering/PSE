#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>

#include "NeuralNetwork.hpp"
#include "NeuralNetworkParser.hpp"
#include "ReLuLayer.hpp"

TEST(Parse, valid)
{
	std::string in = "[nn]\nlabels=name1,name2\nheight=64\nwidth=64\nchannels=3\n[activation]\nfunction=relu\n";
	auto network = NeuralNetworkParser().parse(in);
	EXPECT_EQ(64, network.getHeight());
	EXPECT_EQ(64, network.getWidth());
	EXPECT_EQ(3, network.getChannels());
}

TEST(ParseBack, invalid)
{
	NeuralNetwork network = NeuralNetwork("nn", 64, 64, 3);
	ReLuLayer* layer = new  ReLuLayer();
	network.addLayer(&layer);
	std::list<std::string> labels = std::list<std::string>();
	labels.push_back("name1");
	labels.push_back("name2");
	network.setLabels(labels);
	std::string out = NeuralNetworkParser().parseBack(network);
	EXPECT_EQ("[nn]\nlabels=name1,name2\nheight=64\nwidth=64\nchannels=3\n[activation]\nfunction=relu\n", out);
}
