#include "NetworkLayer.hpp"
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
#include "LayerType.hpp"

#include "ActivationLayer.hpp"
#include "CollectResultsLayer.hpp"
#include "ConvolutionLayer.hpp"
#include "DenseLayer.hpp"
#include "DropoutLayer.hpp"
#include "FlattenLayer.hpp"
#include "InceptionLayer.hpp"
#include "LocalResponseNormalizationLayer.hpp"
#include "OutputStorageLayer.hpp"
#include "PollingLayer.hpp"

#include <string>
#include <stdexcept>
#include <algorithm>

NetworkLayer LayerParserDistribution::parse(std::string toParse)
{
    auto firstLine = *(LineBreakParser::splitIntoLines(toParse).begin());
    firstLine.erase(std::remove(firstLine.begin(), firstLine.end(), TYPE_BEGIN), firstLine.end());
    firstLine.erase(std::remove(firstLine.begin(), firstLine.end(), TYPE_END), firstLine.end());

    toParse.substr(firstLine.size() + 4, toParse.size());

    if (firstLine == CONVOLUTIONAL)
    {
        return parseConvolutionalLayer(toParse);
    }
    else if (firstLine == POLLING)
    {
        return parsePollingLayer(toParse);
    }
    else if (firstLine == ACTIVATION)
    {
        return parseActivationLayer(toParse);
    }
    else if (firstLine == LOCAL_RESPONSE_NORMALIZATION)
    {
        return parseLocalResponseNormalizationLayer(toParse);
    }
    else if (firstLine == DENSE)
    {
        return parseDenseLayer(toParse);
    }
    else if (firstLine == FLATTEN)
    {
        return parseFlattenLayer(toParse);
    }
    else if (firstLine == DROPOUT)
    {
        return parseDropoutLayer(toParse);
    }
    else if (firstLine == COLLECT_RESULTS)
    {
        return parseCollectResultLayer(toParse);
    }
    else if (firstLine == INCEPTION)
    {
        return parseInceptionLayer(toParse);
    }
    else if (firstLine == OUTPUT_STORAGE)
    {
        return parseOutputStorageLayer(toParse);
    }
    else
    {
        throw std::invalid_argument("Wrong format");
    }
}

std::string LayerParserDistribution::parseBack(NetworkLayer* layer)
{
    std::string output = "";
    switch ((*layer).getLayerType())
    {
    case LayerType::ACTIVATION:
        output += ActivationLayerParser().parseBack(*dynamic_cast<ActivationLayer*>(layer));
        break;
    case LayerType::COLLECT_RESULTS:
        output += CollectResultsLayerParser().parseBack(*dynamic_cast<CollectResultsLayer*>(layer));
        break;
    case LayerType::CONVOLUTION:
        output += ConvolutionalLayerParser().parseBack(*dynamic_cast<ConvolutionLayer*>(layer));
        break;
    case LayerType::DENSE:
        output += DenseLayerParser().parseBack(*dynamic_cast<DenseLayer*>(layer));
        break;
    case LayerType::DROPOUT:
        output += DropoutLayerParser().parseBack(*dynamic_cast<DropoutLayer*>(layer));
        break;
    case LayerType::FLATTEN:
        output += FlattenLayerParser().parseBack(*dynamic_cast<FlattenLayer*>(layer));
        break;
    case LayerType::INCEPTION:
        output += InceptionLayerParser().parseBack(*dynamic_cast<InceptionLayer*>(layer));
        break;
    case LayerType::LRN:
        output += LRNLayerParser().parseBack(*dynamic_cast<LocalResponseNormalizationLayer*>(layer));
        break;
    case LayerType::OUTPUT_STORAGE:
        output += OutputStorageLayerParser().parseBack(*dynamic_cast<OutputStorageLayer*>(layer));
        break;
    case LayerType::POLLING:
        output += PollingLayerParser().parseBack(*dynamic_cast<PollingLayer*>(layer));
        break;
    }
	return output;
}

NetworkLayer LayerParserDistribution::parseConvolutionalLayer(std::string toParse)
{
    return ConvolutionalLayerParser().parse(toParse);
}
NetworkLayer LayerParserDistribution::parseActivationLayer(std::string toParse)
{
    return ActivationLayerParser().parse(toParse);
}
NetworkLayer LayerParserDistribution::parsePollingLayer(std::string toParse)
{
    return PollingLayerParser().parse(toParse);
}
NetworkLayer LayerParserDistribution::parseLocalResponseNormalizationLayer(std::string toParse)
{
    return LRNLayerParser().parse(toParse);
}
NetworkLayer LayerParserDistribution::parseDenseLayer(std::string toParse)
{
    return DenseLayerParser().parse(toParse);
}
NetworkLayer LayerParserDistribution::parseFlattenLayer(std::string toParse)
{
    return FlattenLayerParser().parse(toParse);
}
NetworkLayer LayerParserDistribution::parseDropoutLayer(std::string toParse)
{
    return DropoutLayerParser().parse(toParse);
}
NetworkLayer LayerParserDistribution::parseCollectResultLayer(std::string toParse)
{
    return CollectResultsLayerParser().parse(toParse);
}
NetworkLayer LayerParserDistribution::parseOutputStorageLayer(std::string toParse)
{
    return OutputStorageLayerParser().parse(toParse);
}
NetworkLayer LayerParserDistribution::parseInceptionLayer(std::string toParse)
{
    return InceptionLayerParser().parse(toParse);
}
