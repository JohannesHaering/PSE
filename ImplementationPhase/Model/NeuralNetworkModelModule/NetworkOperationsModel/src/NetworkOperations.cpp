#include "NetworkOperations.hpp"

void NetworkOperations::NetworkOperations() NetworkOperations("Undefined_platform") {}

void NetworkOperations::NetworkOperations(std::string platformName) : platformName(platformName) {
  layerHandlers.resize(9);
}

int NetworkOperations::addKernelCode(LayerType layerType, std::vector<std::string> kernelCode) {
  switch(layerType) {
    case LayerType::CONVOLUTION : layers[LayerType::CONVOLUTION](new ConvolutionCode(kernelCode));
    break;
    case LayerType::ACTIVATION : layers[LayerType::ACTIVATION](new ActivationCode(kernelCode));
    break;
    case LayerType::POOLING : layers[LayerType::POOLING](new PoolingCode(kernelCode));
    break;
    case LayerType::LRN : layers[LayerType::LRN](new LocalResponseNormalizationCode(kernelCode));
    break;
    case LayerType::DENSE : layers[LayerType::DENSE](new DenseCode(kernelCode));
    break;
    case LayerType::FLATTEN : layers[LayerType::FLATTEN](new FlattenCode(kernelCode));
    break;
    case LayerType::DROPOUT : layers[LayerType::DROPOUT](new DropoutCode(kernelCode));
    break;
    case LayerType::COLLECT_RESULTS : layers[LayerType::COLLECT_RESULTS](new CollectResultsCode(kernelCode));
    break;
    case LayerType::INCEPTION : layers[LayerType::INCEPTION](new InceptionCode(kernelCode));
    break;
    default :
    return 1;
  }
  return 0;
}

Matrix_3D(float) NetworkOperations::executeCalculation(NetworkLayer *layer, Matrix_3D(float) inputData) {
  return layerHandlers[layer->getLayerType()]->performCalculation(layer, inputData)
}

TENSOR(float) NetworkOperations::executeBackPropagation(NetworkLayer *layer, TENSOR(float) inputData) {
  return layerHandlers[layer->getLayerType()]->performBackPropagation(layer, inputData)
}

std::string NetworkOperations::getplatformName() {
  return platformName;
}
