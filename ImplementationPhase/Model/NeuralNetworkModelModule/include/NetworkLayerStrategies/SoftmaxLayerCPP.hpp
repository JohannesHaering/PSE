#ifndef SOFTMAXLAYERCPP_H_
#define SOFTMAXLAYERCPP_H_

#include <string>
#include <math.h>
#include <vector>
#include "SoftmaxLayerStrategy.hpp"

class SoftmaxLayerCPP : public SoftmaxLayerStrategy
{
    public:
        SoftmaxLayerCPP();
        MatrixDefine::TENSOR(float) forward(MatrixDefine::TENSOR(float) input_data) override;
        MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) updates, MatrixDefine::TENSOR(float) output_forward) override;
};
#endif
