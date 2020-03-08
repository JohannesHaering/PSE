#define TESTDIR _TESTDIR

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>

#include "DetectionData.hpp"
#include "DetectionDataFacade.hpp"
#include "SingleDetectionDataset.hpp"


TEST(DetectionnDataFacade, valid){
    std::string path = TESTDIR + "readdir\\TestDetectionData";
    DetectionData dataset = DetectionDataFacade().loadDetectionData(path);
    EXPECT_EQ(2, dataset.getDataset().size());
}
