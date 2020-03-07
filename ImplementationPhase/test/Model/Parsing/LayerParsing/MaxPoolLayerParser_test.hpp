#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>
#include <stdexcept>

#include "LayerParser.hpp"
#include "LayerType.hpp"
#include "NetworkLayer.hpp"
#include "MaxPoolLayerParser.hpp"
#include "MaxPoolLayer.hpp"

TEST(LayerParserTest, valid)
{
  std::string in = "";
NetworkLayer* layer = MaxPoolLayerParser().parse(in);
  EXPECT_EQ(LayerType::POLLING, layer->getLayerType());
}

TEST(LayerBackParserTest, valid)
{
   MaxPoolLayer* layer = new MaxPoolLayer();
   EXPECT_EQ("[maxpool]\n", MaxPoolLayerParser().parseBack(layer));
}
