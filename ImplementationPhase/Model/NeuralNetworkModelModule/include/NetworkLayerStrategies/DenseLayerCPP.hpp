#ifndef DENSELAYERCPP_H_
#define DENSELAYERCPP_H_

#include <string>
#include <math.h>
#include <vector>
#include "DenseLayerStrategy.hpp"

class DenseLayerCPP : public DenseLayerStrategy
{
    public:
        DenseLayerCPP(std::vector<std::vector<float>>* weights, std::vector<float>* bias, int* inputSize, int* outputSize, *TENSOR(float) net);
        TENSOR(float) forward(TENSOR(float) input_data) override;
        TENSOR(float) backprob(TENSOR(float) updates, float learningRate) override;
};
#endif
