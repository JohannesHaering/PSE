#include "NeuralNetworkLayer.hpp"
#include "LineBreakParser.hpp"
#include "LayerParserDistribution.hpp"
#include "ActivationLayerParser.hpp"
#include "CollectResultsLayerParser.hpp"
#include "ConvolutionalLayerParser.hpp"
#include "DenseLayerParser.hpp"
#include "DropoutLayerParser.hpp"
#include "FlattenLayerParser.hpp"
#include "InceptionLayerParser.hpp"
#include "LRNLayerParser.hpp"
#include "OutputStorageLayerParser.hpp"
#include "PollingLayerParser.hpp"

#include <string>
#include <stdexcept>

NeuralNetworkLayer LayerParserDistribution::parse(std::string toParse)
{
    auto firstLine = *(LineBreakParser::splitIntoLines(toParse).begin());
    firstLine.erase(std::remove(firstLine.begin(), firstLine.end(), TYPE_BEGIN), firstLine.end());
    firstLine.erase(std::remove(firstLine.begin(), firstLine.end(), TYPE_END), firstLine.end());

    toParse.substr(firstLine.size() + 4, toParse.size());
    
    switch (firstLine)
    {
    case CONVOLUTIONAL:
        return parseConvolutionalLayer(toParse);
    case POLLING:
        return parsePollingLayer(toParse);
    case ACTIVATION:
        return parseActivationLayer(toParse);
    case LOCAL_RESPONSE_NORMALIZATION:
        return parseLocalResponseNormalizationLayer(toParse);
    case DENSE:
        return parseDenseLayer(toParse);
    case FLATTEN:
        return parseFlattenLayer(toParse);
    case DROPOUT:
        return parseDropoutLayer(toParse);
    case COLLECT_RESULTS:
        return parseCollectResultLayer(toParse);
    case INCEPTION:
        return parseInceptionLayer(toParse);
    case OUTPUT_STORAGE:
        return parseOutputStorageLayer(toParse);
    default:
        throw std::invalid_argument("Wrong format");
    }
}

NeuralNetworkLayer LayerParserDistribution::parseConvolutionalLayer(std::string toParse);
NeuralNetworkLayer LayerParserDistribution::parseActivationLayer(std::string toParse);
NeuralNetworkLayer LayerParserDistribution::parsePollingLayer(std::string toParse);
NeuralNetworkLayer LayerParserDistribution::parseLocalResponseNormalizationLayer(std::string toParse);
NeuralNetworkLayer LayerParserDistribution::parseDenseLayer(std::string toParse);
NeuralNetworkLayer LayerParserDistribution::parseFlattenLayer(std::string toParse);
NeuralNetworkLayer LayerParserDistribution::parseDropoutLayer(std::string toParse);
NeuralNetworkLayer LayerParserDistribution::parseCollectResultLayer(std::string toParse);
NeuralNetworkLayer LayerParserDistribution::parseOutputStorageLayer(std::string toParse);
NeuralNetworkLayer LayerParserDistribution::parseInceptionLayer(std::string toParse);
