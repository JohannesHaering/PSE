#ifndef LEAKYRELULAYERCPP_H_
#define LEAKYRELULAYERCPP_H_

#include <string>
#include <math.h>
#include <vector>
#include "LeakyReLuLayerStrategy.hpp"

class LeakyReLuLayerCPP : public LeakyReLuLayerStrategy
{
    public:
        LeakyReLuLayerCPP();
        TENSOR(float) forward(TENSOR(float) input_data);
        TENSOR(float) backprob(TENSOR(float) updates);
};
#endif
