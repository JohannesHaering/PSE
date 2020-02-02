#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>
#include <stdexcept>

#include "LayerParser.hpp"
#include "LayerType.hpp"
#include "NetworkLayer.hpp"
#include "DropoutLayer.hpp"
#include "DropoutLayerParser.hpp"

TEST(LayerParserTest, valid1)
{
  std::string in = "inputdim=[1,2,3]\nrate=0.2";
  auto layer = DropoutLayerParser().parse(in);
  EXPECT_EQ(LayerType::DROPOUT, layer.getLayerType());
}

TEST(LayerParserTest, valid2)
{
  std::string in = "inputdim=[1,2,3]";
  auto layer = DropoutLayerParser().parse(in);
  EXPECT_EQ(LayerType::DROPOUT, layer.getLayerType());
}

TEST(LayerBackParserTest, valid)
{
  int dim[] = {1, 2, 3};
  auto layer = DropoutLayer("", dim, 0.1);
  EXPECT_EQ("[dropout]\ninputdim=[1,2,3]\nrate=0.1", DropoutLayerParser().parseBack(layer));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}