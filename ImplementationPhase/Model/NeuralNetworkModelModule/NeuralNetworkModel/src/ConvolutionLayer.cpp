#include "ConvolutionLayer.hpp"

ConvolutionLayer::ConvolutionLayer() : NetworkLayer(LayerType::CONVOLUTION), stride(0), padding(0) {}

ConvolutionLayer::ConvolutionLayer(std::string name, int* inputDimensions, TENSOR(float) weights, int stride, int padding) : NetworkLayer(name, inputDimensions, LayerType::CONVOLUTION), weightsTensor(weights), stride(stride), padding(padding) {}

void ConvolutionLayer::setWeightsTensor(TENSOR(float) weights) { weightsTensor = weights; }

void ConvolutionLayer::setStride(int stride) { this->stride = stride; }

void ConvolutionLayer::setPadding(int padding) { this->padding = padding; }

TENSOR(float) ConvolutionLayer::getWeightsTensor() { return weightsTensor; }

int ConvolutionLayer::getStride() { return stride; }

int ConvolutionLayer::getPadding() { return padding; }

int* ConvolutionLayer::getTensorDimensions() {
 return new int[4] { (int) weightsTensor[0][0][0].size(), (int) weightsTensor[0][0].size(), (int) weightsTensor[0].size(), (int) weightsTensor.size()}; }
