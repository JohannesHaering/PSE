#include <string>
#include <list>
#include <gtest/gtest.h>

#include "ImageLocationParser.hpp"

TEST(ImageLocationParserTest, twoParts)
{
  ImageLocationParser parser = ImageLocationParser();
  std::string in = "foo\nbar";
  std::list<std::string> out = parser.parse(in);
  EXPECT_EQ(2, out.size());
  EXPECT_EQ("foo", *(out.begin()));
  EXPECT_EQ("bar", *(--out.end()));
}