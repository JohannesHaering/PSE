#ifndef SIGMOIDLAYERCPP_H_
#define SIGMOIDLAYERCPP_H_

#include <string>
#include <math.h>
#include <vector>
#include "SoftmaxLayerStrategy.hpp"

class SigmoidLayerCPP : public SigmoidLayerStrategy
{
    public:
        SigmoidLayerCPP();
        MatrixDefine::TENSOR(float) forward(MatrixDefine::TENSOR(float) input_data) override;
        MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) updates) override;
};
#endif
