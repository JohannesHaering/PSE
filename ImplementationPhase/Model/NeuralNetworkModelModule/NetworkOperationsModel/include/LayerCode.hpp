#ifndef LAYERCODE_H_
#define LAYERCODE_H_

// #include <list>
#include <string>
// #include "MatrixDefine.hpp"
#include "NeuralNetwork.hpp"

class LayerCode {

  private:
    std::vector<std::string> kernelCode;

  public:
    virtual void setKernelCode(std::vector<std::string> kernelCode);
    virtual MATRIX_3D(float) performCalculation(NetworkLayer *layer, MATRIX_3D(float) inputData) = 0;
    virtual TENSOR(float) performBackPropagation(NetworkLayer *layer, TENSOR(float) inputData) = 0;
};
#endif
