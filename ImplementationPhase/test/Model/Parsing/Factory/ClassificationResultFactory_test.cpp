#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>

#include "ClassificationResultFactory.hpp"
#include "ClassProbability.hpp"
#include "ClassificationResult.hpp"

TEST(FactoryTest, valid)
{
  std::list<ClassProbability> probabilities = std::list<ClassProbability>();
  probabilities.push_back(ClassProbability("name", 0.1));
  ClassificationResult *result = ClassificationResultFactory().build("name", "nn", probabilities);
  EXPECT_EQ("name", result->getImageID());
  EXPECT_EQ("nn", result->getNeuralNetworkID());
  EXPECT_EQ(1, result->getProbabilities().size());
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
