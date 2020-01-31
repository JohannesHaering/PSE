#include "NetworkOperations.hpp"

NetworkOperations::NetworkOperations() : NetworkOperations("Undefined_platform") {}

NetworkOperations::NetworkOperations(std::string platformName) : platformName(platformName) {
  layerHandlers.resize(9);
}

int NetworkOperations::addKernelCode(LayerType layerType, std::vector<std::string> kernelCode) {
//  switch(layerType) {
//    case LayerType::CONVOLUTION : layerHandlers[LayerType::CONVOLUTION](new ConvolutionCode(kernelCode));
//    break;
//    case LayerType::ACTIVATION : layerHandlers[LayerType::ACTIVATION](new ActivationCode(kernelCode));
//    break;
//    case LayerType::POLLING : layerHandlers[LayerType::POLLING](new PoolingCode(kernelCode));
//    break;
//    case LayerType::LRN : layerHandlers[LayerType::LRN](new LocalResponseNormalizationCode(kernelCode));
//    break;
//    case LayerType::DENSE : layerHandlers[LayerType::DENSE](new DenseCode(kernelCode));
//    break;
//    case LayerType::FLATTEN : layerHandlers[LayerType::FLATTEN](new FlattenCode(kernelCode));
//    break;
//    case LayerType::DROPOUT : layerHandlers[LayerType::DROPOUT](new DropoutCode(kernelCode));
//    break;
//    case LayerType::COLLECT_RESULTS : layerHandlers[LayerType::COLLECT_RESULTS](new CollectResultsCode(kernelCode));
//    break;
//    case LayerType::INCEPTION : layerHandlers[LayerType::INCEPTION](new InceptionCode(kernelCode));
//    break;
//    default :
//    return 1;
//  }
  return 0;
}

MATRIX_3D(float) NetworkOperations::executeCalculation(NetworkLayer *layer, MATRIX_3D(float) inputData) {
  return layerHandlers[layer->getLayerType()]->performCalculation(layer, inputData);
}

TENSOR(float) NetworkOperations::executeBackPropagation(NetworkLayer *layer, TENSOR(float) inputData) {
  return layerHandlers[layer->getLayerType()]->performBackPropagation(layer, inputData);
}

std::string NetworkOperations::getplatformName() {
  return platformName;
}
