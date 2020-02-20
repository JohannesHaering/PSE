#ifndef MAXPOOLLAYERSTRATEGY_H_
#define MAXPOOLLAYERSTRATEGY_H_
#include <string>
#include <math.h>
#include <vector>
#include "NetworkLayerStrategy.hpp"
#include "MatrixDefine.hpp"

class MaxPoolLayerStrategy : public NetworkLayerStrategy
{
public:
    virtual TENSOR(float) forward(TENSOR(float) input_data) = 0;
    virtual TENSOR(float) backprob(TENSOR(float) updates) = 0;
};
#endif //
