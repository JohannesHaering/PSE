#include "Data.hpp"

#include <gtest/getst.h>
#include <string>

TEST (DataTest, string) {
    Data<std::string> data = Data("foo");
    EXPECT_EQ("foo", data.getData());
}

TEST (DataTest, float) {
    Data<float> data = Data(3.1);
    EXPECT_EQ(3.1, data.getData());
}

int main(int argc, char ∗∗argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}