#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>

#include "BoundingBoxFactory.hpp"
#include "ClassProbability.hpp"
#include "DetectionResultFactory.hpp"
#include "BoundingBox.hpp"
#include "DetectionResult.hpp"

TEST(FactoryTest, valid)
{
  auto probabilities = std::list<ClassProbability>();
  probabilities.push_back(ClassProbability("name", 0.1));
  auto boundingBox = BoundingBoxFactory().build(0.1, 0.1, 0.1, 0.1, probabilities);
  EXPECT_EQ(0.1, boundingBox.getX());
  EXPECT_EQ(0.1, boundingBox.getY());
  EXPECT_EQ(0.1, boundingBox.getWidth());
  EXPECT_EQ(0.1, boundingBox.getHeight());
  EXPECT_EQ(probabilities, boundingBox.getProbabilities());
  auto bbs = std::list<BoundingBox>();
  bbs.push_back(boundingBox);
  auto result = DetectionResultFactory().build("i", "nn", bbs);
  EXPECT_EQ("i", result.getImageID());
  EXPECT_EQ("nn", result.getNeuralNetworkID());
  EXPECT_EQ(bbs, result.getBoundingBoxes());
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
