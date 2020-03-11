#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "FlattenLayerFactory.hpp"
#include "FlattenLayer.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"

TEST(FlattenBuildTest, valid)
{
  NetworkLayer* layer = FlattenLayerFactory().buildLayer();
  EXPECT_EQ(LayerType::FLATTEN, layer->getLayerType());
}
