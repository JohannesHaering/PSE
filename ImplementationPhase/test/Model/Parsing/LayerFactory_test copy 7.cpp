#include <gtest/gtest.h>
#include <vector>
#include <string>


TEST(BuildTest, valid){
    int dim[] = {1,2,3};
    std::string name = "nn";
    
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}