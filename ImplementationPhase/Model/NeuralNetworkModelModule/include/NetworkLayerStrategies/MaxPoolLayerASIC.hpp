#ifndef MAXPOOLLAYERASIC_H_
#define MAXPOOLLAYERASIC_H_
#include "MatrixDefine.hpp"
#include "OpenVino.hpp"
#include "ConnectionLayer.hpp"
#include <vector>

class MaxPoolLayerASIC : public ConnectionLayer
{
public:
    TENSOR(float) forward(TENSOR(float) input_data) override;
    TENSOR(float) backprob(TENSOR(float) updates, float learningRate) override;
    void setMode(DeviceType device, cl_int deviceID) override;
};
#endif // MAXPOOLLAYERASIC_HPP
