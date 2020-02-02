#include "MultipleImageFileIO.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Data.hpp"
#include <opencv2/opencv.hpp>
#include <vector>
#include <list>

TEST(readFileTest, emptyPath)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back("");
    auto input = io.readFile(paths);
    cv::Mat mat =  *input.getData().begin();
    EXPECT_EQ(0, mat.total());
}

TEST(readFileTest, file)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back("C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\testBMP.bmp");
    auto input = io.readFile(paths);
    auto mat = *input.getData().begin();
    EXPECT_EQ(64*64, mat.total());
}

TEST(readFileTest, noImageFile)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back("C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testTXT.txt");
    auto input = io.readFile(paths);
	cv::Mat mat = *input.getData().begin();
    EXPECT_EQ(0, mat.total());
}

TEST(readFileTest, notExisting)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back("C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\NotExisting.bmp");
	auto input = io.readFile(paths);
	cv::Mat mat = *input.getData().begin();
	EXPECT_EQ(0, mat.total());
}

TEST(writeFileTest, emptyPath)
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

TEST(writeFileTest, emptyData)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back("C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\testBMP.bmp");
    cv::Mat mat;
    std::list<cv::Mat> images;
    images.push_back(mat);
    auto success = io.writeFile(Data<std::list<cv::Mat>>(images), paths);
    EXPECT_EQ(false, success);
}

TEST(writeFileTest, file)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back("C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\testBMP.bmp");
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
    EXPECT_EQ(true, success);
}

TEST(writeFileTest, noTextFile)
{
    auto io = MultipleImageFileIO();
    std::list<std::string> paths;
    paths.push_back("C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\testTXT.txt");
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

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}