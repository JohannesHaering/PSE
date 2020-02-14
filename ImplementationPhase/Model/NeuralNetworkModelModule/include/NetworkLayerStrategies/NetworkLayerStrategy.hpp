#ifndef NETWORKLAYERSTRATEGY_H_
#define NETWORKLAYERSTRATEGY_H_

#include <string>
#include <vector>
#include "MatrixDefine.hpp"
#include <CL/cl2.hpp>

class NetworkLayerStrategy {

	protected:
		MatrixDefine::TENSOR(float)* net;
    
    public:
	    virtual MatrixDefine::TENSOR(float) forward(MatrixDefine::TENSOR(float) input) = 0;
	    virtual MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) feedback, float learningrate) = 0;

};
#endif
