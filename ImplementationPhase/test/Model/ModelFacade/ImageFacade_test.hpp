#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>
#include <opencv2/opencv.hpp>

#include "ImageFacade.hpp"
#include "MatrixDefine.hpp"

TEST(GetImage, valid){
    auto facade = ImageFacade();
    cv::Mat input = facade.getImage("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/readdir/testBMPRead.bmp", 64,64,1);
    EXPECT_EQ(64*64, input.total());
}

TEST(GetImages, valid){
    auto facade = ImageFacade();
    std::list<std::string> paths = std::list<std::string>();
    paths.push_back("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/readdir/testBMPRead.bmp");
    std::list<cv::Mat> input = facade.getImages(paths,64,64,1);
    cv::Mat mat = *input.begin();
    EXPECT_EQ(64*64, mat.total());
}

TEST(writeImages, valid)
{
    ImageFacade facade = ImageFacade();
    std::list<std::string> paths = std::list<std::string>();
    paths.push_back("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/writedir/testBMPWrite.bmp");
    cv::Mat mat(64, 64, CV_32F, cv::Scalar(0,0,0));
    std::list<cv::Mat> images = std::list<cv::Mat>();
    images.push_back(mat);
    bool success = facade.writeImages(paths, images);
    EXPECT_EQ(true, success);
}

TEST(writeImage, valid)
{
	ImageFacade facade = ImageFacade();
    cv::Mat mat(64, 64, CV_32F, cv::Scalar(0, 0, 0));
    bool success = facade.writeImage("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/writedir/testBMPWrite.bmp", mat);
    EXPECT_EQ(true, success);
}

TEST(ImageGreyScale, valid){
  ImageFacade facade = ImageFacade();
  std::vector<float> image = facade.getImageGreyScale("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/readdir/testBMPRead.bmp", 64,64,1);
  EXPECT_EQ(64*64, image.size());
}

TEST(ImageTensor, valid){
  ImageFacade facade = ImageFacade();
  cv::Mat input = facade.getImage("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/readdir/testBMPRead.bmp", 64,64,1);
  std::vector<cv::Mat> images = std::vector<cv::Mat>();
  images.push_back(input);
  TENSOR(float) tensor = facade.createImageTensor(images, 28,28);
  EXPECT_EQ(tensor[0][0].size(), 28);
  EXPECT_EQ(tensor[0][0][0].size(), 28);
}
