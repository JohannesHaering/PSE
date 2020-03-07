#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>
#include <stdexcept>

#include "LayerParser.hpp"
#include "LayerType.hpp"
#include "NetworkLayer.hpp"
#include "ConvolutionalLayerParser.hpp"
#include "ConvolutionLayer.hpp"

TEST(ConvLayerParserTest, valid)
{
  std::string in = "tensor=[[[[1]]]]";
  NetworkLayer* layer = ConvolutionalLayerParser().parse(in);
  EXPECT_EQ(LayerType::CONVOLUTION, layer->getLayerType());
}

TEST(ConvLayerParserTest, invalid)
{
  std::string in = "tesor=[[[[1]]]]";
  EXPECT_THROW(ConvolutionalLayerParser().parse(in), std::invalid_argument);
}

TEST(ConvLayerBackParserTest, valid)
{
  auto tensor = std::vector<std::vector<std::vector<std::vector<float>>>>();
  auto sub1 = std::vector<std::vector<std::vector<float>>>();
  auto sub2 = std::vector<std::vector<float>>();
  auto sub3 = std::vector<float>();
  sub3.push_back(1);
  sub2.push_back(sub3);
  sub1.push_back(sub2);
  tensor.push_back(sub1);
  ConvolutionalLayer *layer = new ConvolutionLayer(tensor, 0, 0);
  EXPECT_EQ("[convolutional]\ntensor=[[[[1.000000]]]]\n", ConvolutionalLayerParser().parseBack(layer));
}
