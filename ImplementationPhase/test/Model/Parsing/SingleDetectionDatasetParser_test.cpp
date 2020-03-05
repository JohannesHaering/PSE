#include <gtest/gtest.h>
#include <string>
#include <stdexcept>
#include <list>

#include "DetectionResult.hpp"
#include "BoundingBox.hpp"
#include "ClassProbability.hpp"
#include "DetectionResultParser.hpp"
#include "SingleDetectionDataset.hpp"
#include "SingleDetectionDatasetParser.hpp"

TEST(ParseTest, valid)
{
    std::string in = "image\npath\n0.1|0.2$0.3$0.4$0.5$name1:1/name2:0";
    SingleDetectionDataset out = SingleDetectionDatasetParser().parse(in);
    EXPECT_EQ("path", out.getImageLocation());
    EXPECT_EQ(1, out.getBoundingBoxes().size());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
