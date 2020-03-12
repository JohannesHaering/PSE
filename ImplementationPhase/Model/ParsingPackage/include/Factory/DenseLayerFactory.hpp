#ifndef DENSE_LAYER_FACTORY_H_
#define DENSE_LAYER_FACTORY_H_

#include "LayerFactory.hpp"
#include "NetworkLayer.hpp"

#include <vector>

class DenseLayerFactory : public LayerFactory
{
public:
    NetworkLayer* buildLayer() override;
    DenseLayerFactory *setMatrix(std::vector<std::vector<float>> matrix);
    DenseLayerFactory *setBiases(std::vector<float> bias);
private:
    std::vector<std::vector<float>> matrix;
    std::vector<float> bias;
};
#endif
