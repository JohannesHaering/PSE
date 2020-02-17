#ifndef ACTIVATION_LAYER_PARSER_H_
#define ACTIVATION_LAYER_PARSER_H_

#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "ActivationLayerFactory.hpp"
#include "ActivationLayer.hpp"

#include <string>
class ActivationLayerParser : public LayerParser
{
public:
    NetworkLayer* parse(std::string toParse) override;
    std::string parseBack(NetworkLayer* layer) override;

private:
    float extractAlpha(std::string alphaString);
    std::string saveAlpha(float alpha);

    const std::string USED_FUNCTION = "function";
    const std::string SIGMOID = "sigmoid";
    const std::string TANH = "tanh";
    const std::string RELU = "relu";
    const std::string LEAKING_RELU = "lrelu";
    const std::string PARAMETRIC_RELU = "prelu";
    const std::string SOFTMAX = "soft";
    const std::string SWISH = "swish";
    const std::string ALPHA = "alpha";
    const float STANDARD_ALPHA = 0.01f;    
};
#endif
