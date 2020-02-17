#ifndef LEAKYRELULAYERCPU_H_
#define LEAKYRELULAYERCPU_H_

#include "MatrixDefine.hpp"
#include "LeakyReLuLayerStrategy.hpp"

#include <vector>

class LeakyReLuLayerCPU : public LeakyReLuLayerStrategy
{
public:
    MatrixDefine::TENSOR(float) forward(MatrixDefine::TENSOR(float) input_data) override;
    MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) updates) override;
};
#endif