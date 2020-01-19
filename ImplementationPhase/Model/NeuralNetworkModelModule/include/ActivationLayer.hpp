#ifndef ACTIVATIONLAYER_H_
#define ACTIVATIONLAYER_H_

#include <string>
#include "NetworkLayer.hpp"
#include "Activation.hpp"

class ActivationLayer  : public NetworkLayer {

  private:
    Activation function;
    float alpha;

  public:
    ActivationLayer();
    ActivationLayer(std::string name, int* inputDimensions, Activation function);
    ActivationLayer(std::string name, int* inputDimensions, Activation function, float alpha);
    void setFunction(Activation function);
    void setAlpha(float alpha);
    Activation getFunction();
    float getAlpha();
    virtual int* getTensorDimenssions();
    // ~ActivationLayer();
};
#endif
