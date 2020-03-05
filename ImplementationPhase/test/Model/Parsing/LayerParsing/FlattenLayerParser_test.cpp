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
  std::string in = "";
  NeuralNetworkLayer* layer = FlattenLayerParser().parse(in);
  EXPECT_EQ(LayerType::FLATTEN, layer->getLayerType());
}

TEST(LayerBackParserTest, valid)
{
   FlattenLayer* layer = new FlattenLayer();
   EXPECT_EQ("[flatten]\n", FlattenLayerParser().parseBack(layer));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
