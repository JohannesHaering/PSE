#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>
#include <stdexcept>

#include "LayerParser.hpp"
#include "LayerType.hpp"
#include "NetworkLayer.hpp"
#include "CollectResultsLayerParser.hpp"
#include "CollectResultsLayer.hpp"

TEST(LayerParserTest, valid)
{
  std::string in = "inputdim=[1,2,3]";
  auto layer = CollectResultsLayerParser().parse(in);
  EXPECT_EQ(LayerType::COLLECT_RESULTS, layer.getLayerType());
}

TEST(LayerParserTest, invalid)
{
  std::string in = "x=[1,2,3]\nfunction=rel\nalpha=0.2";
  EXPECT_THROW(CollectResultsLayerParser().parse(in), std::invalid_argument);
}

TEST(LayerBackParserTest, valid)
{
  int dim[] = {1, 2, 3};
  auto layer = CollectResultsLayer("name", dim);
  EXPECT_EQ("[collect]\ninputdim=[1,2,3]", CollectResultsLayerParser().parseBack(layer));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}