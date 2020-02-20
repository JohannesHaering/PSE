#ifndef DENSELAYERASIC_H_
#define DENSELAYERASIC_H_
#include "MatrixDefine.hpp"
#include "DenseLayerStrategy.hpp"
#include "OpenVino.hpp"
#include <vector>
#include <include/DenseLayer.hpp>

class DenseLayerASIC : public DenseLayerStrategy
{
public:
    DenseLayerASIC();
    TENSOR(float) forward(TENSOR(float) input_data) override;
    TENSOR(float) backprob(TENSOR(float) updates) override;
private:
    DenseLayer* denseLayer;
};
#endif // DENSELAYERASIC_HPP
