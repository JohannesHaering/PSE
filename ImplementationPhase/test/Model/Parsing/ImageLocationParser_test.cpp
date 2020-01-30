#include <string>
#include <list>
#include <gtest/gtest.h>

#include "ImageLocationParser.hpp"

TEST (SplitLinesTest, twoParts) {
    ImageLocationParser parser = ImageLocationParser();
    auto in = "foo\nbar";
    auto out = parser.parse(in);
    EXPECT_EQ(2, out.size());
    EXPECT_EQ("foo", *out.begin());
    EXPECT_EQ("bar", *out.end());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
