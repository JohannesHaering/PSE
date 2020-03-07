#include <string>
#include <list>
#include <gtest/gtest.h>

#include "Parser.hpp"
#include "LineBreakParser_test.hpp"

TEST(SplitSymbolTest, twoParts)
{
  Parser<std::string> parser = Parser<std::string>();
  std::string in = "foo/bar";
  std::list<std::string> out = parser.splitBySymbol(in, "/");
  EXPECT_EQ(2, out.size());
  std::string val1 = *out.begin();
  std::string val2 = *(--out.end());
  EXPECT_EQ("foo", val1);
  EXPECT_EQ("bar", val2);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
