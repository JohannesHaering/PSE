#include <gtest/gtest.h>
#include <string>
#include <stdexcept>
#include <list>

#include "DetectionResult.hpp"
#include "BoundingBox.hpp"
#include "ClassProbability.hpp"
#include "DetectionResultParser.hpp"


TEST (ParseTest, valid){
    auto in = "i#nn#0.2$0.3$0.4$0.5$name1:1/name2:0|0.2$0.3$0.4$0.5$name1:1/name2:0";
    auto out = DetectionResultParser().parse(in);
    EXPECT_EQ("i", out.getImageID());
    EXPECT_EQ("nn", out.getNeuralNetworkID());
    EXPECT_EQ(2, out.getBoundingBoxes().size());
}

TEST (ParseTest, invalid){
    auto in = "i#nn#0.2$0.3$0.5$name1:1/name2:0";
    EXPECT_THROW(DetectionResultParser().parse(in), std::invalid_argument);
}

TEST (ParseBackTest, valid) {
    auto list = std::list<ClassProbability>();
    list.push_back(ClassProbability("name", 1));
    auto listBB = std::list<BoundingBox>();
    listBB.push_back(BoundingBox(0.2f, 0.3f, 0.4f, 0.5f, list));
    auto out = DetectionResultParser().parseBack(DetectionResult("i", "nn", listBB));
    EXPECT_EQ("i#nn#0.2$0.3$0.4$0.5$name1:1", out);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
