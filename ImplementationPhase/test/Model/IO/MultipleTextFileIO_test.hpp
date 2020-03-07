#include "MultipleTextFileIO.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Data.hpp"
#include <list>

TEST(readTextFilesTest, emptyPath)
{
    auto io = MultipleTextFileIO();
    auto paths = std::list<std::string>();
    paths.push_back("");
    auto input = io.readFile(paths);
    EXPECT_EQ("", *(input.getData().begin()));
}

TEST(readTextFilesTest, file)
{
    auto io = MultipleTextFileIO();
    auto paths = std::list<std::string>();
    paths.push_back("C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\testTXTRead.txt");
    auto input = io.readFile(paths);
    EXPECT_EQ("foo\n", *(input.getData().begin()));
}

TEST(readTextFilesTest, noTextFile)
{
    auto io = MultipleTextFileIO();
    auto paths = std::list<std::string>();
    paths.push_back("C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\testBMP.bmp");
    auto input = io.readFile(paths);
    EXPECT_EQ("", *(input.getData().begin()));
}

TEST(writeTextFilesTest, emptyPath)
{
    auto io = MultipleTextFileIO();
    auto paths = std::list<std::string>();
    paths.push_back("");
    auto strings = std::list<std::string>();
    strings.push_back("foo");
    auto success = io.writeFile(paths, Data<std::list<std::string>>(strings));
    EXPECT_EQ(false, success);
}

TEST(writeTextFilesTest, emptyData)
{
    auto io = MultipleTextFileIO();
    auto paths = std::list<std::string>();
    paths.push_back("C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\testTXT.txt");
    auto strings = std::list<std::string>();
    strings.push_back("");
    auto success = io.writeFile(paths,Data<std::list<std::string>>(strings));
    EXPECT_EQ(false, success);
}

TEST(writeTextFilesTest, file)
{
    auto io = MultipleTextFileIO();
    auto paths = std::list<std::string>();
    paths.push_back("C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\testTXTWrite.txt");
    auto strings = std::list<std::string>();
    strings.push_back("foo");
    auto success = io.writeFile(paths,Data<std::list<std::string>>(strings));
    EXPECT_EQ(true, success);
}

TEST(writeTextFilesTest, noTextFile)
{
    auto io = MultipleTextFileIO();
    auto paths = std::list<std::string>();
    paths.push_back("C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\testBMP.bmp");
    auto strings = std::list<std::string>();
    strings.push_back("foo");
    auto success = io.writeFile(paths, Data<std::list<std::string>>(strings));
    EXPECT_EQ(false, success);
}