#include <gtest/getest.h>

#include "BoundingBox_test.hpp"
#include "ClassificationResult_test.hpp"
#include "ClassProbability_test.hpp"
#include "DetectionResult_test.hpp"
#include "ResultManager_test.hpp"
#include "Result_test.hpp"


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
