#ifndef POOLING_LAYER_FACTORY_H_
#define POOLING_LAYER_FACTORY_H_

#include "LayerFactory.hpp"
#include "NetworkLayer.hpp"
#include "PollingLayer.hpp"
#include "PollingType.hpp"

class PollingLayerFactory : public LayerFactory
{
public:
	NetworkLayer buildLayer() override;
	PollingLayerFactory setType(PollingType type);
	PollingLayerFactory setSize(int size);
	PollingLayerFactory setStride(int stride);

private:
	PollingType type;
	int size;
	int stride;
};
#endif