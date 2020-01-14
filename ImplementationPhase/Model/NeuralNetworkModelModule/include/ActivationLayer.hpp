#ifndef ACTIVATIONLAYER_H_
#define ACTIVATIONLAYER_H_

#include <string>
#include "NetworkLayer.hpp"
#include "Activation.hpp"

class ActivationLayer  : public NetworkLayer {

  private:
    Activation function;

  public:
    ActivationLayer();
    ActivationLayer(std::string name, int* inputDimensions, Activation function);
    void setFunction(Activation function);
    Activation getFunction();
    virtual int* getTensorDimenssions();
    // ~ActivationLayer();
};
#endif
