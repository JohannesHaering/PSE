#include <gtest/gtest.h>
#include "Result.hpp"

TEST(ResultTest, ImageIDGetter) {
    Result res("FOO", "BAR");
    EXPECT_EQ(res.getImageID(), "FOO");
}

TEST(ResultTest, NNGetter) {
    Result res("A", "B");
    EXPECT_EQ(res.getNeuralNetworkID(), "B");
}
