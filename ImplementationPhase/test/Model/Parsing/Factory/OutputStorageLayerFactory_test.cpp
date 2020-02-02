#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "OutputStorageLayerFactory.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"

TEST(BuildTest, valid)
{
  int dim[] = {1, 2, 3};
  std::string name = "nn";
  std::vector<std::vector<std::vector<float>>> data = std::vector<std::vector<std::vector<float>>>();
  std::vector<std::vector<float>> sub1 = std::vector<std::vector<float>>();
  std::vector<float> sub2 = std::vector<float>();
  sub2.push_back(1);
  sub1.push_back(sub2);
  data.push_back(sub1);

  auto layer = OutputStorageLayerFactory().setData(data).setInputDimensions(dim)->setName(name)->buildLayer();
  EXPECT_EQ(LayerType::OUTPUT_STORAGE, layer.getLayerType());
  EXPECT_EQ(name, layer.getName());
  EXPECT_EQ(dim, layer.getInputDimensions());
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}