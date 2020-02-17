#include "NetworkLayer.hpp"

LayerType NetworkLayer::getLayerType() { return layerType; }

void NetworkLayer::setHeight(int height) { this->height = height; }

void NetworkLayer::setWidth(int width) { this->width = width; }

void NetworkLayer::setZ(int z) { this->z = z; }

void NetworkLayer::setBatchSize(int batchsize) { this->batchSize=batchsize;}

int NetworkLayer::getWidth()  { return width; }

int NetworkLayer::getHeight() { return height; }

int NetworkLayer::getZ(){ return z; }

int NetworkLayer::getBatchSize() { return batchSize;}
