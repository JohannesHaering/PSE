#pragma once^

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>
#include <stdexcept>

#include "LayerParser.hpp"
#include "LayerType.hpp"
#include "NetworkLayer.hpp"
#include "DenseLayerParser.hpp"
#include "DenseLayer.hpp"

TEST(DenseLayerParserTest, valid)
{
  std::string in = "tensor=[[1]]\nbias=[1]";
  NetworkLayer* layer = DenseLayerParser().parse(in);
  EXPECT_EQ(LayerType::DENSE, layer->getLayerType());
}

TEST(DenseLayerParserTest, invalid)
{
  std::string in = "\nteor=[[1]]";
  EXPECT_THROW(DenseLayerParser().parse(in), std::invalid_argument);
}

TEST(DenseLayerBackParserTest, valid)
{
  auto tensor = std::vector<std::vector<float>>();
  auto sub1 = std::vector<float>();
  sub1.push_back(1);
  tensor.push_back(sub1);
  DenseLayer* layer = new DenseLayer(1,1, 1);
  layer->set_bias(sub1);
  layer->set_weights(tensor);
  EXPECT_EQ("[dense]\ntensor=[[1.000000]]\nbias=[1.000000]\n", DenseLayerParser().parseBack(layer));
}
