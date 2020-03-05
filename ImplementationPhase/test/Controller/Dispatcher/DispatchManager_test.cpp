#include <gtest/gtest.h>
#include "DispatchManager.hpp"
#include "Mode.hpp"
#include "HighPerformanceMode.hpp"

TEST(DispatchManagerTest, emptyConstructor) {
    DispatchManager& mgr = DispatchManager::getInstance();
    Mode * hp = new HighPerformanceMode();
    mgr.setMode(hp);
    ASSERT_NE(mgr.getMode(), nullptr);
    EXPECT_EQ(mgr.getMode(), hp);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
