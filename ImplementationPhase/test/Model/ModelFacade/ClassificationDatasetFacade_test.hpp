#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <list>

#include "ClassificationDatasetFacade.hpp"
#include "ClassificationResult.hpp"


TEST(ClassificationDatasetFacade, valid){
    std::string path = "C:\\Users\\Johannes\\Documents\\Projekte\\Uni\\PSE\\ImplementationPhase\\Data\\testdata\\TestClassificationDataset";
    std::list<ClassificationResult> dataset = ClassificationDatasetFacade().loadDataset(path);
    EXPECT_EQ(2, dataset.size());
}
