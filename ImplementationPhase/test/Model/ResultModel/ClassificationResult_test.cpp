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



    
/* more examples
TEST(InitTest, PositiveNum) { 
    EXPECT_EQ(2, math::add(1, 1));
    EXPECT_EQ(10, math::add(2, 8));
    EXPECT_EQ(100, math::add(50, 50));
}

TEST(MathAddTest, ZeroB) { 
    EXPECT_EQ(1, math::add(1, 0));
    EXPECT_EQ(10, math::add(10, 0));
    EXPECT_EQ(100, math::add(100, 0));
}

TEST(MathSubTest, PositiveNum) { 
    EXPECT_EQ(0, math::sub(1, 1));
    EXPECT_EQ(-6, math::sub(2, 8));
    EXPECT_EQ(100, math::sub(150, 50));
}

TEST(MathSubTest, ZeroB) { 
    EXPECT_EQ(1, math::sub(1, 0));
    EXPECT_EQ(10, math::sub(10, 0));
    EXPECT_EQ(100, math::sub(100, 0));
}

TEST(MathMulTest, PositiveNum) { 
    EXPECT_EQ(1, math::mul(1, 1));
    EXPECT_EQ(16, math::mul(2, 8));
    EXPECT_EQ(1500, math::mul(150, 10));
}

TEST(MathMulTest, ZeroB) { 
    EXPECT_EQ(0, math::mul(1, 0));
    EXPECT_EQ(0, math::mul(10, 0));
    EXPECT_EQ(0, math::mul(100, 0));
}*/

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
