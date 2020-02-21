#ifndef RELULAYERASIC_H_
#define RELULAYERASIC_H_

#include "MatrixDefine.hpp"
#include "ReLuLayerStrategy.hpp"
#include "OpenVino.hpp"
#include <vector>

class ReLuLayerASIC : public ReLuLayerStrategy
{
public:
    ReLuLayerASIC();
    TENSOR(float) forward(TENSOR(float) input_data) override;
    TENSOR(float) backprob(TENSOR(float) updates) override;
};
#endif
