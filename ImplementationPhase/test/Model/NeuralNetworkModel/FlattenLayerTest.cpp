#include <gtest/gtest.h>
#include "FlattenLayer.hpp"

struct FlattenLayerTest : testing::Test
{

	FlattenLayer* maxLayer;

	FlattenLayerTest() {
		layer = new FlattenLayer();
	}

	~FlattenLayerTest() {
		delete layer;
	}

};

TEST_F(FlattenLayerTest, FlattenForwardTest)
{
    TENSOR(float) input = TENSOR(float){{{{1,2,1,0}, {0,2,0,0}, {1,2,0,0}, {0,0,0,3}}}};
    TENSOR(float) output = layer->forward(input);
    TESNOR(float) expectedOutput = TENSOR(float){{{{1,2,1,0,0,2,0,0,1,2,0,0,0,0,0,3}}}};
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

TEST_F(FlattenLayerTest, FlattenForwardTest)
{
    TENSOR(float) input = TENSOR(float){{{{1,2,1,0}, {0,2,0,0}, {1,2,0,0}, {0,0,0,3}}}};
    layer->forward(input);
    TENSOR(float) feedback = TENSOR(float){{{{1,2,1,0,0,2,0,0,1,2,0,0,0,0,0,3}}}};
    TENSOR(float) output = layer->backward(feedback);
    TESNOR(float) expectedOutput = TENSOR(float){{{{1,2,1,0}, {0,2,0,0}, {1,2,0,0}, {0,0,0,3}}}};
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

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}