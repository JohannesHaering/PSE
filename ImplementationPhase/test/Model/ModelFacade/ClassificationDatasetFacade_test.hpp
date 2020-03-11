#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <list>

#include "ClassificationDatasetFacade.hpp"
#include "ClassificationResult.hpp"


TEST(ClassificationDatasetFacade, valid){
    std::string path = "/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/readdir/TestClassificationDataset";
    std::list<ClassificationResult> dataset = ClassificationDatasetFacade().loadDataset(path);
    EXPECT_EQ(2, dataset.size());
}
