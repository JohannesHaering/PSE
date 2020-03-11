#include <gtest/gtest.h>
#include "MaxPoolLayer.hpp"

struct MaxPoolTest : testing::Test
{

	MaxPoolLayer* maxLayer;

	MaxPoolTest() {
		maxLayer = new MaxPoolLayer();
	}

	~MaxPoolTest() {
		delete maxLayer;
	}

};

TEST_F(MaxPoolTest, MaxPoolForwardTest)
{
    TENSOR(float) input = TENSOR(float){{{{1,2,1,0}, {0,2,0,0}, {1,2,0,0}, {0,0,0,3}}}};
    TENSOR(float) output = maxLayer->forward(input);
    TENSOR(float) expectedOutput = TENSOR(float){{{{2,2}, {2,3}}}};
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

TEST_F(MaxPoolTest, MaxPoolBackwardTest)
{
    TENSOR(float) input = TENSOR(float){{{{1,2,1,0}, {0,2,0,0}, {1,2,0,0}, {0,0,0,3}}}};
    maxLayer->forward(input);
    TENSOR(float) feedback = TENSOR(float){{{{2,2}, {2,3}}}};
    TENSOR(float) output = maxLayer->backprob(feedback, 0.1f);
    TENSOR(float) expectedOutput = TENSOR(float){{{{0,1 + 1/3,0,0}, {0,2 + 1/3,0,0}, {0,2 + 1/3,0,0}, {0,0,0,3}}}};
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
