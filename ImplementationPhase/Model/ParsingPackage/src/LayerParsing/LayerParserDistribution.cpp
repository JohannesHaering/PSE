#ifndef LAYER_PARSER_DISTRIBUTION_H_
#define LAYER_PARSER_DISTRIBUTION_H_

#include "NeuralNetworkLayer.hpp"
#include "LineBreakParser.hpp"

#include <string>

class LayerParserDistribution : public LineBreakParser<NeuralNetworkLayer> {
public:
    NeuralNetworkLayer parse(std::string toParse);
private:
    NeuralNetworkLayer parseConvolutionalLayer(std::list<std::string> lines);
    NeuralNetworkLayer parseActivationLayer(std::list<std::string> lines);
    NeuralNetworkLayer parsePollingLayer(std::list<std::string> lines);
    NeuralNetworkLayer parseLocalResponseNormalizationLayer(std::list<std::string> lines);
    NeuralNetworkLayer parseDenseLayer(std::list<std::string> lines);
    NeuralNetworkLayer parseFlattenLayer(std::list<std::string> lines);
    NeuralNetworkLayer parseDropoutLayer(std::list<std::string> lines);
    NeuralNetworkLayer parseCollectResultLayer(std::list<std::string> lines);
    NeuralNetworkLayer parseOutputStorageLayer(std::list<std::string> lines);
    NeuralNetworkLayer parseInceptionLayer(std::list<std::string> lines);

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
};
#endif
