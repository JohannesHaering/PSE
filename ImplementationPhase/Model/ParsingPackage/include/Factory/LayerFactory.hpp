#ifndef LAYER_FACTORY_H_
#define LAYER_FACTORY_H_

#include "NeuralNetworkLayer.hpp"

#include <string>
#include <vector>

class LayerFactory
{
public:
    virtual NeuralNetworkLayer buildLayer();
    LayerFactory setInputDimensions(std::vector<int> dimensions);
    LayerFactory setName(std::string name);

protected:
    std::vector<int> inputDimensions;
    std::string name;
};
#endif