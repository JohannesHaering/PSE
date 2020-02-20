#include <gtest/gtest.h>
#include <random>
#include "NeuralNetwork.hpp"
 #include <iostream>

struct NetworkLayerASICTest : public ::testing::Test {
  NetworkLayer *testLayer;
  void SetUp() {
//      testNetwork = new NeuralNetwork();
  }
  void TearDown() {
    // std::cout<<testNetwork->getLayerCount();
    delete testLayer;
  }
};



TEST_F(NetworkLayerASICTest, ReLuLayerASICTest) {

    testLayer = new ReLuLayer();
    TENSOR(float) input = {
            {   {   {1, 2, 3},
                    {1, -2, 3},
                    {-1, 2, 3},
                    {1, 2, 3}   },
                {   {1, 2, -3},
                    {1, 2, 3},
                    {-1, 2, 3},
                    {1, 2, 3}},
                {   {1, 2, 3},
                    {1, -2, 3},
                    {1, 2, 3},
                    {1, -2, 3}   }   },
            {   {   {1, 2, 3},
                    {1, 2, 3},
                    {1, 2, 3},
                    {1, 2, 3}},
                {   {-1, 2, 3},
                    {1, 2, 3},
                    {1, 2, 3},
                    {1, 2, -3}},
                {   {1, 2, 3},
                    {1, 2, 3},
                    {1, -2, 3},
                    {1, 2, 3}   }   }
    };
    testLayer->setMode(DeviceType::ASIC);
    TENSOR(float) output = testLayer->forward(input);
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[0].size(); j++) {
            for (int k = 0; k < input[0][0].size(); k++) {
                for (int l = 0; l < input[0][0][0].size(); l++) {
                    EXPECT_EQ(input[i][j][k][l] < 0 ? 0 :  input[i][j][k][l], output[i][j][k][l]);
                }
            }
        }
    }
}

// int main(int argc, char **argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }
