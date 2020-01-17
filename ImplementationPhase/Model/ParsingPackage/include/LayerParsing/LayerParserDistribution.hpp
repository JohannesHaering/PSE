#ifndef LAYER_PARSER_DISTRIBUTION_H_
#define LAYER_PARSER_DISTRIBUTION_H_

#include "NeuralNetworkLayer.hpp"
#include "LineBreakParser.hpp"

#include <string>

class LayerParserDistribution : public LineBreakParser<NeuralNetworkLayer>
{
public:
    NeuralNetworkLayer parse(std::string toParse);

    const std::string TYPE_BEGIN = "[";
    const std::string TYPE_END = "]";
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

private:
    NeuralNetworkLayer parseConvolutionalLayer(std::string toParse);
    NeuralNetworkLayer parseActivationLayer(std::string toParse);
    NeuralNetworkLayer parsePollingLayer(std::string toParse);
    NeuralNetworkLayer parseLocalResponseNormalizationLayer(std::string toParse);
    NeuralNetworkLayer parseDenseLayer(std::string toParse);
    NeuralNetworkLayer parseFlattenLayer(std::string toParse);
    NeuralNetworkLayer parseDropoutLayer(std::string toParse);
    NeuralNetworkLayer parseCollectResultLayer(std::string toParse);
    NeuralNetworkLayer parseOutputStorageLayer(std::string toParse);
    NeuralNetworkLayer parseInceptionLayer(std::string toParse);
};
#endif
