#ifndef DENSELAYER_H_
#define DENSELAYER_H_

#include <string>
#include "NetworkLayer.hpp"
#include "MatrixDefine.hpp"

class DenseLayer  : public NetworkLayer {

  private:
    MATRIX_2D(double) matrix;

  public:
    DenseLayer();
    DenseLayer(std::string name, int* inputDimensions, MATRIX_2D(double) matrix);
    void setMatrix(MATRIX_2D(double) matrix);
    MATRIX_2D(double) getMatrix();
    virtual int* getTensorDimensions();
    // ~DenseLayer();
};
#endif
