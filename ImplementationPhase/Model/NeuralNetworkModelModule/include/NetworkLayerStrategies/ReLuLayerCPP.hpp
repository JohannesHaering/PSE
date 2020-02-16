#ifndef RELULAYERCPP_H_
#define RELULAYERCPP_H_

#include <string>
#include <math.h>
#include <vector>
#include "ReLuLayerStrategy.hpp"

class ReLuLayerCPP : public ReLuLayerStrategy
{
    public:
        ReLuLayerCPP();
        TENSOR(float) forward(TENSOR(float) input_data) override;
        TENSOR(float) backprob(TENSOR(float) updates) override;
};
#endif
