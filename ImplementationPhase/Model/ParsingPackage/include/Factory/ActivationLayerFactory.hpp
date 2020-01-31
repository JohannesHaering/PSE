#ifndef ACTIVATION_LAYER_FACTORY
#define ACTIVATION_LAYER_FACTORY

#include "LayerFactory.hpp"
#include "NetworkLayer.hpp"
#include "Activation.hpp"

class ActivationLayerFactory : public LayerFactory
{
public:
	NetworkLayer buildLayer() override;
    ActivationLayerFactory setActivation(Activation activation);
    ActivationLayerFactory setAlpha(float alpha);

private:
	Activation activation;
	float alpha;
};
#endif
