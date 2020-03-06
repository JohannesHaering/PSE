#include "Data.hpp"

#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>
#include <string>


TEST (DataTest, stringO) {
    Data<std::string> data = Data<std::string>("foo");
    EXPECT_EQ("foo", data.getData());
}

TEST (DataTest, floatO) {
    Data<float> data = Data<float>(3.1);
    EXPECT_NEAR(3.1f, data.getData(), 0.01);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
