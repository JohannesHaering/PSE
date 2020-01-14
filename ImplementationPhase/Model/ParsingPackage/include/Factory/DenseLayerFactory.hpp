#ifndef DENSE_LAYER_FACTORY_H_
#define DENSE_LAYER_FACTORY_H_

#include "LayerFactory.hpp"
#include "NeuralNetworkLayer.hpp"

#include <vector>

class DenseLayerFactory : public LayerFactory
{
public:
    NeuralNetworkLayer buildLayer() override;
    DenseLayerFactory setMatrix(std::vector<std::vector<double>> matrix);
private:
    std::vector<std::vector<double>> matrix;
};
#endif