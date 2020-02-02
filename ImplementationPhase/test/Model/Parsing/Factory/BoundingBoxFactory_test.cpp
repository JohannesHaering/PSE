#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>

#include "BoundingBoxFactory.hpp"
#include "ClassProbability.hpp"

TEST (FactoryTest, valid){
    auto probabilities = std::list<ClassProbability>();
    probabilities.push_back(ClassProbability("name", 0.1));
    auto boundingBox = BoundingBoxFactory().build(0.1, 0.1, 0.1, 0.1, probabilities);
    EXPECT_EQ(0.1, boundingBox.getX());
    EXPECT_EQ(0.1, boundingBox.getY());
    EXPECT_EQ(0.1, boundingBox.getWidth());
    EXPECT_EQ(0.1, boundingBox.getHeight());
    EXPECT_EQ(probabilities, boundingBox.getProbabilities());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
