#include "LayerFactory.hpp"
#include "NetworkLayer.hpp"

#include <string>
#include <vector>

LayerFactory* LayerFactory::setInputDimensions(int* dimensions)
{
	this->inputDimensions = dimensions;
	return this;
}

LayerFactory* LayerFactory::setBatchSize(int batchSize)
{
	this->batchSize = batchSize;
	return this;
}

LayerFactory* LayerFactory::setHeight(int height)
{
	this->height = height;
	return this;
}

LayerFactory* LayerFactory::setWidth(int width)
{
	this->width = width;
	return this;
}

LayerFactory* LayerFactory::setZ(int z)
{
	this->z = z;
	return this;
}
