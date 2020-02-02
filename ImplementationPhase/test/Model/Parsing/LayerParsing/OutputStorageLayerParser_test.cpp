#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>
#include <stdexcept>

#include "LayerParser.hpp"
#include "LayerType.hpp"
#include "NetworkLayer.hpp"
#include "OutputStorageLayer.hpp"
#include "OutputStorageLayerParser.hpp"

TEST(LayerParserTest, valid)
{
  std::string in = "inputdim=[1,2,3]\ndata=[[[1]]]";
  auto layer = OutputStorageLayerParser().parse(in);
  EXPECT_EQ(LayerType::OUTPUT_STORAGE, layer.getLayerType());
}

TEST(LayerParserTest, invalid)
{
  std::string in = "inputdim=[1,2,3]\ndat=[[[1]]]";
  EXPECT_THROW(OutputStorageLayerParser().parse(in), std::invalid_argument);
}

TEST(LayerBackParserTest, valid)
{
  int dim[] = {1, 2, 3};
  auto data = std::vector<std::vector<std::vector<float>>>();
  auto sub1 = std::vector<std::vector<float>>();
  auto sub2 = std::vector<float>();
  sub2.push_back(1);
  sub1.push_back(sub2);
  data.push_back(sub1);
  auto layer = OutputStorageLayer("", data, dim);
  EXPECT_EQ("[output_storage]\ninputdim=[1,2,3]\ndata=[[[1]]]", OutputStorageLayerParser().parseBack(layer));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}