#include "ResultFacade.hpp"
#include "DetectionResultParser.hpp"
#include "ClassificationResultParser.hpp"
#include "DetectionResult.hpp"
#include "ClassificationResult.hpp"
#include "TextFileIO.hpp"
#include "Data.hpp"

#include <string>

DetectionResult ResultFacade::parseDetectionResult(std::string resultString)
{
    return DetectionResultParser().parse(resultString);
}

ClassificationResult ResultFacade::parseClassificationResult(std::string resultString)
{
    return ClassificationResultParser().parse(resultString);
}

bool ResultFacade::writeDetectionResult(DetectionResult result, std::string path)
{
    std::string output = DetectionResultParser().parseBack(result);
    return TextFileIO().writeFile(path, Data(output));
}

bool ResultFacade::writeClassificationResult(ClassificationResult result, std::string path)
{
    std::string output = ClassificationResultParser().parseBack(result);
    return TextFileIO().writeFile(path, Data(output));
}