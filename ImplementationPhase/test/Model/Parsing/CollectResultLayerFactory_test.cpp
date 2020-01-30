#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "CollectResultsLayer.hpp"
#include "CollectResultsLayerFactory.hpp"


TEST(BuildTest, valid){
    int dim[] = {1,2,3};
    std::string name = "nn";
    auto layer = CollectResultsLayerFactory().setInputDimensions(dim).setName(name).buildLayer();
    EXPECT_EQ(LayerType::COLLECT_RESULTS, layer.getLayerType());
    EXPECT_EQ(name, layer.getName());
    EXPECT_EQ(dim, layer.getInputDimensions());
    
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}