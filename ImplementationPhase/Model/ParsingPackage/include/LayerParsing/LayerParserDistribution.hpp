#ifndef LAYER_PARSER_DISTRIBUTION_H_
#define LAYER_PARSER_DISTRIBUTION_H_

#include "NetworkLayer.hpp"
#include "LineBreakParser.hpp"

#include <string>

class LayerParserDistribution : public LineBreakParser<NetworkLayer>
{
public:
    NetworkLayer* parse(std::string toParse);
    std::string parseBack(NetworkLayer *layer);

    const char TYPE_BEGIN = '[';
    const char TYPE_END = ']';
    
    const std::string CONVOLUTIONAL = "convolutional";
    const std::string POLLING = "polling";
    const std::string ACTIVATION = "activation";
    const std::string LOCAL_RESPONSE_NORMALIZATION = "lrn";
    const std::string DENSE = "dense";
    const std::string FLATTEN = "flatten";
    const std::string DROPOUT = "dropout";
    const std::string COLLECT_RESULTS = "collect";
    const std::string INCEPTION = "inception";
    const std::string OUTPUT_STORAGE = "output_storage";
    const std::string SIGMOID = "sigmoid";
    const std::string SOFTMAX = "softmax";
    const std::string RELU = "relu";
    const std::string LEAKYRELU = "leakyrelu";
    const std::string MAXPOOL = "maxpool";

private:
    NetworkLayer* parseConvolutionalLayer(std::string toParse);
    NetworkLayer* parseActivationLayer(std::string toParse);
    NetworkLayer* parsePollingLayer(std::string toParse);
    NetworkLayer* parseLocalResponseNormalizationLayer(std::string toParse);
    NetworkLayer* parseDenseLayer(std::string toParse);
    NetworkLayer* parseFlattenLayer(std::string toParse);
    NetworkLayer* parseDropoutLayer(std::string toParse);
    NetworkLayer* parseCollectResultLayer(std::string toParse);
    NetworkLayer* parseOutputStorageLayer(std::string toParse);
    NetworkLayer* parseInceptionLayer(std::string toParse);
};
#endif
