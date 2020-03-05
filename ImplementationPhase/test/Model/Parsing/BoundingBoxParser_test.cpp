#include <gtest/gtest.h>
#include <string>
#include <stdexcept>
#include <list>

#include "BoundingBoxParser.hpp"
#include "BoundingBox.hpp"
#include "ClassProbability.hpp"

TEST(ParseTest, valid)
{
    std::string in = "0.2$0.3$0.4$0.5$name1:1/name2:0";
    BoundingBox out = BoundingBoxParser().parse(in);
    EXPECT_NEAR(0.2f, out.getX(), 0.01);
    EXPECT_NEAR(0.3f, out.getY(), 0.01);
    EXPECT_NEAR(0.4f, out.getWidth(), 0.01);
    EXPECT_NEAR(0.5f, out.getHeight(), 0.01);
    EXPECT_EQ(out.getProbabilities().size(), 2);
}

TEST(ParseTest, invalid)
{
    std::string in = "0.2$0.3$0.4$name1:1/name2:0";
    EXPECT_THROW(BoundingBoxParser().parse(in), std::invalid_argument);
}

TEST(ParseBackTest, valid)
{
    std::list<ClassProbability> list = std::list<ClassProbability>();
    list.push_back(ClassProbability("name", 1));
    std::string out = BoundingBoxParser().parseBack(BoundingBox(0.2f, 0.3f, 0.4f, 0.5f, list));
    EXPECT_EQ("0.200000$0.300000$0.400000$0.500000$name:1.000000", out);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}