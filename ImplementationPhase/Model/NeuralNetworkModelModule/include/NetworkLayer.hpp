#ifndef NETWORKLAYER_H_
#define NETWORKLAYER_H_

#include <string>
// #include <vector>
#include "LayerType.hpp"

class NetworkLayer {

private:
    std::string name;
    int inputDimensions[3];
    LayerType layerType;

  public:
    NetworkLayer(std::string name, int* inputDimensions, LayerType layerType);
    NetworkLayer(LayerType layerType);
    void setName(std::string name);
    void setInputDimensions(int* inputDimensions);
    std::string getName();
    LayerType getLayerType();
    int* getInputDimensions();
    virtual int* getTensorDimenssions();
    // ~NetworkLayer();
};
#endif
