#ifndef DENSELAYER_H_
#define DENSELAYER_H_

#include <string>
#include "NetworkLayer.hpp"
#include "MatrixDefine.hpp"

class DenseLayer  : public NetworkLayer {

  private:
    MATRIX_2D(float) matrix;

  public:
    DenseLayer();
    DenseLayer(std::string name, int* inputDimensions, MATRIX_2D(float) matrix);
    void setMatrix(MATRIX_2D(float) matrix);
    MATRIX_2D(float) getMatrix();
    virtual int* getTensorDimensions();
    // ~DenseLayer();
};
#endif
