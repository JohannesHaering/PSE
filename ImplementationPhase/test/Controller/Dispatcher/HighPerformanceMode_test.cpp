#include <gtest/gtest.h>
#include "HighPerformanceMode.hpp"
#include "Mode.hpp"

TEST(HPModeTest, ConstructorTest) {
    Mode * hpMode = new HighPerformanceMode();
    ASSERT_NE(hpMode, nullptr);
}

TEST(HPModeTest, testGetter) {
    Mode * hpMode = new HighPerformanceMode();
    ASSERT_NE(hpMode, nullptr);
    //EXPECT_EQ();
}




int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
