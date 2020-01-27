#include "MultipleImageFileIO.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Data.hpp"
#include <opencv2/opencv.hpp>
#include <vector>

TEST(readFileTest, emptyPath)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back("");
    auto input = io.readFile(paths);
    cv::Mat mat;
    EXPECT_EQ(mat, *input.getData().begin());
}

TEST(readFileTest, file)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back("..\\..\\Data\\testdata\\testBMP.bmp");
    auto input = io.readFile(paths);
    auto mat = *input.getData().begin();
    EXPECT_EQ(64, mat.size()[0]);
    EXPECT_EQ(64, mat.size()[1]);
}

TEST(readFileTest, noImageFile)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back("..\\..\\Data\\testTXT.txt");
    auto input = io.readFile(paths);
    cv::Mat mat;
    EXPECT_EQ(mat, input.getData());
}

TEST(readFileTest, notExisting)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back("..\\..\\Data\\NotExisting.bmp");
    EXPECT_THROW(io.readFile(paths)), std::ifstream::failure);
}

TEST(writeFileTest, emptyPath)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back("");
    cv::Mat mat;
    std::list<cv::Mat> images;
    images.push_back(mat);
    auto success = io.writeFile(paths, Data<std::list<cv::Mat>>(images));
    EXPECT_EQ(false, success);
}

TEST(writeFileTest, emptyData)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back("..\\..\\Data\\testdata\\testBMP.bmp");
    cv::Mat mat;
    std::list<cv::Mat> images;
    images.push_back(mat);
    auto success = io.writeFile(paths, Data<std::list<cv::Mat>>(images));
    EXPECT_EQ(false, success);
}

TEST(writeFileTest, file)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back("..\\..\\Data\\testdata\\testBMP.bmp");
    std::vector<float> data;
    for (int i = 0; i < 64; i++)
    {
        for (int j = 0; i < 64; i++)
        {
            data.push_back(128);
        }
    }
    cv::Mat mat(64, 64, CV_32F, data);
    std::list<cv::Mat> images;
    images.push_back(mat);
    auto success = io.writeFile(paths, Data<std::list<cv::Mat>>(images));
    EXPECT_EQ(true, success);
}

TEST(writeFileTest, noTextFile)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back("..\\..\\Data\\testdata\\testTXT.txt");
    std::vector<float> data;
    for (int i = 0; i < 64; i++)
    {
        for (int j = 0; i < 64; i++)
        {
            data.push_back(128);
        }
    }
    cv::Mat mat(64, 64, CV_32F, data);
    std::list<cv::Mat> images;
    images.push_back(mat);
    auto success = io.writeFile(paths, Data<std::list<cv::Mat>>(images));
    EXPECT_EQ(false, success);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}