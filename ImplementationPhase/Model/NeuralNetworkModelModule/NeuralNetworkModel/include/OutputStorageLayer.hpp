#ifndef OUTPUTSTORAGELAYER_H_
#define OUTPUTSTORAGELAYER_H_

#include <string>
#include "NetworkLayer.hpp"
#include "MatrixDefine.hpp"

class OutputStorageLayer  : public NetworkLayer {

  private:
    MATRIX_3D(float) outputData;

  public:
    OutputStorageLayer();
    OutputStorageLayer(std::string name, MATRIX_3D(float) outputData);
    OutputStorageLayer(std::string name, MATRIX_3D(float) outputData, int* inputDimensions);
    void setData(MATRIX_3D(float) outputData);
    MATRIX_3D(float) getData();
    // ~CollectResultsLayer();
};
#endif
