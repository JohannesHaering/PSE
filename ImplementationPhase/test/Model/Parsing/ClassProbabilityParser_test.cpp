#include <gtest/gtest.h>
#include <string>
#include <stdexcept>

#include "ClassProbabilityParser.hpp"
#include "ClassProbability.hpp"

TEST(ClassProbabilityParseTest, correctBox)
{
    std::string toParse = "name:1";
    ClassProbability out = ClassProbabilityParser().parse(toParse);
    EXPECT_EQ(out.getClassName(), "name");
    EXPECT_EQ(out.getProbability(), 1);
}

TEST(ClassProbabilityParseTest, notValid)
{
    std::string toParse = "name1";
    EXPECT_THROW(ClassProbabilityParser().parse(toParse), std::invalid_argument);
}

TEST(ClassProbabilityParseBackTest, valid)
{
    ClassProbability in = ClassProbability("name", 1);
    EXPECT_EQ("name:1.000000", ClassProbabilityParser().parseBack(in));
}