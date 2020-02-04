#include <gtest/gtest.h>
#include <random>
#include "NeuralNetwork.hpp"
// #include <iostream>
// #include "ConvolutionLayer.hpp"

struct NeuralNetworkTest : public ::testing::Test {
  NeuralNetwork *testNetwork;
  void SetUp() { testNetwork = new NeuralNetwork(); }
  void TearDown() {
    // std::cout<<testNetwork->getLayerCount();
    delete testNetwork;
  }
};

TEST_F(NeuralNetworkTest, DefaultName) {
  EXPECT_STREQ(testNetwork->getName().c_str(), "Default_Network_Name");
}

TEST_F(NeuralNetworkTest, AddConvolutionalLayer) {

  float lower_bound = 0;
  float upper_bound = 10;
  std::uniform_real_distribution<float> unif(lower_bound,upper_bound);
  std::default_random_engine re;

  TENSOR(float) testTensor(4);

  for (int i = 0; i < testTensor.size(); i++) {
    testTensor[i].resize(4);
    for (int j = 0; j < testTensor[i].size(); j++) {
      testTensor[i][j].resize(4);
      for (int k = 0; k < testTensor[i][j].size(); k++) {
        testTensor[i][j][k].resize(4);
        for (int l = 0; l < testTensor[i][j][k].size(); l++) {
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
  delete testConvolutionLayer;
}

TEST_F(NeuralNetworkTest, AddActivationLayer) {

  // testNetwork->addLayer(new ActivationLayer());
  testNetwork->addLayer(new ActivationLayer("testActivation", new int[3] {3, 3, 3}, Activation::LEAKING_RELU, 0.5));
  NetworkLayer *testLayer = testNetwork->getFirstLayer();
  ASSERT_EQ(testLayer->getLayerType(), LayerType::ACTIVATION);
  ActivationLayer *testActivationLayer = dynamic_cast<ActivationLayer*>(testLayer);
  EXPECT_STREQ(testActivationLayer->getName().c_str(), "testActivation");
  EXPECT_EQ(testActivationLayer->getInputDimensions()[0], 3);
  EXPECT_EQ(testActivationLayer->getInputDimensions()[1], 3);
  EXPECT_EQ(testActivationLayer->getInputDimensions()[2], 3);
  ASSERT_EQ(testActivationLayer->getFunction(), Activation::LEAKING_RELU);
  EXPECT_EQ(testActivationLayer->getAlpha(), 0.5);
  delete testActivationLayer;
}

TEST_F(NeuralNetworkTest, AddPollingLayer) {

  testNetwork->addLayer(new PollingLayer());
  // testNetwork->addLayer(new PollingLayer("testActivation", new int[3] {3, 3, 3}, Activation::LEAKING_RELU), 0.5);
  NetworkLayer *testLayer = testNetwork->getFirstLayer();
  ASSERT_EQ(testLayer->getLayerType(), LayerType::POLLING);
  PollingLayer *testPollingLayer = dynamic_cast<PollingLayer*>(testLayer);
  // EXPECT_STREQ(testActivationLayer->getName().c_str(), "testActivation");
  // EXPECT_EQ(testActivationLayer->getInputDimensions()[0], 3);
  // EXPECT_EQ(testActivationLayer->getInputDimensions()[1], 3);
  // EXPECT_EQ(testActivationLayer->getInputDimensions()[2], 3);
  // ASSERT_EQ(testActivationLayer->getFunction(), Activation::LEAKING_RELU);
  // EXPECT_EQ(testActivationLayer->getAlpha, 0.5);
  delete testPollingLayer;
}

TEST_F(NeuralNetworkTest, AddFlattenLayer) {

  testNetwork->addLayer(new FlattenLayer());
  // testNetwork->addLayer(new PollingLayer("testActivation", new int[3] {3, 3, 3}, Activation::LEAKING_RELU), 0.5);
  NetworkLayer *testLayer = testNetwork->getFirstLayer();
  ASSERT_EQ(testLayer->getLayerType(), LayerType::FLATTEN);
  FlattenLayer *testFlattenLayer = dynamic_cast<FlattenLayer*>(testLayer);
  // EXPECT_STREQ(testActivationLayer->getName().c_str(), "testActivation");
  // EXPECT_EQ(testActivationLayer->getInputDimensions()[0], 3);
  // EXPECT_EQ(testActivationLayer->getInputDimensions()[1], 3);
  // EXPECT_EQ(testActivationLayer->getInputDimensions()[2], 3);
  // ASSERT_EQ(testActivationLayer->getFunction(), Activation::LEAKING_RELU);
  // EXPECT_EQ(testActivationLayer->getAlpha, 0.5);
  delete testFlattenLayer;
}

TEST_F(NeuralNetworkTest, MNIST_Test) {

  float lower_bound = 0;
  float upper_bound = 10;
  std::uniform_real_distribution<float> unif(lower_bound,upper_bound);
  std::default_random_engine re;

  // CONV 3x3x1 x8; stride=1; padding=0
  // POLL 2x2; MAX; stride=1;
  // FLATTEN
  // DENSE 13*13*8x10
  // ACTIVATION SOFTMAX

  TENSOR(float) mnistConvTensor(3); // 3x3x1 x8

  for (int i = 0; i < mnistConvTensor.size(); i++) {
    mnistConvTensor[i].resize(3);
    for (int j = 0; j < mnistConvTensor[i].size(); j++) {
      mnistConvTensor[i][j].resize(1);
      for (int k = 0; k < mnistConvTensor[i][j].size(); k++) {
        mnistConvTensor[i][j][k].resize(8);
        for (int l = 0; l < mnistConvTensor[i][j][k].size(); l++) {
          mnistConvTensor[i][j][k][l] = unif(re);
        }
      }
    }
  }

  MATRIX_2D(float) mnistDenseMatrix(13*13*8); // 3x3x1 x8

  for (int i = 0; i < mnistDenseMatrix.size(); i++) {
    mnistDenseMatrix[i].resize(10);
    for (int j = 0; j < mnistDenseMatrix[i].size(); j++) {
      mnistDenseMatrix[i][j] = unif(re);
    }
  }

  NetworkLayer *testLayer = testNetwork->getFirstLayer();
  EXPECT_EQ(testLayer, nullptr);

  testNetwork->addLayer(new ConvolutionLayer());
  testNetwork->addLayer(new ConvolutionLayer("Convolution_3x3x1x8_1_0", new int[3] {28, 28, 1}, mnistConvTensor, 3, 1));
  testNetwork->addLayer(new PollingLayer("MaxPolling_2x2_1", new int[3] {26, 26, 8}, 2, 3, PollingType::MAX));
  testNetwork->addLayer(new FlattenLayer("Flatten", new int[3] {13, 13, 8}));
  testNetwork->addLayer(new DenseLayer("Flatten", new int[3] {13*13*8, 1, 1}, mnistDenseMatrix));
  testNetwork->addLayer(new ActivationLayer("Flatten", new int[3] {10, 1, 1}, Activation::SOFTMAX));

  testLayer = testNetwork->getFirstLayer();
  EXPECT_EQ(testLayer->getLayerType(), LayerType::CONVOLUTION);
  testLayer = testNetwork->getNextLayer();
  EXPECT_EQ(testLayer->getLayerType(), LayerType::POLLING);
  testLayer = testNetwork->getNextLayer();
  EXPECT_EQ(testLayer->getLayerType(), LayerType::FLATTEN);
  testLayer = testNetwork->getNextLayer();
  EXPECT_EQ(testLayer->getLayerType(), LayerType::DENSE);
  testLayer = testNetwork->getNextLayer();
  EXPECT_EQ(testLayer->getLayerType(), LayerType::ACTIVATION);
  testLayer = testNetwork->getNextLayer();
  EXPECT_EQ(testLayer, nullptr);

  testLayer = testNetwork->getLastLayer();
  EXPECT_EQ(testLayer->getLayerType(), LayerType::ACTIVATION);
  testLayer = testNetwork->getPreviousLayer();
  EXPECT_EQ(testLayer->getLayerType(), LayerType::DENSE);
  testLayer = testNetwork->getPreviousLayer();
  EXPECT_EQ(testLayer->getLayerType(), LayerType::FLATTEN);
  testLayer = testNetwork->getPreviousLayer();
  EXPECT_EQ(testLayer->getLayerType(), LayerType::POLLING);
  testLayer = testNetwork->getPreviousLayer();
  EXPECT_EQ(testLayer->getLayerType(), LayerType::CONVOLUTION);
  testLayer = testNetwork->getPreviousLayer();
  EXPECT_EQ(testLayer, nullptr);

  // delete testLayer;
}

// int main(int argc, char **argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }
