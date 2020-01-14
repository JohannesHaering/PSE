#ifndef OUTPUT_STORAGE_LAYER_FACTORY_H_
#define OUTPUT_STORAGE_LAYER_FACTORY_H_

#include "LayerFactory.hpp"
#include "NeuralNetworkLayer.hpp"

#include <vector>

class OutputStorageLayerFactory : public LayerFactory
{
public:
    NeuralNetworkLayer buildLayer() override;
    OutputStorageLayerFactory setData(std::vector<std::vector<std::vector<double>>> data);

private:
    std::vector<std::vector<std::vector<double>>> data;
};
#endif