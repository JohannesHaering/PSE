#include <string>
#include <list>
#include <gtest/gtest.h>

#include "LineBreakParser.hpp"

TEST (SplitLinesTest, twoParts) {
    LineBreakParser<std::string> parser = LineBreakParser<std::string>();
    std::string in = "foo\nbar";
    std::list<std::string> out = parser.splitIntoLines(in);
    EXPECT_EQ(2, out.size());
    EXPECT_EQ("foo", *out.begin());
    EXPECT_EQ("bar", *(--out.end()));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
