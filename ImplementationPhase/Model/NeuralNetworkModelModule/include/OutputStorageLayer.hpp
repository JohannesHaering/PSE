#ifndef OUTPUTSTORAGELAYER_H_
#define OUTPUTSTORAGELAYER_H_

#include <string>
#include "NetworkLayer.hpp"
#include "MatrixDefine.hpp"

class OutputStorageLayer  : public NetworkLayer {

  private:
    MATRIX_3D(double) outputData;

  public:
    OutputStorageLayer();
    OutputStorageLayer(std::string name, MATRIX_3D(double) outputData);
    OutputStorageLayer(std::string name, MATRIX_3D(double) outputData, int* inputDimensions);
    void setData(MATRIX_3D(double) outputData);
    MATRIX_3D(double) getData();
    // ~CollectResultsLayer();
};
#endif
