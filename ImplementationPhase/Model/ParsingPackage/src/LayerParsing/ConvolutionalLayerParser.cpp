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
    //LayerParser::extractGeneralInformation(toParse);
    ConvolutionalLayerFactory factory = ConvolutionalLayerFactory();
    //factory.setInputDimensions(LayerParser::inputDimensions);
    //factory.setBatchSize(batchSize);

    std::list<std::string> lines = LineBreakParser<NetworkLayer>::splitIntoLines(toParse);
    auto it = lines.begin();
  //  ++it;
/*
	std::list<std::string> val1 = Parser::splitBySymbol(*it, VALUE_TYPE_DELIMETER);
	std::list<std::string>::iterator parts1It = val1.begin();
    if ((*parts1It).compare(STRIDE))
        throw std::invalid_argument("Wrong Format");
    factory.setStride(::atoi((*(++parts1It)).c_str()));
    ++it;

	std::list<std::string> val2 = Parser::splitBySymbol(*it, VALUE_TYPE_DELIMETER);
	std::list<std::string>::iterator parts2It = val2.begin();
    if (*parts2It != PADDING)
        throw std::invalid_argument("Wrong Format");
    factory.setPadding(::atoi((*(++parts2It)).c_str()));
    ++it;
*/
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

    //output += saveGeneralInformation(layer);
    //output += STRIDE;
    //output += LayerParser::VALUE_TYPE_DELIMETER;
    //output += std::to_string(denselayer->getStride());
    //output += "\n";
    //output += PADDING;
    //output += LayerParser::VALUE_TYPE_DELIMETER;
    //output += std::to_string(denselayer->getPadding());
    //output += "\n";
    output += WEIGHTS_TENSOR;
    output += LayerParser::VALUE_TYPE_DELIMETER;
    output += LayerParser::save4DFloatArray(denselayer->getWeightsTensor());
    output += "\n";
	return output;
}
