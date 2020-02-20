#ifndef DENSELAYER_H_
#define DENSELAYER_H_

#include <string>
#include <math.h>
#include <vector>
#include "ConnectionLayer.hpp"

class DenseLayer : public ConnectionLayer
{
private: 
	MATRIX_2D(float) weights;
	std::vector<float> bias;

	float learningRate;
	int inputSize;
	int outputSize;

public:
	DenseLayer(int inputSize, int outputSize);
	DenseLayer(int inputSize, int outputSize, float learningRate);

	void set_bias(std::vector<float> new_bias);
	void set_weights(MATRIX_2D(float) new_weights);
	TENSOR(float) forward(TENSOR(float) input_data) override;
	TENSOR(float) backprob(TENSOR(float) updates, float learningRate) override;
 	MATRIX_2D(float) get_weights();
	std::vector<float> get_biase();
	void setMode(DeviceType device, cl_int deviceID) override;
};
#endif

