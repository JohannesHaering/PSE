#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>

#include "BoundingBoxFactory.hpp"
#include "ClassProbability.hpp"
#include "BoundingBox.hpp"

TEST(FactoryTest, valid)
{
  std::list<ClassProbability> probabilities = std::list<ClassProbability>();
  probabilities.push_back(ClassProbability("name", 0.1f));
  BoundingBox boundingBox = BoundingBoxFactory().build(0.1f, 0.1f, 0.1f, 0.1f, probabilities);
  EXPECT_NEAR(0.1, boundingBox.getX(), 0.01);
  EXPECT_NEAR(0.1, boundingBox.getY(), 0.01);
  EXPECT_NEAR(0.1, boundingBox.getWidth(), 0.01);
  EXPECT_NEAR(0.1, boundingBox.getHeight(), 0.01);
  EXPECT_EQ(1, boundingBox.getProbabilities().size());
}