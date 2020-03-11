#include "VideoFileIO.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Data.hpp"
#include <opencv2/opencv.hpp>
#include <vector>

TEST(readVideoFileTest, emptyPath)
{
	VideoFileIO io = VideoFileIO();
	Data<cv::VideoCapture> input = io.readFile("");
	cv::VideoCapture mat = input.getData();
	EXPECT_EQ(false, mat.isOpened());
}

TEST(readVideoFileTest, noVideoFile)
{
	VideoFileIO io = VideoFileIO();
	Data<cv::VideoCapture> input = io.readFile("~/Documents/PSE/ImplementationPhase/build/testdata/readdir/testTXT.txt");
	cv::VideoCapture mat = input.getData();
	EXPECT_EQ(false, mat.isOpened());
}

TEST(readVideoFileTest, notExisting)
{
	VideoFileIO io = VideoFileIO();
	EXPECT_THROW(io.readFile("~/Documents/PSE/ImplementationPhase/build/testdata/readdir/NotExisting.avi"), std::ifstream::failure);
}

