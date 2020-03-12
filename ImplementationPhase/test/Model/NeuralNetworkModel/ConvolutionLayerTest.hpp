#include <gtest/gtest.h>
#include "ConvolutionLayer.hpp"

struct ConvolutionTest : testing::Test
{

	ConvolutionLayer* layer;

	ConvolutionTest() {
		layer = new ConvolutionLayer(TENSOR(float){{{{.3f, 0.5f}}}}, 1, 0);
	}

	~ConvolutionTest() {
		delete layer;
	}

};

TEST_F(ConvolutionTest, ConvolutionForwardTest)
{
    TENSOR(float) input = TENSOR(float){{{{1,2,3}}}};
    TENSOR(float) output = layer->forward(input);
    TENSOR(float) expectedOutput = TENSOR(float){{{{1.3f, 2.1f}}}};
    for (int b = 0; b < output[0].size(); b++) {
        for (int z = 0; z < output[0].size(); z++) {
            for (int y = 0; y < output[0][0].size(); y++) {
                for (int x = 0; x < output[0][0][0].size(); x++) {
                    EXPECT_EQ(output[b][z][y][x], expectedOutput[b][z][y][x]);
                }
            }
        }
    }
}

TEST_F(ConvolutionTest, ConvolutionBackwardTest)
{
    TENSOR(float) input = TENSOR(float){{{{1,2,3}}}};
    layer->forward(input);
    TENSOR(float) feedback = TENSOR(float){{{{-0.1f, 0.2f}}}};
    TENSOR(float) output = layer->backprob(feedback, 0.1f);
    TENSOR(float) expectedOutput = TENSOR(float){{{{-0.03f,0.01f,0.1f}}}};
    for (int b = 0; b < output[0].size(); b++) {
        for (int z = 0; z < output[0].size(); z++) {
            for (int y = 0; y < output[0][0].size(); y++) {
                for (int x = 0; x < output[0][0][0].size(); x++) {
                    EXPECT_EQ(output[b][z][y][x], expectedOutput[b][z][y][x]);
                }
            }
        }
    }
}
