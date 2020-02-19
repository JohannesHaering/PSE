#ifndef LEAKYRELULAYERASIC_H_
#define LEAKYRELULAYERASIC_H_
#include "LeakyReLuLayerStrategy.hpp"
class LeakyReLuLayerASIC : public LeakyReLuLayerStrategy
{
public:
    LeakyReLuLayerASIC();
    TENSOR(float) forward(TENSOR(float) input_data) override;
    TENSOR(float) backprob(TENSOR(float) updates) override;
};
#endif // LEAKYRELULAYERASIC_H
