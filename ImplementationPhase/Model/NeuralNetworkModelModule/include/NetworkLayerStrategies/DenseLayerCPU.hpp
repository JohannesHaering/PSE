#ifndef DENSELAYERCPU_H_
#define DENSELAYERCPU_H_

#include "DenseLayerStrategy.hpp"
#include "MatrixDefine.hpp"
#include "DenseLayer.hpp"
#include "DenseLayer.hpp"

class DenseLayerCPU : public DenseLayerStrategy
{
private:
	DenseLayer* layer;
public:
    DenseLayerCPU(DenseLayer* layer, int inputSize, int outputSize);
    TENSOR(float) forward(TENSOR(float) input_data) override;
  TENSOR(float) backprob(TENSOR(float) updates) override;
    TENSOR(float) backprob(TENSOR(float) updates, float learningRate, TENSOR(float) net) override;
};
#endif
