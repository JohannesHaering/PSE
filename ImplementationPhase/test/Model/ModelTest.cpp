#include <gtest/gtest.h>
#include "IO/IOPackageTest.hpp"
#include "Parsing/ParsingPackageTest.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
