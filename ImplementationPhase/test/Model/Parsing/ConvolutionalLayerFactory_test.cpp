#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "ConvolutionalLayerFactory.hpp"

TEST(BuildTest, valid){
    int dim[] = {1,2,3};
    std::string name = "nn";
    std::vector<std::vector<std::vector<std::vector<float>>>> weights =std::vector<std::vector<std::vector<std::vector<float>>>>();
    std::vector<std::vector<std::vector<float>>> sub1 = std::vector<std::vector<std::vector<float>>>();
    std::vector<std::vector<float>> sub2 = std::vector<std::vector<float>>();
    std::vector<float> sub3 = std::vector<float>();
    sub3.push_back(1);
    sub2.push_back(sub3);
    sub1.push_back(sub2);
    weights.push_back(sub1);
    auto layer = ConvolutionalLayerFactory().setPadding(1).setStride(1).setWeightTensors(weights).setInputDimensions(dim).setName(name).buildLayer();
    EXPECT_EQ(LayerType::CONVOLUTION, layer.getLayerType());
    EXPECT_EQ(name, layer.getName());
    EXPECT_EQ(dim, layer.getInputDimensions());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}