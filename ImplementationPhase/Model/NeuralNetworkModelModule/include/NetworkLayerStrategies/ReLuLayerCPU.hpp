#ifndef RELULAYERCPU_H_
#define RELULAYERCPU_H_

#include "MatrixDefine.hpp"
#include "ReLuLayerStrategy.hpp"

#include <vector>

class ReLuLayerCPU : public ReLuLayerStrategy
{
public:
    MatrixDefine::TENSOR(float) forward(MatrixDefine::TENSOR(float) input_data) override;
    MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) updates) override;
};
#endif