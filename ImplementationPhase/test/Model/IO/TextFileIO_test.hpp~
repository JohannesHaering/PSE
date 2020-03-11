#define TESTDIR _TESTDIR

#include "TextFileIO.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Data.hpp"

TEST(readTextFileTest, emptyPath){
    auto io = TextFileIO();
    auto input = io.readFile("");
    EXPECT_EQ("", input.getData());
}

TEST(readTextFileTest, file){
    auto io = TextFileIO();
    auto input = io.readFile(TESTDIR + "readdir\\testTXTRead.txt");
    EXPECT_EQ("foo\n", input.getData());
}

TEST(readTextFileTest, noTextFile){
    auto io = TextFileIO();
    auto input = io.readFile(TESTDIR + "readdir\\testBMP.bmp");
    EXPECT_EQ("", input.getData());
}

TEST(readTextFileTest, notExisting) {
  auto io = TextFileIO();
  auto input = io.readFile(TESTDIR + "readdir\\NotExisting.txt");
  EXPECT_EQ("", input.getData());
}
TEST(writeTextFileTest, emptyPath){
    auto io = TextFileIO();
    auto success = io.writeFile("", Data<std::string>("foo"));
    EXPECT_EQ(false, success);
}
TEST(writeTextFileTest, emptyData){
    auto io = TextFileIO();
    auto success = io.writeFile(TESTDIR + "\\writedir\\testTXT.txt", Data<std::string>(""));
    EXPECT_EQ(false, success);
}

TEST(writeTextFileTest, file){
    auto io = TextFileIO();
    auto success = io.writeFile(TESTDIR + "\\writedir\\testTXT.txt", Data<std::string>("foo"));
    EXPECT_EQ(true, success);
}

TEST(writeTextFileTest, noTextFile){
    auto io = TextFileIO();
    auto success = io.writeFile(TESTDIR + "\\writedir\\testBMP.bmp", Data<std::string>("foo"));
    EXPECT_EQ(false, success);
}