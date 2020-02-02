#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "LayerType.hpp"
#include "NetworkLayer.hpp"
#include "PollingLayerFactory.hpp"
#include "PollingType.hpp"

TEST(BuildTest, valid)
{
  int dim[] = {1, 2, 3};
  std::string name = "nn";
  auto layer = PollingLayerFactory().setSize(2).setStride(2).setType(PollingType::AVERAGE).setInputDimensions(dim)->setName(name)->buildLayer();
  EXPECT_EQ(LayerType::POLLING, layer.getLayerType());
  EXPECT_EQ(name, layer.getName());
  EXPECT_EQ(dim, layer.getInputDimensions());
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}