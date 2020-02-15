#ifndef PARSE_RESULT_FACADE_H_
#define PARSE_RESULT_FACADE_H_

#include "ModelFacade.hpp"
#include "DetectionResult.hpp"
#include "ClassificationResult.hpp"
#include "MatrixDefine.hpp"

#include <string>
#include <list>
#include <vector>

class ResultFacade : public ModelFacade
{
public:
    DetectionResult parseDetectionResult(std::string resultString);
    ClassificationResult* parseClassificationResult(std::string resultString);
    ClassificationResult* parseClassificationResult(std::string imageID, std::string neuralNetworkID, std::list<std::string> labels, std::vector<float> probabilities);
    std::vector<ClassificationResult*> parseClassificationResult(std::string neuralNetworkID, std::list<std::string> imageIDs, std::list<std::string> classNames, MatrixDefine::TENSOR(float) tensor);
    bool writeDetectionResult(DetectionResult result, std::string path);
    bool writeClassificationResult(ClassificationResult result, std::string path);
};
#endif
