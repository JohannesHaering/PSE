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

TEST(LayerParserTest, valid)
{
  std::string in = "inputdim=[1,2,3]\nfunction=relu\nalpha=0.2";
  auto layer = ActivationLayerParser().parse(in);
  EXPECT_EQ(LayerType::ACTIVATION, layer.getLayerType());
}

TEST(LayerParserTest, invalid)
{
  std::string in = "x=[1,2,3]\nfunction=rel\nalpha=0.2";
  EXPECT_THROW(ActivationLayerParser().parse(in), std::invalid_argument);
}

TEST(LayerBackParserTest, valid)
{
  int dim[] = {1, 2, 3};
  auto layer = ActivationLayer("name", dim, Activation::LEAKING_RELU, 0.2);
  auto out = ActivationLayerParser().parseBack(layer);
  EXPECT_EQ("[activation]\ninputdim=[1,2,3]\nfunction=lrelu\nalpha=0.200000\n", out);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}