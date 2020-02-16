#ifndef SIGMOIDLAYERSTRATEGY_H_
#define SIGMOIDLAYERSTRATEGY_H_

#include <string>
#include <math.h>
#include <vector>
#include "NetworkLayerStrategy.hpp"

class SigmoidLayerStrategy : public NetworkLayerStrategy
{
public:
	virtual TENSOR(float) forward(TENSOR(float) input_data);
	virtual TENSOR(float) backprob(TENSOR(float) updates);
};
#endif
