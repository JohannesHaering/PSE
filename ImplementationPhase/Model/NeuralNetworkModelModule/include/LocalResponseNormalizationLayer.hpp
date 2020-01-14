#ifndef LOCALRESPONSENORMALIZATIONLAYER_H_
#define LOCALRESPONSENORMALIZATIONLAYER_H_

#include <string>
#include "NetworkLayer.hpp"
#include "LRNType.h"

class LocalResponseNormalizationLayer  : public NetworkLayer {

  private:
    LRNType type;
    int depth;

  public:
    void LocalResponseNormalizationLayer();
    void LocalResponseNormalizationLayer(std::string name, int* inputDimensions, LRNType type, int depth);
    void setType(LRNType type);
    void setDepth(int depth);
    LRNType getType();
    int getDepth();
};
#endif
