#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>
#include <stdexcept>

#include "LayerParser.hpp"
#include "LayerType.hpp"
#include "NetworkLayer.hpp"

TEST(LayerParserTest, valid){
    std::string in = "inputdim=[1,2,3]\n"

}

TEST(LayerParserTest, invalid){
    
}

TEST(LayerBackParserTest, valid){

}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}