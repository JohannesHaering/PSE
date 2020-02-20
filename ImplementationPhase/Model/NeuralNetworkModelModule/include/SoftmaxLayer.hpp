#ifndef SOFTMAX_LAYER_H_
#define SOFTMAX_LAYER_H_

#include <string>
#include <vector>
#include "ActivationLayer.hpp"
#include "SoftmaxLayerStrategy.hpp"
#include "MatrixDefine.hpp"

class SoftmaxLayer : public ActivationLayer
{

private:
    SoftmaxLayerStrategy *layerStrategy;

public:
    SoftmaxLayer();
    TENSOR(float)  forward(TENSOR(float) net) override;
    TENSOR(float) backprob(TENSOR(float) feedback, float learningrate) override;
    TENSOR(float) backprob(TENSOR(float) feedback);
    std::vector<float> calcCEError(TENSOR(float) target);
    void setMode(DeviceType device) override;
};
#endif
