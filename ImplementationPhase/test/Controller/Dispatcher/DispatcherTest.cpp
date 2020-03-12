#include <gtest/gtest.h>

#include "Device_test.hpp"
#include "DispatchManager_test.hpp"
#include "Executor_test.hpp"
#include "HighPerformanceMode_test.hpp"

#include "Device.hpp"
#include "DispatchManager.hpp"
#include "Executor.hpp"
#include "HighPerformanceMode.hpp"

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
