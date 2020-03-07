#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>
#include <stdexcept>

#include "LayerParser.hpp"
#include "LayerType.hpp"
#include "NetworkLayer.hpp"
#include "Activation.hpp"
#include "ActivationLayer.hpp"
#include "ActivationLayerParser.hpp"
#include "ReLuLayer.hpp"

TEST(LayerParserTest, valid)
{
  std::string in = "inputdim=[1,2,3]\nfunction=relu";
  NetworkLayer* layer = ActivationLayerParser().parse(in);
  EXPECT_EQ(LayerType::RELU, layer->getLayerType());
}

TEST(LayerParserTest, invalid)
{
  std::string in = "x=[1,2,3]\nfunction=reu";
  EXPECT_THROW(ActivationLayerParser().parse(in), std::invalid_argument);
}

TEST(LayerBackParserTest, valid)
{
  NetworkLayer* layer = new ReLuLayer();
  auto out = ActivationLayerParser().parseBack(layer);
  EXPECT_EQ("[activation]\nfunction=relu\n", out);
}
