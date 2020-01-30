#include <string>
#include <list>
#include <gtest/gtest.h>

#include "Parser.hpp"

TEST (SplitSymbolTest, twoParts) {
    Parser<std::string> parser = Parser<std::string>();
    auto in = "foo/bar";
    auto out = parser.splitBySymbol(in, "/");
    EXPECT_EQ(2, out.size());
    EXPECT_EQ("foo", *out.begin());
    EXPECT_EQ("bar", *out.end());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
