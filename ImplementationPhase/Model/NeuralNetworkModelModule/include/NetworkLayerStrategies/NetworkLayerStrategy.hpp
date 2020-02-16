#ifndef NETWORKLAYERSTRATEGY_H_
#define NETWORKLAYERSTRATEGY_H_

#include <string>
#include <vector>
#include "MatrixDefine.hpp"
#include <CL/cl2.hpp>

class NetworkLayerStrategy {

	protected:
		TENSOR(float)* net;
    
    public:
	    virtual TENSOR(float) forward(TENSOR(float) input) = 0;
	    virtual TENSOR(float) backprob(TENSOR(float) feedback, float learningrate) = 0;

};
#endif
