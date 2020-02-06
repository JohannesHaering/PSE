#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>

#include "ImageParserWithSizing.hpp"

TEST(ParserTest, valid) {
    cv::Mat mat(64,64, CV_32F, cv::Scalar(0,0,0));
    ImageParserWithSizing parser = ImageParserWithSizing(24,24,3);
    cv::Mat parsed = parser.parse(mat);
    EXPECT_EQ(24*24, parsed.total());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}