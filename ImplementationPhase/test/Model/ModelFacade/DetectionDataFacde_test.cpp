#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>

#include "DetectionData.hpp"
#include "DetectionDataFacade.hpp"
#include "SingleDetectionDataset.hpp"


TEST(DetectionnDataFacade, valid){
    std::string path = "C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\TestDetectionData";
    DetectionData dataset = DetectionDataFacade().loadDetectionData(path);
    EXPECT_EQ(2, dataset.getDataset().size());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}