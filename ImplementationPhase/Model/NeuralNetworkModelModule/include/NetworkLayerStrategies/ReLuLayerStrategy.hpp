#ifndef RELULAYERSTRATEGY_H_
#define RELULAYERSTRATEGY_H_

#include <string>
#include <math.h>
#include <vector>
#include "NetworkLayerStrategy.hpp"

class ReLuLayerStrategy : public NetworkLayerStrategy
{
public:
	virtual MatrixDefine::TENSOR(float) forward(MatrixDefine::TENSOR(float) input_data);
	virtual MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) updates);
};
#endif
