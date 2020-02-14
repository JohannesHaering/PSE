#ifndef DENSELAYER_H_
#define DENSELAYER_H_

#include <string>
#include <math.h>
#include <vector>
#include "ConnectionLayer.hpp"

class DenseLayer : public ConnectionLayer
{
private: 
  std::vector<std::vector<float>> weights;
	std::vector<float> bias;

	float learningRate;
	int inputSize;
	int outputSize;

public:
	DenseLayer(int inputSize, int outputSize);
	DenseLayer(int inputSize, int outputSize, float learningRate);
	void set_bias(std::vector<float> new_bias);
	void set_weights(std::vector<std::vector<float>> new_weights);
	MatrixDefine::TENSOR(float) forward(MatrixDefine::TENSOR(float) input_data) override;
	MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) updates, float learningRate) override;
  std::vector<std::vector<float>> get_weights();
	std::vector<float> get_biase();
};
#endif
