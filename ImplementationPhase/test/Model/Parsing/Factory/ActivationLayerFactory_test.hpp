#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "ActivationLayer.hpp"
#include "ActivationLayerFactory.hpp"
#include "SoftmaxLayer.hpp"
#include "LeakyReLuLayer.hpp"
#include "ReLuLayer.hpp"
#include "SigmoidLayer.hpp"


TEST(Softmax, valid){
    NetworkLayer* layer = ActivationLayerFactory().setActivation(LayerType::SOFTMAX)->buildLayer();
    EXPECT_EQ(LayerType::SOFTMAX, layer->getLayerType());
}
TEST(Sigmoid, valid){
    NetworkLayer *layer = ActivationLayerFactory().setActivation(LayerType::SIGMOID)->buildLayer();
    EXPECT_EQ(LayerType::SIGMOID, layer->getLayerType());
}
TEST(RELU, valid){
    NetworkLayer *layer = ActivationLayerFactory().setActivation(LayerType::RELU)->buildLayer();
    EXPECT_EQ(LayerType::RELU, layer->getLayerType());
}
TEST(LEAKYRELU, valid){
    NetworkLayer *layer = ActivationLayerFactory().setActivation(LayerType::LEAKYRELU)->buildLayer();
    EXPECT_EQ(LayerType::LEAKYRELU, layer->getLayerType());
}
