#include "ResultFacade.hpp"
#include "DetectionResultParser.hpp"
#include "ClassificationResultParser.hpp"
#include "DetectionResult.hpp"
#include "ClassificationResult.hpp"
#include "TextFileIO.hpp"
#include "Data.hpp"

#include <string>

DetectionResult ParseResultFacade::parseDetectionResult(std::string resultString)
{
    return DetectionResultParser().parse(resultString);
}

ClassificationResult ParseResultFacade::parseClassificationResult(std::string resultString)
{
    return ClassificationResultParser().parse(resultString);
}

bool writeDetectionResult(DetectionResult result, std::string path)
{
    std::string output = DetectionResultParser().parseBack(result);
    return TextFileIO().writeFile(path, Data(output));
}

bool writeClassificationResult(ClassificationResult result, std::string path)
{
    std::string output = ClassificationResultParser().parseBack(result);
    return TextFileIO().writeFile(path, Data(output));
}