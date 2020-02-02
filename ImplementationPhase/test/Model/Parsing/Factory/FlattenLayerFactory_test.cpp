#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "FlattenLayerFactory.hpp"
#include "FlattenLayer.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"

TEST(BuildTest, valid)
{
  int dim[] = {1, 2, 3};
  std::string name = "nn";
  auto layer = FlattenLayerFactory().setName(name)->setInputDimensions(dim)->buildLayer();
  EXPECT_EQ(LayerType::FLATTEN, layer.getLayerType());
  EXPECT_EQ(name, layer.getName());
  EXPECT_EQ(dim, layer.getInputDimensions());
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}