#ifndef PARSE_RESULT_FACADE_H_
#define PARSE_RESULT_FACADE_H_

#include "ModelFacade.hpp"
#include "DetectionResult.hpp"
#include "ClassificationResult.hpp"

#include <string>

class ParseResultFacade : public ModelFacade
{
public:
    DetectionResult parseDetectionResult(std::string resultString);
    ClassificationResult parseClassificationResult(std::string resultString);
};
#endif