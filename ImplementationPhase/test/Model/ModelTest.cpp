#include <gtest/gtest.h>
#include "IOPackageTest.hpp"
#include "ParsingPackageTest.hpp"
#include "ModelFacadepackageTest.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
