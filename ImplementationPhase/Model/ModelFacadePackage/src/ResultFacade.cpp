#include "ResultFacade.hpp"
#include "DetectionResultParser.hpp"
#include "ClassificationResultParser.hpp"
#include "DetectionResult.hpp"
#include "ClassificationResult.hpp"

#include <string>

DetectionResult ParseResultFacade::parseDetectionResult(std::string resultString)
{
    return DetectionResultParser().parse(resultString);
}

ClassificationResult ParseResultFacade::parseClassificationResult(std::string resultString)
{
    return ClassificationResultParser().parse(resultString);
}

bool writeDetectionResult(DetectionResult result)
{
}

bool writeClassificationResult(ClassificationResult result)
{
}