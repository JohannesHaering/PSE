#include "LineBreakParser.hpp"
#include "LayerParserDistribution.hpp"
#include "DenseLayerParser.hpp"

#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "DenseLayer.hpp"
#include "ReLuLayer.hpp"
#include "LeakyReLuLayer.hpp"
#include "SigmoidLayer.hpp"
#include "SoftmaxLayer.hpp"
#include "ActivationLayerParser.hpp"
#include "ConvolutionLayer.hpp"
#include "ConvolutionalLayerParser.hpp"
#include "FlattenLayerParser.hpp"
#include "MaxPoolLayerParser.hpp"
#include "MaxPoolLayer.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>

NetworkLayer* LayerParserDistribution::parse(std::string toParse)
{
	std::list<std::string> lines = LineBreakParser::splitIntoLines(toParse);
	auto firstLine = *(lines.begin());
	firstLine.erase(std::remove(firstLine.begin(), firstLine.end(), TYPE_BEGIN), firstLine.end());
	firstLine.erase(std::remove(firstLine.begin(), firstLine.end(), TYPE_END), firstLine.end());
	std::string extras = "[\n]";
	// Remove first line
	toParse = toParse.substr(firstLine.size() + extras.size(), toParse.size());
  if (firstLine.compare(DENSE) == 0)
	{
		return parseDenseLayer(toParse);
	}
	else{
    if (firstLine.compare(ACTIVATION) == 0) {
       return ActivationLayerParser().parse(toParse);
	  }
	  else{
      if (firstLine.compare(MAXPOOL) == 0) {
		    return new MaxPoolLayer();
	    } 
      else{
        if (firstLine.compare(CONVOLUTIONAL) == 0) 
        {
  		    return ConvolutionalLayerParser().parse(toParse);
        }
        else{
          if (firstLine.compare(FLATTEN) == 0) {
		        return FlattenLayerParser().parse(toParse);
	        }  
	        else{
            if (firstLine.compare(POLLING) == 0) {
		          return MaxPoolLayerParser().parse(toParse);
	          }
	          else
	          {   
		          throw std::invalid_argument(firstLine + "  " + CONVOLUTIONAL);
	          }
          }
        } 
      }
    }
  }
}

std::string LayerParserDistribution::parseBack(NetworkLayer* layer)
{
	std::string output = "";
	switch (layer->getLayerType())
	{
	case LayerType::DENSE:
		output += DenseLayerParser().parseBack(layer);
		break;
	case LayerType::LEAKYRELU:
		output += ActivationLayerParser().parseBack(layer);
		break;
	case LayerType::RELU:
		output += ActivationLayerParser().parseBack(layer);
		break;
	case LayerType::SOFTMAX:
		output += ActivationLayerParser().parseBack(layer);
		break;
	case LayerType::SIGMOID:
		output += ActivationLayerParser().parseBack(layer);
		break;
	case LayerType::CONVOLUTION:
		output += ConvolutionalLayerParser().parseBack(layer);
		break;
	case LayerType::FLATTEN:
		output += FlattenLayerParser().parseBack(layer);
		break;	
	case LayerType::POLLING:
		output += MaxPoolLayerParser().parseBack(layer);
		break;
	}
	return output;
}

NetworkLayer* LayerParserDistribution::parseDenseLayer(std::string toParse)
{
	return DenseLayerParser().parse(toParse);
}
