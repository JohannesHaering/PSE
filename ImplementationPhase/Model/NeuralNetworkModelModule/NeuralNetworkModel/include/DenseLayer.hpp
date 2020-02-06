#ifndef DENSELAYER_H_
#define DENSELAYER_H_

#include <vector>
#include <string>
#include "NetworkLayer.hpp"
#include "MatrixDefine.hpp"

class DenseLayer  : public NetworkLayer {

  private:
    MATRIX_2D(float) matrix;
    std::vector<float> bias;

  public:
    DenseLayer();
    DenseLayer(std::string name, int* inputDimensions, MATRIX_2D(float) matrix, std::vector<float> bias);
    void setMatrix(MATRIX_2D(float) matrix);
    MATRIX_2D(float) getMatrix();
    virtual int* getTensorDimensions();
    std::vector<float> getBias();
    // ~DenseLayer();
};
#endif
