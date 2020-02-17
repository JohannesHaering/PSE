#ifndef DENSELAYERSTRATEGY_H_
#define DENSELAYERSTRATEGY_H_

#include <string>
#include <math.h>
#include <vector>
#include "NetworkLayerStrategy.hpp"
#include "MatrixDefine.hpp"

class DenseLayerStrategy : public NetworkLayerStrategy
{
protected: 
	int inputSize;
	int outputSize;

public:
	virtual TENSOR(float) forward(TENSOR(float) input_data);
	virtual TENSOR(float) backprob(TENSOR(float) updates, float learningRate, TENSOR(float) net);
};
#endif
