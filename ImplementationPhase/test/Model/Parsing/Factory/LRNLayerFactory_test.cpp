#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "LocalResponseNormalizationLayerFactory.hpp"
#include "LocalResponseNormalizationLayer.hpp"
#include "LRNType.hpp"
#include "LayerType.hpp"
#include "NetworkLayer.hpp"

TEST(BuildTest, valid)
{
  int dim[] = {1, 2, 3};
  std::string name = "nn";
  auto layer = LocalResponseNormalizationLayerFactory().setDepth(1).setType(LRNType::INTER_CHANNEL).setName(name)->setInputDimensions(dim)->buildLayer();
  EXPECT_EQ(LayerType::LRN, layer.getLayerType());
  EXPECT_EQ(name, layer.getName());
  EXPECT_EQ(dim, layer.getInputDimensions());
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}