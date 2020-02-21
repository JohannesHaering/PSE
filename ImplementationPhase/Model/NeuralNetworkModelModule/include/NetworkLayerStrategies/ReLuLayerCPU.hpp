#ifndef RELULAYERCPU_H_
#define RELULAYERCPU_H_

#include "MatrixDefine.hpp"
#include "ReLuLayerStrategy.hpp"

#include <vector>

class ReLuLayerCPU : public ReLuLayerStrategy
{
public:
    TENSOR(float) forward(TENSOR(float) input_data) override;
    TENSOR(float) backprob(TENSOR(float) updates) override;
};
#endif