#ifndef MAXPOOLLAYERASIC_H_
#define MAXPOOLLAYERASIC_H_
#include "MatrixDefine.hpp"
#include "OpenVino.hpp"
#include "MaxPoolLayerStrategy.hpp"
#include "ConnectionLayer.hpp"
#include <vector>

class MaxPoolLayerASIC : public MaxPoolLayerStrategy
{
public:
    MaxPoolLayerASIC();
    TENSOR(float) forward(TENSOR(float) input_data) override;
    TENSOR(float) backprob(TENSOR(float) updates) override;
};
#endif // MAXPOOLLAYERASIC_HPP
