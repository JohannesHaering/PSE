#ifndef DENSELAYERSTRATEGY_H_
#define DENSELAYERSTRATEGY_H_

#include <string>
#include <math.h>
#include <vector>
#include "DenseLayer.hpp"

class DenseLayerStrategy : public NetworkLayerStrategy
{
protected: 
    std::vector<std::vector<float>>* weights;
	std::vector<float>* bias;
	std::vector<float>

	float* learningRate;
	int* inputSize;
	int* outputSize;

public:
	virtual MatrixDefine::TENSOR(float) forward(MatrixDefine::TENSOR(float) input_data);
	virtual MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) updates, float learningRate);
};
#endif
