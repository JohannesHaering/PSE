#include "ImageFileIO.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Data.hpp"
#include <opencv2/opencv.hpp>
#include <vector>

TEST(readFileTest, emptyPath)
{
    auto io = ImageFileIO();
    auto input = io.readFile("");
    cv::Mat mat = input.getData();
    EXPECT_EQ(0, mat.total());
}

TEST(readFileTest, file)
{
    auto io = ImageFileIO();
    auto input = io.readFile("C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\testBMP.bmp");
    cv::Mat mat = input.getData();
    EXPECT_EQ(64*64, mat.total());
}

TEST(readFileTest, noImageFile)
{
    auto io = ImageFileIO();
    auto input = io.readFile("C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testTXT.txt");
	cv::Mat mat = input.getData();
	EXPECT_EQ(0, mat.total());
}

TEST(readFileTest, notExisting)
{
    auto io = ImageFileIO();
	auto input = io.readFile("C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\NotExisting.bmp");
	cv::Mat mat = input.getData();
	EXPECT_EQ(0, mat.total());
	EXPECT_EQ(0, mat.total());
}

TEST(writeFileTest, emptyPath)
{
    auto io = ImageFileIO();
    cv::Mat mat;
    auto success = io.writeFile(Data<cv::Mat>(mat), "");
    EXPECT_EQ(false, success);
}

TEST(writeFileTest, emptyData)
{
    auto io = ImageFileIO();
    cv::Mat mat;
    auto success = io.writeFile(Data<cv::Mat>(mat), "C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\testBMP.bmp");
    EXPECT_EQ(false, success);
}

TEST(writeFileTest, file)
{
    auto io = ImageFileIO();
    std::vector<float> data;
    for (int i = 0; i < 64; i++)
    {
        for (int j = 0; i < 64; i++)
        {
            data.push_back(128);
        }
    }
    cv::Mat mat(64, 64, CV_32F, cv::Scalar(0, 0, 0));
    auto success = io.writeFile(Data<cv::Mat>(mat), "C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\testBMP.bmp");
    EXPECT_EQ(true, success);
}

TEST(writeFileTest, noTextFile)
{
    auto io = ImageFileIO();
    std::vector<float> data;
    for (int i = 0; i < 64; i++)
    {
        for (int j = 0; i < 64; i++)
        {
            data.push_back(128);
        }
    }
    cv::Mat mat(64, 64, CV_32F);
    auto success = io.writeFile(Data<cv::Mat>(mat), "C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\testTXT.txt");
    EXPECT_EQ(false, success);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}