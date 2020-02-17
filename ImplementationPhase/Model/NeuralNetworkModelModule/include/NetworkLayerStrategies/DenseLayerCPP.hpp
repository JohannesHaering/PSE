#ifndef DENSELAYERCPP_H_
#define DENSELAYERCPP_H_

#include <string>
#include <math.h>
#include <vector>
#include "DenseLayerStrategy.hpp"
#include "DenseLayer.hpp"
#include "MatrixDefine.hpp"

class DenseLayerCPP : public DenseLayerStrategy
{
  private:
    DenseLayer* layer;

    public:
        DenseLayerCPP(DenseLayer* layer, int inputSize, int outputSize);
	      TENSOR(float) forward(TENSOR(float) input_data) override;
	      TENSOR(float) backprob(TENSOR(float) updates) override;

        TENSOR(float) backprob(TENSOR(float) updates, float learningRate, TENSOR(float) net) override;
};
#endif
