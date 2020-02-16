#ifndef DENSELAYERSTRATEGY_H_
#define DENSELAYERSTRATEGY_H_

#include <string>
#include <math.h>
#include <vector>
#include "NetworkLayerStrategy.hpp"

class DenseLayerStrategy : public NetworkLayerStrategy
{
protected: 
    std::vector<std::vector<float>>* weights;
	std::vector<float>* bias;

	int* inputSize;
	int* outputSize;

public:
	virtual TENSOR(float) forward(TENSOR(float) input_data);
	virtual TENSOR(float) backprob(TENSOR(float) updates, float learningRate);
};
#endif
