#ifndef SIGMOIDLAYERCPP_H_
#define SIGMOIDLAYERCPP_H_

#include <string>
#include <math.h>
#include <vector>
#include "SigmoidLayerStrategy.hpp"

class SigmoidLayerCPP : public SigmoidLayerStrategy
{
    public:
        SigmoidLayerCPP();
        TENSOR(float) forward(TENSOR(float) input_data) override;
        TENSOR(float) backprob(TENSOR(float) updates) override;
};
#endif
