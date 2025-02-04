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

TEST(ActivationLayerParserTest, valid)
{
  std::string in = "function=relu";
  NetworkLayer* layer = ActivationLayerParser().parse(in);
  EXPECT_EQ(LayerType::RELU, layer->getLayerType());
}

TEST(ActivationLayerParserTest, invalid)
{
  std::string in = "x=[1,2,3]\nfunction=reu";
  EXPECT_THROW(ActivationLayerParser().parse(in), std::invalid_argument);
}

TEST(ActivationLayerBackParserTest, valid)
{
  NetworkLayer* layer = new ReLuLayer();
  auto out = ActivationLayerParser().parseBack(layer);
  EXPECT_EQ("[activation]\nfunction=relu\n", out);
}
