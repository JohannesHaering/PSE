#ifndef SOFTMAXLAYERSTRATEGY_H_
#define SOFTMAXLAYERSTRATEGY_H_

#include <string>
#include <math.h>
#include <vector>
#include "NetworkLayerStrategy.hpp"

class SoftmaxLayerStrategy : public NetworkLayerStrategy
{
public:
	virtual MatrixDefine::TENSOR(float) forward(MatrixDefine::TENSOR(float) input_data);
	virtual MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) updates, MatrixDefine::TENSOR(float) output_forward);
};
#endif
