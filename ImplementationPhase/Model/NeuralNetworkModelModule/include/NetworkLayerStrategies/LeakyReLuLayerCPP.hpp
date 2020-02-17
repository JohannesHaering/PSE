#ifndef LEAKYRELULAYERCPP_H_
#define LEAKYRELULAYERCPP_H_

#include <string>
#include <math.h>
#include <vector>
#include "ReLuLayerStrategy.hpp"
#include "MatrixDefine.hpp"

class LeakyReLuLayerCPP : public ReLuLayerStrategy
{
    public:
        LeakyReLuLayerCPP();
		TENSOR(float) forward(TENSOR(float) input_data) override;
		TENSOR(float) backprob(TENSOR(float) updates) override;
};
#endif
