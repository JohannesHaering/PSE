#include <gtest/gtest.h>
#include "Result.hpp"
#include "ResultManager.hpp"
#include <iostream>

TEST(ResultManagerTest, emptyConstructor) {
    ResultManager mgr = ResultManager();
    EXPECT_EQ(mgr.getSingleResult("FOO", "coolNN"), nullptr);
    Result * newRes = new Result("FOO", "coolNN");
    ASSERT_NE(newRes, nullptr);
    mgr.addResult(newRes);
    ASSERT_NE(mgr.getSingleResult("FOO", "coolNN"), nullptr);
    EXPECT_EQ(mgr.getSingleResult("FOO", "coolNN")->getImageID(), "FOO");
    EXPECT_EQ(mgr.getSingleResult("FOO", "coolNN")->getNeuralNetworkID(), "coolNN");
}

TEST(ResultManagerTest, filledConstructor) {
    std::list<Result*> resultList = std::list<Result*>();
    resultList.push_back(new Result("ImageA", "NNA"));
    resultList.push_back(new Result("ImageB", "NNB"));
    resultList.push_back(new Result("ImageC", "NNC"));
    resultList.push_back(new Result("ImageD", "NND"));
    ResultManager mgr = ResultManager(resultList);
    EXPECT_EQ(mgr.getSingleResult("ImageA",""), nullptr);
    EXPECT_EQ(mgr.getSingleResult("",""), nullptr);
    EXPECT_EQ(mgr.getSingleResult("ImageB","NNC"), nullptr);
    //EXPECT_EQ(mgr.getSingleResult("ImageB","NNB")->getImageID(), "ImageB");
    //EXPECT_EQ(mgr.getSingleResult("ImageB","NNB")->getNeuralNetworkID(), "NNB");
}
