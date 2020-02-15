#include "ResultFacade.hpp"
#include "DetectionResultParser.hpp"
#include "ClassificationResultParser.hpp"
#include "DetectionResult.hpp"
#include "ClassificationResult.hpp"
#include "TextFileIO.hpp"
#include "Data.hpp"
#include "MatrixDefine.hpp"

#include <string>
#include <vector>
#include <list>

DetectionResult ResultFacade::parseDetectionResult(std::string resultString)
{
    return DetectionResultParser().parse(resultString);
}

ClassificationResult* ResultFacade::parseClassificationResult(std::string resultString)
{
    return ClassificationResultParser().parse(resultString);
}

ClassificationResult* ResultFacade::parseClassificationResult(std::string imageID, std::string neuralNetworkID, std::list<std::string> labels, std::vector<float> probabilities) {
    return ClassificationResultParser().parse(imageID, neuralNetworkID, labels, probabilities);
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

std::vector<ClassificationResult*> ResultFacade::parseClassificationResult(std::string neuralNetworkID, std::list<std::string> imageIDs, std::list<std::string> classNames, TENSOR(float) tensor) {
    std::vector<ClassificationResult*> results = std::vector<ClassificationResult*>();
    std::list<std::string>::iterator it = imageIDs.begin();
    for (int i = 0; i < results.size(); i++) {
        results.push_back(parseClassificationResult(*it, neuralNetworkID, classNames, tensor.at(i).at(0).at(0)));
    }

    return results;
}