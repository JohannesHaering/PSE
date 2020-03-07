#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "DenseLayer.hpp"
#include "DenseLayerFactory.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "MatrixDefine.hpp"

TEST(DenseBuildTest, valid)
{
    MATRIX_2D(float) weights = MATRIX_2D(float)(5, std::vector<float>(5));
    std::vector<float> biases = std::vector<float>(5);
 NetworkLayer* layer = DenseLayerFactory().setMatrix(weights)->setBiases(biases)->buildLayer();
  EXPECT_EQ(LayerType::DENSE, layer->getLayerType());
}
