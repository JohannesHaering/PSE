#include <gtest/gtest.h>
#include <random>
#include "NeuralNetwork.hpp"
#include "ConvolutionLayer.hpp"

struct NeuralNetworkTest : public ::testing::Test {
  NeuralNetwork *testNetwork;
  void SetUp() { testNetwork = new NeuralNetwork(); }
  void TearDown() { delete testNetwork; }
};

TEST_F(NeuralNetworkTest, DefaultName) {
  EXPECT_STREQ(testNetwork->getName().c_str(), "Default_Network_Name");
}

TEST_F(NeuralNetworkTest, AddConvolutionalLayer) {

  double lower_bound = 0;
  double upper_bound = 10;
  std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
  std::default_random_engine re;

  TENSOR(double) testTensor(4);

  for (int i = 0; i < 4; i++) {
    testTensor[i].resize(4);
    for (int j = 0; j < 4; j++) {
      testTensor[i][j].resize(4);
      for (int k = 0; k < 4; k++) {
        testTensor[i][j][k].resize(4);
        for (int l = 0; l < 4; l++) {
          testTensor[i][j][k][l] = unif(re);
        }
      }
    }
  }

  // testNetwork->addLayer(new ConvolutionLayer());
  testNetwork->addLayer(new ConvolutionLayer("testConvolution", new int[3] {3, 3, 3}, testTensor, 3, 1));
  NetworkLayer *testLayer = testNetwork->getFirstLayer();
  EXPECT_STREQ(testLayer->getName().c_str(), "testConvolution");
  EXPECT_EQ(testLayer->getInputDimensions()[0], 3);
  EXPECT_EQ(testLayer->getInputDimensions()[1], 3);
  EXPECT_EQ(testLayer->getInputDimensions()[2], 3);
  ASSERT_EQ(testLayer->getLayerType(), LayerType::CONVOLUTION);
  ConvolutionLayer *testConvolutionLayer = dynamic_cast<ConvolutionLayer*>(testLayer);
  EXPECT_EQ(testConvolutionLayer->getTensorDimensions()[0], 4);
  EXPECT_EQ(testConvolutionLayer->getTensorDimensions()[1], 4);
  EXPECT_EQ(testConvolutionLayer->getTensorDimensions()[2], 4);
  EXPECT_EQ(testConvolutionLayer->getTensorDimensions()[3], 4);
  EXPECT_EQ(testConvolutionLayer->getStride(), 3);
  EXPECT_EQ(testConvolutionLayer->getPadding(), 1);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        for (int l = 0; l < 4; l++) {
          EXPECT_EQ(testConvolutionLayer->getWeightsTensor()[i][j][k][l], testTensor[i][j][k][l]);
        }
      }
    }
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
