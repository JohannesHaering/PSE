#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>
#include <stdexcept>

#include "LayerParser.hpp"
#include "LayerType.hpp"
#include "NetworkLayer.hpp"
#include "PollingLayer.hpp"
#include "PollingLayerParser.hpp"
#include "PollingType.hpp"

TEST(LayerParserTest, valid1)
{
  std::string in = "inputdim=[1,2,3]\nsize=3\nstride=1\ntype=max";
  auto layer = PollingLayerParser().parse(in);
  EXPECT_EQ(LayerType::POLLING, layer.getLayerType());
}

TEST(LayerParserTest, valid2)
{
  std::string in = "inputdim=[1,2,3]\nsize=3\nstride=1\ntype=average";
  auto layer = PollingLayerParser().parse(in);
  EXPECT_EQ(LayerType::POLLING, layer.getLayerType());
}

TEST(LayerParserTest, invalid1)
{
  std::string in = "inputdim=[1,2,3]\nsze=3\nstride=1\ntype=average";
  EXPECT_THROW(PollingLayerParser().parse(in), std::invalid_argument);
}

TEST(LayerParserTest, invalid2)
{
  std::string in = "inputdim=[1,2,3]\nsize=3\nstide=1\ntype=average";
  EXPECT_THROW(PollingLayerParser().parse(in), std::invalid_argument);
}

TEST(LayerParserTest, invalid3)
{
  std::string in = "inputdim=[1,2,3]\nsize=3\nstride=1\ntye=average";
  EXPECT_THROW(PollingLayerParser().parse(in), std::invalid_argument);
}

TEST(LayerBackParserTest, valid)
{
  int dim[] = {1, 2, 3};
  auto layer = PollingLayer("", dim, 3, 1, PollingType::MAX);
  EXPECT_EQ("[polling]\ninputdim=[1,2,3]\nsize=3\nstride=1\ntype=max", PollingLayerParser().parseBack(layer));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}