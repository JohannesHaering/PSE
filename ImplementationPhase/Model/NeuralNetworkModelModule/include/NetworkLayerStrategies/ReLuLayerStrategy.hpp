#ifndef RELULAYERSTRATEGY_H_
#define RELULAYERSTRATEGY_H_

#include <string>
#include <math.h>
#include <vector>
#include "NetworkLayerStrategy.hpp"
#include "MatrixDefine.hpp"

class ReLuLayerStrategy : public NetworkLayerStrategy
{
public:
	virtual TENSOR(float) forward(TENSOR(float) input_data) = 0;
	virtual TENSOR(float) backprob(TENSOR(float) updates) = 0;
};
#endif
