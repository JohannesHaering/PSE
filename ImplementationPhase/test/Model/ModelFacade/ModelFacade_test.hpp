#include <gtest/gtest.h>
#include <vector>
#include <list>
#include <string>

#include "ModelFacade.hpp"

TEST(readDirectories, valid)
{
    auto facade = ModelFacade();
    std::list<std::string> directory = facade.readDirectory("C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata");
    EXPECT_EQ(8, directory.size());
}
