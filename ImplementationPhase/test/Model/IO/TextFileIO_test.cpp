#include "TextFileIO.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Data.hpp"

TEST(readFileTest, emptyPath){
    auto io = TextFileIO();
    auto input = io.readFile("");
    EXPECT_EQ("", input.getData());
}

TEST(readFileTest, file){
    auto io = TextFileIO();
    auto input = io.readFile("..\\..\\Data\\testdata\\testTXT.txt");
    EXPECT_EQ("foo", input.getData());
}

TEST(readFileTest, noTextFile){
    auto io = TextFileIO();
    auto input = io.readFile("..\\..\\Data\\testBMP.bmp");
    EXPECT_EQ("", input.getData());
}

TEST(readFileTest, notExisting) {
  auto io = TextFileIO();
  EXPECT_THROW(io.readFile("..\\..\\Data\\NotExisting.txt"), std::ifstream::failure);
}
TEST(writeFileTest, emptyPath){
    auto io = TextFileIO();
    auto success = io.writeFile("", Data<std::string>("foo"));
    EXPECT_EQ(false, success);
}
TEST(writeFileTest, emptyData){
    auto io = TextFileIO();
    auto success = io.writeFile("..\\..\\Data\\testdata\\testTXT.txt", Data<std::string>(""));
    EXPECT_EQ(false, success);
}

TEST(writeFileTest, file){
    auto io = TextFileIO();
    auto success = io.writeFile("..\\..\\Data\\testdata\\testTXT.txt", Data<std::string>("foo"));
    EXPECT_EQ(true, success);
}

TEST(writeFileTest, noTextFile){
    auto io = TextFileIO();
    auto success = io.writeFile("..\\..\\Data\\testBMP.bmp", Data<std::string>("foo"));
    EXPECT_EQ(false, success);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}