#ifndef POLLINGLAYER_H_
#define POLLINGLAYER_H_

#include <string>
#include "NetworkLayer.hpp"
#include "PollingType.h"

class PollingLayer  : public NetworkLayer {

  private:
    PollingType type;
    int size;
    int stride;

  public:
    PolingLayer();
    PolingLayer(std::string name, int* inputDimensions, int size, int stride, PollingType type);
    void setType(PollingType type);
    void setSize(int size);
    void setStride(int stride);
    PollingType getType();
    int getSize();
    int getStride();
    // ~PolingLayer();
};
#endif
