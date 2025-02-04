#include <gtest/gtest.h>
#include <vector>
#include <list>
#include <string>

#include "ModelFacade.hpp"

TEST(readDirectories, valid)
{
    auto facade = ModelFacade();
    std::list<std::string> directory = facade.readDirectory("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/readdir");
    EXPECT_EQ(4, directory.size());
}
