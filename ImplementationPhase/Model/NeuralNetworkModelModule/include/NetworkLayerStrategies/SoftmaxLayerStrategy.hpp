#ifndef SOFTMAXLAYERSTRATEGY_H_
#define SOFTMAXLAYERSTRATEGY_H_

#include <string>
#include <math.h>
#include <vector>
#include "NetworkLayerStrategy.hpp"

class SoftmaxLayerStrategy : public NetworkLayerStrategy
{
public:
	virtual TENSOR(float) forward(TENSOR(float) input_data) = 0;
	virtual TENSOR(float) backprob(TENSOR(float) updates, TENSOR(float) output_forward) = 0;
};
#endif
