#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>

#include "ImageParserWithSizing.hpp"

TEST(ImageParserTest, valid)
{
  cv::Mat mat(64, 64, CV_32F, cv::Scalar(0, 0, 0));
  ImageParserWithSizing parser = ImageParserWithSizing(24, 24, 3);
  cv::Mat parsed = parser.parse(mat);
  EXPECT_EQ(24 * 24, parsed.total());
}

/*TEST(GreyScaleParserTest, valid)
{
  cv::Mat mat(64, 64, CV_32F, cv::Scalar(0, 0, 0));
  ImageParserWithSizing parser = ImageParserWithSizing(24, 24, 3);
  std::vector<float> parsed = parser.parseFloatsGreyScale(mat);
  EXPECT_EQ(24 * 24, parsed.size());
  for (int i = 0; i < 24 * 24; i++)
  {
    EXPECT_EQ(0, parsed[i]);
  }
}*/
