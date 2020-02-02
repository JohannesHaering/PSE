#include "MultipleTextFileIO.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Data.hpp"
#include <list>

TEST(readFileTest, emptyPath)
{
    auto io = MultipleTextFileIO();
    auto paths = std::list<std::string>();
    paths.push_back("");
    auto input = io.readFile(paths);
    EXPECT_EQ("", *(input.getData().begin()));
}

TEST(readFileTest, file)
{
    auto io = MultipleTextFileIO();
    auto paths = std::list<std::string>();
    paths.push_back("C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\testTXT.txt");
    auto input = io.readFile(paths);
    EXPECT_EQ("foo\n", *(input.getData().begin()));
}

TEST(readFileTest, noTextFile)
{
    auto io = MultipleTextFileIO();
    auto paths = std::list<std::string>();
    paths.push_back("C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\testBMP.bmp");
    auto input = io.readFile(paths);
    EXPECT_EQ("", *(input.getData().begin()));
}

TEST(writeFileTest, emptyPath)
{
    auto io = MultipleTextFileIO();
    auto paths = std::list<std::string>();
    paths.push_back("");
    auto strings = std::list<std::string>();
    strings.push_back("foo");
    auto success = io.writeFile(paths, Data<std::list<std::string>>(strings));
    EXPECT_EQ(false, success);
}

TEST(writeFileTest, emptyData)
{
    auto io = MultipleTextFileIO();
    auto paths = std::list<std::string>();
    paths.push_back("C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\testTXT.txt");
    auto strings = std::list<std::string>();
    strings.push_back("");
    auto success = io.writeFile(paths,Data<std::list<std::string>>(strings));
    EXPECT_EQ(false, success);
}

TEST(writeFileTest, file)
{
    auto io = MultipleTextFileIO();
    auto paths = std::list<std::string>();
    paths.push_back("C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\testTXT.txt");
    auto strings = std::list<std::string>();
    strings.push_back("foo");
    auto success = io.writeFile(paths,Data<std::list<std::string>>(strings));
    EXPECT_EQ(true, success);
}

TEST(writeFileTest, noTextFile)
{
    auto io = MultipleTextFileIO();
    auto paths = std::list<std::string>();
    paths.push_back("C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\testBMP.bmp");
    auto strings = std::list<std::string>();
    strings.push_back("foo");
    auto success = io.writeFile(paths, Data<std::list<std::string>>(strings));
    EXPECT_EQ(false, success);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}