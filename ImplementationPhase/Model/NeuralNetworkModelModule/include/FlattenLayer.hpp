#ifndef FLATTENLAYER_H_
#define FLATTENLAYER_H_

#include <string>
#include "NetworkLayer.hpp"

class FlattenLayer  : public NetworkLayer {

  public:
    FlattenLayer();
    FlattenLayer(std::string name, int* inputDimensions);
    // ~FlattenLayer();
};
#endif
