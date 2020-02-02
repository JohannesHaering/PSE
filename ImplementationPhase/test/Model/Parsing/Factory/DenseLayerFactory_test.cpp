#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "DenseLayer.hpp"
#include "DenseLayerFactory.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"

TEST(BuildTest, valid)
{
  int dim[] = {1, 2, 3};
  std::string name = "nn";
  std::vector<std::vector<float>> matrix = std::vector<std::vector<float>>();
  std::vector<float> sub = std::vector<float>();
  sub.push_back(1);
  matrix.push_back(sub);
  auto layer = DenseLayerFactory().setMatrix(matrix).setInputDimensions(dim)->setName(name)->buildLayer();
  EXPECT_EQ(LayerType::DENSE, layer.getLayerType());
  EXPECT_EQ(name, layer.getName());
  EXPECT_EQ(dim[0], layer.getInputDimensions()[0]);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}