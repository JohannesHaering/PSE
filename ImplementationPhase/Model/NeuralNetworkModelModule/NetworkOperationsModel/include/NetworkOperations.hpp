#ifndef NETWORKOPERATIONS_H_
#define NETWORKOPERATIONS_H_

// #include <list>
#include <string>
#include "MatrixDefine.hpp"

class NetworkOperations {

  private:
    std::string platformName;
    std::vector<*LayerCode> layerHandlers;

  public:
    void NetworkOperations();
    void NetworkOperations(std::string platformName);
    int addKernelCode(LayerType layerType, std::vector<std::string> kernelCode);
    Matrix_3D(float) executeCalculation(NetworkLayer *layer, Matrix_3D(float) inputData);
    TENSOR(float) executeBackPropagation(NetworkLayer *layer, TENSOR(float) inputData);
    std::string getplatformName();
};
#endif
