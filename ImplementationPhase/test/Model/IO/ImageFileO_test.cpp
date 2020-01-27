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
    cv::Mat mat;
    EXPECT_EQ(mat, input.getData());
}

TEST(readFileTest, file)
{
    auto io = ImageFileIO();
    auto input = io.readFile("..\\..\\Data\\testdata\\testBMP.bmp");
    auto mat = input.getData();
    EXPECT_EQ(64, mat.size()[0]);
    EXPECT_EQ(64, mat.size()[1]);
}

TEST(readFileTest, noImageFile)
{
    auto io = ImageFileIO();
    auto input = io.readFile("..\\..\\Data\\testTXT.txt");
    cv::Mat mat;
    EXPECT_EQ(mat, input.getData());
}

TEST(readFileTest, notExisting)
{
    auto io = ImageFileIO();
    EXPECT_THROW(io.readFile("..\\..\\Data\\NotExisting.bmp"), std::ifstream::failure);
}

TEST(writeFileTest, emptyPath)
{
    auto io = ImageFileIO();
    cv::Mat mat;
    auto success = io.writeFile("", Data<cv::Mat>(mat));
    EXPECT_EQ(false, success);
}

TEST(writeFileTest, emptyData)
{
    auto io = ImageFileIO();
    cv::Mat mat;
    auto success = io.writeFile("..\\..\\Data\\testdata\\testBMP.bmp", Data<cv::Mat>(mat));
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
    cv::Mat mat(64, 64, CV_32F, data);
    auto success = io.writeFile("..\\..\\Data\\testdata\\testBMP.bmp", Data<cv::Mat>(mat));
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
    cv::Mat mat(64, 64, CV_32F, data);
    auto success = io.writeFile("..\\..\\Data\\testdata\\testTXT.txt", Data<cv::Mat>(mat));
    EXPECT_EQ(false, success);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}