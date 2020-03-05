#include <gtest/gtest.h>
#include <stdexcept>
#include "ClassProbability.hpp"


TEST(ClassProbabilityTest, ClassNameGetter) {
    ClassProbability res("FOO", 0.1);
    EXPECT_EQ(res.getClassName(), "FOO");
}

TEST(ClassProbabilityTest, PropZero) {
    ClassProbability res("A", 0.0);
    EXPECT_EQ(res.getProbability(), 0.0);
}

TEST(ClassProbabilityTest, PropOne) {
    ClassProbability res("A", 1.0);
    EXPECT_EQ(res.getProbability(), 1.0);
}

TEST(ClassProbabilityTest, PropNeg) {
    EXPECT_THROW(ClassProbability res("A", -0.1), std::invalid_argument);
}

TEST(ClassProbabilityTest, PropLarge) {
    EXPECT_THROW(ClassProbability res("A", 90.0), std::invalid_argument);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
