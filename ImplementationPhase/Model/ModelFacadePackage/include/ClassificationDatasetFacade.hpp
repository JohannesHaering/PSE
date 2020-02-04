#ifndef CLASSIFICATION_DATASET_FACADE_H_
#define CLASSIFICATION_DATASET_FACADE_H_

#include "ModelFacade.hpp"
#include "FileIO.hpp"
#include "MultipleTextFileIO.hpp"
#include "ClassificationResult.hpp"

#include <string>
#include <list>

class ClassificationDatasetFacade : public ModelFacade
{
public:
    std::list<ClassificationResult> loadDataset(std::string directory);
};
#endif
