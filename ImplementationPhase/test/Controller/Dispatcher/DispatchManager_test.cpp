#include <gtest/gtest.h>
#include "DispatchManager.hpp"
#include "Mode.hpp"
#include "HighPerformanceMode.hpp"
#include "HighEfficiencyMode.hpp"
#include "LowPowerMode.hpp"

TEST(DispatchManagerTest, emptyConstructor) {
    DispatchManager& mgr = DispatchManager::getInstance();
    Mode * hp = new HighPerformanceMode();
    mgr.setMode(hp);
    ASSERT_NE(mgr.getMode(), nullptr);
    EXPECT_EQ(mgr.getMode(), hp);
}

TEST(DispatchManagerTest, setModes) {
    DispatchManager& mgr = DispatchManager::getInstance();
    Mode * hp = new HighPerformanceMode();
    Mode * he = new HighEfficiencyMode();
    Mode * lp = new LowPowerMode();
    mgr.setMode(hp);
    ASSERT_NE(mgr.getMode(), nullptr);
    EXPECT_EQ(mgr.getMode(), hp);
    mgr.setMode(lp);
    ASSERT_NE(mgr.getMode(), nullptr);
    EXPECT_EQ(mgr.getMode(), lp);
    mgr.setMode(he);
    ASSERT_NE(mgr.getMode(), nullptr);
    EXPECT_EQ(mgr.getMode(), he);
}
