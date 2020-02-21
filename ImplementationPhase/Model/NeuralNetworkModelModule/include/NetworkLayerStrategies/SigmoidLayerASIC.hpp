#ifndef SIGMOIDLAYERASIC_H_
#define SIGMOIDLAYERASIC_H_
#include "SigmoidLayerStrategy.hpp"
#include "OpenVino.hpp"

class SigmoidLayerASIC : public SigmoidLayerStrategy
{
public:
    SigmoidLayerASIC();
    TENSOR(float) forward(TENSOR(float) input_data) override;
    TENSOR(float) backprob(TENSOR(float) updates) override;
};
#endif // SIGMOIDLAYERASIC_H
