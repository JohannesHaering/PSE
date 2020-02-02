#include <gtest/gtest.h>
#include <string>
#include <stdexcept>
#include <list>

#include "ClassificationResultParser.hpp"
#include "ClassificationResult.hpp"
#include "ClassProbability.hpp"

TEST(ParseTest, correctBox)
{
    std::string toParse = "i#nn#name1:1/name2:0";
    auto out = ClassificationResultParser().parse(toParse);
    EXPECT_EQ(out.getImageID(), "i");
    EXPECT_EQ(out.getNeuralNetworkID(), "nn");
    EXPECT_EQ(out.getProbabilities().size(), 2);
}

TEST(ParseTest, notValid)
{
    std::string toParse = "name1";
    EXPECT_THROW(ClassificationResultParser().parse(toParse), std::invalid_argument);
}

TEST(ParseBackTest, valid)
{
    auto list = std::list<ClassProbability>();
    list.push_back(ClassProbability("name1", 1));
    auto in = ClassificationResult("i", "nn", list);
    auto out = ClassificationResultParser().parseBack(in);
    EXPECT_EQ("i#nn#name1:1.000000", out);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}