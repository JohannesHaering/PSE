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
        MatrixDefine::TENSOR(float) forward(MatrixDefine::TENSOR(float) input_data) override;
        MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) updates) override;
};
#endif
