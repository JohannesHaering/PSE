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

TEST(FlattenLayerParserTest, valid)
{
  std::string in = "";
NetworkLayer* layer = FlattenLayerParser().parse(in);
  EXPECT_EQ(LayerType::FLATTEN, layer->getLayerType());
}

TEST(FlattenLayerBackParserTest, valid)
{
   FlattenLayer* layer = new FlattenLayer();
   EXPECT_EQ("[flatten]\n", FlattenLayerParser().parseBack(layer));
}
