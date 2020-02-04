#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>
#include <stdexcept>

#include "LayerParser.hpp"
#include "LayerType.hpp"
#include "NetworkLayer.hpp"
#include "LocalResponseNormalizationLayer.hpp"
#include "LRNLayerParser.hpp"
#include "LRNType.hpp"

TEST(LayerParserTest, valid1)
{
  std::string in = "inputdim=[1,2,3]\ndepth=1\ntype=inter";
  auto layer = LRNLayerParser().parse(in);
  EXPECT_EQ(layer.getLayerType(), LayerType::LRN);
}

TEST(LayerParserTest, valid2)
{
  std::string in = "inputdim=[1,2,3]\ndepth=1\ntype=intra";
  auto layer = LRNLayerParser().parse(in);
  EXPECT_EQ(layer.getLayerType(), LayerType::LRN);
}

TEST(LayerParserTest, invalid)
{
  std::string in = "inputdim=[1,2,3]\ndepth=1\ntye=inter";
  EXPECT_THROW(LRNLayerParser().parse(in), std::invalid_argument);
}

TEST(LayerBackParserTest, valid)
{
  int dim[] = {1, 2, 3};
  auto layer = LocalResponseNormalizationLayer("", dim, LRNType::INTER_CHANNEL, 1);
  EXPECT_EQ("[lrn]\ninputdim=[1,2,3]\ndepth=1\ntype=inter\n", LRNLayerParser().parseBack(layer));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}