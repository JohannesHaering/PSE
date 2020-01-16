#include "LayerFactory.hpp"
#include "NeuralNetworkLayer.hpp"

#include <string>
#include <vector>

LayerFactory LayerFactory::setInputDimensions(int* dimensions)
{
    this -> inputDimensions = dimensions;
    return *this;
}
LayerFactory LayerFactory::setName(std::string name)
{
    this -> name = name;
    return *this;
}