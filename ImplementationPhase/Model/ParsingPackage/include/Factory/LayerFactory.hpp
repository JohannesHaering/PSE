#ifndef LAYER_FACTORY_H_
#define LAYER_FACTORY_H_

#include "NetworkLayer.hpp"

#include <string>
#include <vector>

class LayerFactory
{
public:
    virtual NetworkLayer buildLayer();
    LayerFactory setInputDimensions(int* dimensions);
    LayerFactory setName(std::string name);

protected:
    int* inputDimensions;
    std::string name;
};
#endif
