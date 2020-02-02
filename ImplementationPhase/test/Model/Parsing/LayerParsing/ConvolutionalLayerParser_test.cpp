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

TEST(LayerParserTest, valid)
{
  std::string in = "inputdim=[1,2,3]\nstride=1\npadding=1\ntensor=[[[[1]]]]";
  auto layer = ConvolutionalLayerParser().parse(in);
  EXPECT_EQ(LayerType::CONVOLUTION, layer.getLayerType());
}

TEST(LayerParserTest, invalid1)
{
  std::string in = "inutdim=[1,2,3]\nstride=1\npadding=1\ntensor=[[[[1]]]]";
  EXPECT_THROW(ConvolutionalLayerParser().parse(in), std::invalid_argument);
}

TEST(LayerParserTest, invalid2)
{
  std::string in = "inputdim=[1,2,3]\nstrde=1\npadding=1\ntensor=[[[[1]]]]";
  EXPECT_THROW(ConvolutionalLayerParser().parse(in), std::invalid_argument);
}

TEST(LayerParserTest, invalid3)
{
  std::string in = "inputdim=[1,2,3]\nstride=1\npaddig=1\ntensor=[[[[1]]]]";
  EXPECT_THROW(ConvolutionalLayerParser().parse(in), std::invalid_argument);
}

TEST(LayerParserTest, invalid4)
{
  std::string in = "inputdim=[1,2,3]\nstride=1\npadding=1\ntesor=[[[[1]]]]";
  EXPECT_THROW(ConvolutionalLayerParser().parse(in), std::invalid_argument);
}

TEST(LayerBackParserTest, valid)
{
  int dim[] = {1, 2, 3};
  auto tensor = std::vector<std::vector<std::vector<std::vector<float>>>>();
  auto sub1 = std::vector<std::vector<std::vector<float>>>();
  auto sub2 = std::vector<std::vector<float>>();
  auto sub3 = std::vector<float>();
  sub3.push_back(1);
  auto layer = ConvolutionLayer("name", dim, tensor, 1, 1);
  EXPECT_EQ("[convolution]\ninputdim=[1,2,3]\nstride=1\npadding=1\ntensor=[[[[1]]]]", ConvolutionalLayerParser().parseBack(layer));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}