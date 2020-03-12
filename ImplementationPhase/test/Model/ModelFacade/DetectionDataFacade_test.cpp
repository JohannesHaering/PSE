#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>

#include "DetectionData.hpp"
#include "DetectionDataFacade.hpp"
#include "SingleDetectionDataset.hpp"


TEST(DetectionnDataFacade, valid){
    std::string path = "/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/readdir/TestDetectionData";
    DetectionData dataset = DetectionDataFacade().loadDetectionData(path);
    EXPECT_EQ(2, dataset.getDataset().size());
}
