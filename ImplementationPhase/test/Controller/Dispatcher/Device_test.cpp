#include <gtest/gtest.h>
#include "Device.hpp"

TEST(DeviceTest, ConstructorTest) {
    Device dev = Device("CPU", "Intel i5-4590", 8, 45.0);
    ASSERT_NE(&dev, nullptr);
}

TEST(DeviceTest, testGetter) {
    Device dev = Device("CPU", "Intel i5-4590", 8, 45.0);
    ASSERT_NE(&dev, nullptr);
    EXPECT_EQ(dev.getType(), "CPU");
    EXPECT_EQ(dev.getName(), "Intel i5-4590");
    EXPECT_EQ(dev.getRAM(), 8);
    EXPECT_EQ(dev.getPerformance(), 45.0);
}




int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
