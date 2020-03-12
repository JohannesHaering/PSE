#include <gtest/gtest.h>
#include "ClassificationResult.hpp"
#include "ClassProbability.hpp"
#include <list>
#include <string>


//Test with empty ClassProbList, should work 
TEST(ClassificationResultTest, imageIDGetter) {
    std::list<ClassProbability> classProbList = std::list<ClassProbability>();
    ClassificationResult res("TreeImage", "CoolNN", classProbList);
    EXPECT_EQ(res.getImageID(), "TreeImage");
}

TEST(ClassificationResultTest, NNGetter) {
    std::list<ClassProbability> anotherClassProbList = std::list<ClassProbability>();
    ClassificationResult res("HouseImage", "FancyNN", anotherClassProbList);
    EXPECT_EQ(res.getNeuralNetworkID(), "FancyNN");
}

//Test with ClassProbList beeing empty, should return 0
TEST(ClassificationResultTest, emptyListGetter) {
    std::list<ClassProbability> thirdClassProbList;
    ClassificationResult res("HouseImage", "FancyNN", thirdClassProbList);
    EXPECT_EQ(res.getProbabilities().size(), 0);
}

TEST(ClassificationResultTest, filledListGetter) {
    std::list<ClassProbability> fourthClassProbList;
    fourthClassProbList.push_back(ClassProbability("house", 0.85f));
    fourthClassProbList.push_back(ClassProbability("Tree", 0.1f));
    ClassificationResult res("HouseImage", "FancyNN", fourthClassProbList);
    EXPECT_EQ(res.getProbabilities().size(), 2);
}
