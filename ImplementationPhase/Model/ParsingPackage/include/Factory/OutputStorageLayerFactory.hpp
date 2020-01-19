#ifndef OUTPUT_STORAGE_LAYER_FACTORY_H_
#define OUTPUT_STORAGE_LAYER_FACTORY_H_

#include "LayerFactory.hpp"
#include "NetworkLayer.hpp"

#include <vector>

class OutputStorageLayerFactory : public LayerFactory
{
public:
    NetworkLayer buildLayer() override;
    OutputStorageLayerFactory setData(std::vector<std::vector<std::vector<float>>> data);

private:
    std::vector<std::vector<std::vector<float>>> data;
};
#endif