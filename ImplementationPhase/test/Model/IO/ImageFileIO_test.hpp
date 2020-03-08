#define TESTDIR _TESTDIR

#include "ImageFileIO.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Data.hpp"
#include <opencv2/opencv.hpp>
#include <vector>

TEST(readImageFileTest, emptyPath)
{
    auto io = ImageFileIO();
    auto input = io.readFile("");
    cv::Mat mat = input.getData();
    EXPECT_EQ(0, mat.total());
}

TEST(readImageFileTest, file)
{
    auto io = ImageFileIO();
    auto input = io.readFile( TESTDIR + "\\readdir\\testBMPRead.bmp");
    cv::Mat mat = input.getData();
    EXPECT_EQ(64*64, mat.total());
}

TEST(readImageFileTest, noImageFile)
{
    auto io = ImageFileIO();
    auto input = io.readFile(TESTDIR + "\\readdir\\testTXT.txt");
	cv::Mat mat = input.getData();
	EXPECT_EQ(0, mat.total());
}

TEST(readImageFileTest, notExisting)
{
    auto io = ImageFileIO();
	auto input = io.readFile(TESTDIR + "\\readdir\\NotExisting.bmp");
	cv::Mat mat = input.getData();
	EXPECT_EQ(0, mat.total());
	EXPECT_EQ(0, mat.total());
}

TEST(writeImageFileTest, emptyPath)
{
    auto io = ImageFileIO();
    cv::Mat mat;
    auto success = io.writeFile(Data<cv::Mat>(mat), "");
    EXPECT_EQ(false, success);
}

TEST(writeImageFileTest, emptyData)
{
    auto io = ImageFileIO();
    cv::Mat mat;
    auto success = io.writeFile(Data<cv::Mat>(mat), TESTDIR + "\\writedir\\testBMP.bmp");
    EXPECT_EQ(false, success);
}

TEST(writeImageFileTest, file)
{
    auto io = ImageFileIO();
    cv::Mat mat(64, 64, CV_32F, cv::Scalar(0, 0, 0));
    auto success = io.writeFile(Data<cv::Mat>(mat), TESTDIR + "\\writedir\\testBMPWrite.bmp");
    EXPECT_EQ(true, success);
}

TEST(writeImageFileTest, noTextFile)
{
    auto io = ImageFileIO();
    cv::Mat mat(64, 64, CV_32F);
    auto success = io.writeFile(Data<cv::Mat>(mat), TESTDIR + "\\writedir\\testTXT.txt");
    EXPECT_EQ(false, success);
}