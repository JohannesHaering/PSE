#ifndef DENSELAYERCPU_H_
#define DENSELAYERCPU_H_

#include "DenseLayerStrategy.hpp"
#include "MatrixDefine.hpp"

class DenseLayerCPU : public DenseLayerStrategy
{
public:
    DenseLayerCPU(std::vector<std::vector<float>> *weights, std::vector<float> *bias, int *inputSize, int *outputSize);
    MatrixDefine::TENSOR(float) forward(MatrixDefine::TENSOR(float) input_data) override;
    MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) updates, float learningRate) override;
};
#endif