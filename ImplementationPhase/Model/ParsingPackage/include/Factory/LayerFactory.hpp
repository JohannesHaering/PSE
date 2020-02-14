#ifndef LAYER_FACTORY_H_
#define LAYER_FACTORY_H_

#include "NetworkLayer.hpp"

#include <string>
#include <vector>

class LayerFactory
{
public:
    virtual NetworkLayer* buildLayer() = 0;
    LayerFactory* setInputDimensions(int* dimensions);
    LayerFactory* setBatchSize(int batchSize);

protected:
    int* inputDimensions;
    int batchSize;
    std::string name;
};
#endif
