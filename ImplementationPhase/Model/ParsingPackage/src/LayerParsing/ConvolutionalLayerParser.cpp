#include "ConvolutionalLayerParser.hpp"
#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "ConvolutionLayer.hpp"
#include "ConvolutionalLayerFactory.hpp"
#include "LayerParserDistribution.hpp"
#include "LineBreakParser.hpp"
#include "Parser.hpp"
#include "MatrixDefine.hpp"
#include <iostream>

#include <string>
#include <list>
#include <stdexcept>

NetworkLayer* ConvolutionalLayerParser::parse(std::string toParse)
{
    ConvolutionalLayerFactory factory = ConvolutionalLayerFactory();

    std::list<std::string> lines = LineBreakParser<NetworkLayer>::splitIntoLines(toParse);
    auto it = lines.begin();

	  std::list<std::string> val3 = Parser::splitBySymbol(*it, VALUE_TYPE_DELIMETER);
	  std::list<std::string>::iterator parts3It = val3.begin();
    if((*parts3It).compare(WEIGHTS_TENSOR) != 0){
      std::cout << *parts3It << " does not equal " << WEIGHTS_TENSOR <<std::endl;  
      throw std::invalid_argument("Wrong format");
    }
    std::string valuePart = *(++parts3It);
    TENSOR(float) tensor = LayerParser::parse4DFloatArray(valuePart);

    factory.setWeightTensors(tensor);
    std::cout << "Returning convlayer" << std::endl;
    return factory.buildLayer();
}

std::string ConvolutionalLayerParser::parseBack(NetworkLayer* layer){
    std::string output = "[convolutional]\n";

	ConvolutionLayer* denselayer = (ConvolutionLayer*)layer;

    output += WEIGHTS_TENSOR;
    output += LayerParser::VALUE_TYPE_DELIMETER;
    output += LayerParser::save4DFloatArray(denselayer->getWeightsTensor());
    output += "\n";
	return output;
}
