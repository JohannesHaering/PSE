#include <gtest/gtest.h>
#include <string>
#include <stdexcept>
#include <list>

#include "BoundingBoxParser.hpp"
#include "BoundingBox.hpp"
#include "ClassProbability.hpp"

TEST(ParseTest, valid)
{
    auto in = "0.2$0.3$0.4$0.5$name1:1/name2:0";
    auto out = BoundingBoxParser().parse(in);
    EXPECT_EQ(0.2f, out.getX());
    EXPECT_EQ(0.3f, out.getY());
    EXPECT_EQ(0.4f, out.getWidth());
    EXPECT_EQ(0.5f, out.getHeight());
    EXPECT_EQ(out.getProbabilities().size(), 2);
}

TEST(ParseTest, invalid)
{
    auto in = "0.2$0.3$0.4$name1:1/name2:0";
    EXPECT_THROW(BoundingBoxParser().parse(in), std::invalid_argument);
}

TEST(ParseBackTest, valid)
{
    auto list = std::list<ClassProbability>();
    list.push_back(ClassProbability("name", 1));
    auto out = BoundingBoxParser().parseBack(BoundingBox(0.2f, 0.3f, 0.4f, 0.5f, list));
    EXPECT_EQ("0.2$0.3$0.4$0.5$name1:1", out);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}