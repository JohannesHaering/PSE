#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>
#include <stdexcept>

#include "LayerParser.hpp"
#include "LayerType.hpp"
#include "NetworkLayer.hpp"
#include "DenseLayerParser.hpp"
#include "DenseLayer.hpp"

TEST(LayerParserTest, valid)
{
  std::string in = "inputdim=[1,2,3]\ntensor=[[1]]";
  auto layer = DenseLayerParser().parse(in);
  EXPECT_EQ(LayerType::DENSE, layer.getLayerType());
}

TEST(LayerParserTest, invalid)
{
  std::string in = "inputdim=[1,2,3]\nteor=[[1]]";
  EXPECT_THROW(DenseLayerParser().parse(in), std::invalid_argument);
}

TEST(LayerBackParserTest, valid)
{
  int dim[] = {1, 2, 3};
  auto tensor = std::vector<std::vector<float>>();
  auto sub1 = std::vector<float>();
  sub1.push_back(1);
  tensor.push_back(sub1);
  auto layer = DenseLayer("", dim, tensor);
  EXPECT_EQ("[dense]\ninputdim=[1,2,3]\ntensor=[[1.000000]]\n", DenseLayerParser().parseBack(layer));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}