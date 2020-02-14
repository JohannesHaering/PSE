#include "LayerFactory.hpp"
#include "NetworkLayer.hpp"

#include <string>
#include <vector>

LayerFactory* LayerFactory::setInputDimensions(int* dimensions)
{
	this->inputDimensions = dimensions;
	return this;
}

LayerFactory* LayerFactory::setBatchSize(int batchSize) {
	this->batchSize = batchSize;
	return this;
}
