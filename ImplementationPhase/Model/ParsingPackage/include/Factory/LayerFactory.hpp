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
    LayerFactory* setWidth(int width);
    LayerFactory* setHeight(int height);
    LayerFactory* setZ(int z);

protected:
    int* inputDimensions;
    int batchSize;
    int width;
    int height;
    int z;
    std::string name;
};
#endif
