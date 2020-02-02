#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>
#include <stdexcept>

#include "LayerParser.hpp"
#include "LayerType.hpp"
#include "NetworkLayer.hpp"
#include "FlattenLayerParser.hpp"
#include "FlattenLayer.hpp"

TEST(LayerParserTest, valid)
{
  std::string in = "inputdim=[1,2,3]";
  auto layer = FlattenLayerParser().parse(in);
  EXPECT_EQ(LayerType::FLATTEN, layer.getLayerType());
}

TEST(LayerParserTest, invalid)
{
  std::string in = "x=[1,2,3]\nfunction=rel\nalpha=0.2";
  EXPECT_THROW(FlattenLayerParser().parse(in), std::invalid_argument);
}

TEST(LayerBackParserTest, valid)
{
  int dim[] = {1, 2, 3};
   auto layer = FlattenLayer("name", dim);
   EXPECT_EQ("[flatten]\ninputdim=[1,2,3]", FlattenLayerParser().parseBack(layer));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}