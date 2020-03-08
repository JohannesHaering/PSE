#define TESTDIR _TESTDIR

#include "MultipleImageFileIO.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Data.hpp"
#include <opencv2/opencv.hpp>
#include <vector>
#include <list>

TEST(readImageFilesTest, emptyPath)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back("");
    auto input = io.readFile(paths);
    cv::Mat mat =  *input.getData().begin();
    EXPECT_EQ(0, mat.total());
}

TEST(readImageFilesTest, file)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back(TESTDIR + "\\readdir\\testBMPRead.bmp");
    auto input = io.readFile(paths);
    auto mat = *input.getData().begin();
    EXPECT_EQ(64*64, mat.total());
}

TEST(readImageFilesTest, noImageFile)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back(TESTDIR + "\\readdir\\testTXT.txt");
    auto input = io.readFile(paths);
	cv::Mat mat = *input.getData().begin();
    EXPECT_EQ(0, mat.total());
}

TEST(readImageFilesTest, notExisting)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back(TESTDIR + "\\readdir\\NotExisting.bmp");
	auto input = io.readFile(paths);
	cv::Mat mat = *input.getData().begin();
	EXPECT_EQ(0, mat.total());
}

TEST(writeImageFilesTest, emptyPath)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back("");
    cv::Mat mat;
    std::list<cv::Mat> images;
    images.push_back(mat);
    auto success = io.writeFile(Data<std::list<cv::Mat>>(images), paths);
    EXPECT_EQ(false, success);
}

TEST(writeImageFilesTest, emptyData)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back(TESTDIR + "\\writedir\\testBMPWrite.bmp");
    cv::Mat mat;
    std::list<cv::Mat> images;
    images.push_back(mat);
    auto success = io.writeFile(Data<std::list<cv::Mat>>(images), paths);
    EXPECT_EQ(false, success);
}

TEST(writeImageFilesTest, file)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back(TESTDIR + "\\writedir\\testBMP.bmp");
    cv::Mat mat(64, 64, CV_32F, cv::Scalar(0,0,0));
    std::list<cv::Mat> images;
    images.push_back(mat);
    auto success = io.writeFile(Data<std::list<cv::Mat>>(images), paths);
    EXPECT_EQ(true, success);
}

TEST(writeImageFilesTest, noTextFile)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back(TESTDIR + "\\writedir\\testTXT.txt");
    std::vector<float> data;
    for (int i = 0; i < 64; i++)
    {
        for (int j = 0; i < 64; i++)
        {
            data.push_back(128);
        }
    }
    cv::Mat mat(64, 64, CV_32F, cv::Scalar(0,0,0));
    std::list<cv::Mat> images;
    images.push_back(mat);
    auto success = io.writeFile(Data<std::list<cv::Mat>>(images), paths);
    EXPECT_EQ(false, success);
}