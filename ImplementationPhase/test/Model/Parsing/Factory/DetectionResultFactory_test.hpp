#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>

#include "BoundingBoxFactory.hpp"
#include "ClassProbability.hpp"
#include "DetectionResultFactory.hpp"
#include "BoundingBox.hpp"
#include "DetectionResult.hpp"

TEST(DetectionResultFactoryTest, valid)
{
  std::list<ClassProbability> probabilities = std::list<ClassProbability>();
  probabilities.push_back(ClassProbability("name", 0.1));
  BoundingBox boundingBox = BoundingBoxFactory().build(0.1, 0.1, 0.1, 0.1, probabilities);
  EXPECT_NEAR(0.1, boundingBox.getX(), 0.001);
  EXPECT_NEAR(0.1, boundingBox.getY(), 0.001);
  EXPECT_NEAR(0.1, boundingBox.getWidth(),0.001);
  EXPECT_NEAR(0.1, boundingBox.getHeight(), 0.001);
  EXPECT_EQ(probabilities.size(), boundingBox.getProbabilities().size());
  std::list<BoundingBox> bbs = std::list<BoundingBox>();
  bbs.push_back(boundingBox);
  DetectionResult result = DetectionResultFactory().build("i", "nn", bbs);
  EXPECT_EQ("i", result.getImageID());
  EXPECT_EQ("nn", result.getNeuralNetworkID());
  EXPECT_EQ(bbs.size(), result.getBoundingBoxes().size());
}
