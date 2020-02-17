#ifndef LEAKYRELULAYERCPU_H_
#define LEAKYRELULAYERCPU_H_

#include "MatrixDefine.hpp"
#include "LeakyReLuLayerStrategy.hpp"

#include <vector>

class LeakyReLuLayerCPU : public LeakyReLuLayerStrategy
{
public:
    TENSOR(float) forward(TENSOR(float) input_data) override;
    TENSOR(float) backprob(TENSOR(float) updates) override;
};
#endif