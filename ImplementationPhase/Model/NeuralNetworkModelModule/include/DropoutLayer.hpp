#ifndef DROPOUTLAYER_H_
#define DROPOUTLAYER_H_

#include <string>
#include "NetworkLayer.hpp"

class DropoutLayer  : public NetworkLayer {

  private:
    float dropoutRate;

  public:
    DropoutLayer();
    DropoutLayer(std::string name, int* inputDimensions, float dropoutRate);
    void setDropoutRate(float dropoutRate);
    float getDropoutRate();
    // ~DropoutLayer();
};
#endif
