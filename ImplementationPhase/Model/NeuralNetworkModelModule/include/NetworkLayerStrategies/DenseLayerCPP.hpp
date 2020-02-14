#ifndef DENSELAYERCPP_H_
#define DENSELAYERCPP_H_

#include <string>
#include <math.h>
#include <vector>
#include "DenseLayerStrategy.hpp"

class DenseLayerCPP : public DenseLayerStrategy
{
    public:
        DenseLayerCPP(std::vector<std::vector<float>>* weights, std::vector<float>* bias, int* inputSize, int* outputSize, *MatrixDefine::TENSOR(float) net);
        MatrixDefine::TENSOR(float) forward(MatrixDefine::TENSOR(float) input_data) override;
        MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) updates, float learningRate) override;
};
#endif
