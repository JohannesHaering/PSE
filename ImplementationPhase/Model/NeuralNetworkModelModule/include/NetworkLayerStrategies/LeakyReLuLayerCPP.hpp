#ifndef LEAKYRELULAYERCPP_H_
#define LEAKYRELULAYERCPP_H_

#include <string>
#include <math.h>
#include <vector>
#include "ReLuLayerStrategy.hpp"

class LeakyReLuLayerCPP : public ReLuLayerStrategy
{
    public:
        LeakyReLuLayerCPP();
        MatrixDefine::TENSOR(float) forward(MatrixDefine::TENSOR(float) input_data) override;
        MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) updates) override;
};
#endif
