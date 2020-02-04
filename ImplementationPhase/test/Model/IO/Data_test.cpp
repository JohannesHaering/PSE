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
    EXPECT_NEAR(3.1, data.getData(), 0.01);
}

TEST (DataTest, nullO) {
    Data<std::string*> data = Data<std::string*>(nullptr);
    EXPECT_EQ(nullptr, data.getData());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
