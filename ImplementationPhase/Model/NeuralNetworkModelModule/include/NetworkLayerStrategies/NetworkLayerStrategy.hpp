#ifndef NETWORKLAYERSTRATEGY_H_
#define NETWORKLAYERSTRATEGY_H_

#include <string>
#include <vector>
#include "MatrixDefine.hpp"

class NetworkLayerStrategy
{

protected:
	TENSOR(float) * net;

public:
	virtual TENSOR(float) forward(TENSOR(float) input_data) = 0;
	virtual TENSOR(float) backprob(TENSOR(float) updates) = 0;
};
#endif
