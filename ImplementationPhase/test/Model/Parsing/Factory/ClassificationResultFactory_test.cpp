#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>

#include "ClassificationResultFactory.hpp"
#include "ClassProbability.hpp"

TEST (FactoryTest, valid){
    auto probabilities = std::list<ClassProbability>();
    probabilities.push_back(ClassProbability("name", 0.1));
    auto result = ClassificationResultFactory().build("name", "nn", probabilities);
    EXPECT_EQ("name", result.getImageID());
    EXPECT_EQ("nn", result.getNeuralNetworkID());
    EXPECT_EQ(probabilities, result.getProbabilities());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
