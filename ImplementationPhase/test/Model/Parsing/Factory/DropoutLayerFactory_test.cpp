#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "DropoutLayer.hpp"
#include "DropoutLayerFactory.hpp"

TEST(BuildTest, valid)
{
  int dim[] = {1, 2, 3};
  std::string name = "nn";
  auto layer = DropoutLayerFactory().setDropoutRate(0.5).setInputDimensions(dim)->setName(name)->buildLayer();
  EXPECT_EQ(LayerType::DROPOUT, layer.getLayerType());
  EXPECT_EQ(name, layer.getName());
  EXPECT_EQ(dim[0], layer.getInputDimensions()[0]);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}