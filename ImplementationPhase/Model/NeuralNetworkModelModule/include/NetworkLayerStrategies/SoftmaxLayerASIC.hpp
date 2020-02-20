#ifndef SOFTMAXLAYERASIC_H_
#define SOFTMAXLAYERASIC_H_
#include "SoftmaxLayerStrategy.hpp"
#include "OpenVino.hpp"

class SoftmaxLayerASIC : public SoftmaxLayerStrategy
{
public:
    SoftmaxLayerASIC();
    TENSOR(float) forward(TENSOR(float) input_data) override;
    TENSOR(float) backprob(TENSOR(float) updates) override;
    TENSOR(float) backprob(TENSOR(float) updates, TENSOR(float) output_forward) override;
};
#endif // SOFTMAXLAYERASIC_H
