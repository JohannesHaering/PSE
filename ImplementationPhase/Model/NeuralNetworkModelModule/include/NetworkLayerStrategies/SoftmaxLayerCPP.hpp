#ifndef SOFTMAXLAYERCPP_H_
#define SOFTMAXLAYERCPP_H_

#include <string>
#include <math.h>
#include <vector>
#include "SoftmaxLayerStrategy.hpp"
#include "MatrixDefine.hpp"

class SoftmaxLayerCPP : public SoftmaxLayerStrategy
{
public:
    SoftmaxLayerCPP();
    TENSOR(float) forward(TENSOR(float) input_data) override;
    TENSOR(float) backprob(TENSOR(float) updates) override;
    TENSOR(float) backprob(TENSOR(float) updates, TENSOR(float) output_forward) override;
private:
    void calcMaxVec(std::vector<float> *maxVec, TENSOR(float) net);

};
#endif
