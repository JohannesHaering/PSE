#include <string>
#include <list>
#include <gtest/gtest.h>

#include "Parser.hpp"

TEST (SplitSymbolTest, twoParts) {
    Parser<std::string> parser = Parser<std::string>();
    auto in = "foo/bar";
    auto out = parser.splitBySymbol(in, "/");
    EXPECT_EQ(2, out.size());
	auto val1 = *out.begin();
	auto val2 = *(--out.end());
    EXPECT_EQ("foo", val1);
    EXPECT_EQ("bar", val2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
