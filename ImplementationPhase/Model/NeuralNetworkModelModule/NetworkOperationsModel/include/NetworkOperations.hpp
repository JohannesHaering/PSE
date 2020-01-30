#ifndef NETWORKOPERATIONS_H_
#define NETWORKOPERATIONS_H_

// #include <list>
#include <string>
// #include "MatrixDefine.hpp"
#include "LayerCode.hpp"

class NetworkOperations {

  private:
    std::string platformName;
    std::vector<LayerCode*> layerHandlers;

  public:
    NetworkOperations();
    NetworkOperations(std::string platformName);
    int addKernelCode(LayerType layerType, std::vector<std::string> kernelCode);
    MATRIX_3D(float) executeCalculation(NetworkLayer *layer, MATRIX_3D(float) inputData);
    TENSOR(float) executeBackPropagation(NetworkLayer *layer, TENSOR(float) inputData);
    std::string getplatformName();
};
#endif
