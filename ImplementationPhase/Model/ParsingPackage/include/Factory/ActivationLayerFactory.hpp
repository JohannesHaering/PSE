#ifndef ACTIVATION_LAYER_FACTORY
#define ACTIVATION_LAYER_FACTORY

#include "LayerFactory.hpp"
#include "NetworkLayer.hpp"
#include "Activation.hpp"
#include "LayerType.hpp"

class ActivationLayerFactory : public LayerFactory
{
public:
  	NetworkLayer* buildLayer() override;
    ActivationLayerFactory setActivation(LayerType activation);
    ActivationLayerFactory setAlpha(float alpha);

private:
	LayerType activation;
	float alpha;
};
#endif
