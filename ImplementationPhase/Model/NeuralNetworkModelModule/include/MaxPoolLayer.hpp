#ifndef MAXPOOLLAYER_H_
#define MAXPOOLLAYER_H_

#include <string>
#include <vector>
#include "ConnectionLayer.hpp"
#include "MaxPoolLayerStrategy.hpp"

class MaxPoolLayer : public ConnectionLayer
{
private: 
  	int filterwidth = 3;
	std::vector<TENSOR(float)> maxValueMap;
	TENSOR(float) output;
    MaxPoolLayerStrategy* layerStrategy;
public:
	MaxPoolLayer();
	TENSOR(float) forward(TENSOR(float) input_data) override;
	TENSOR(float) backprob(TENSOR(float) updates, float learningRate) override;
	void setMode(DeviceType device, cl_int deviceID) override;
};
#endif
