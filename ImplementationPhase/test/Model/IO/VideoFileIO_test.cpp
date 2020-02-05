#include "VideoFileIO.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Data.hpp"
#include <opencv2/opencv.hpp>
#include <vector>

TEST(readFileTest, emptyPath)
{
	auto io = VideoFileIO();
	auto input = io.readFile("");
	cv::VideoCapture mat = input.getData();
	EXPECT_EQ(false, mat.isOpened());
}

TEST(readFileTest, noImageFile)
{
	auto io = VideoFileIO();
	auto input = io.readFile("..\\..\\Data\\testTXT.txt");
	cv::VideoCapture mat = input.getData();
	EXPECT_EQ(false, mat.isOpened());
}

TEST(readFileTest, notExisting)
{
	auto io = VideoFileIO();
	EXPECT_THROW(io.readFile("..\\..\\Data\\NotExisting.avi"), std::ifstream::failure);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}