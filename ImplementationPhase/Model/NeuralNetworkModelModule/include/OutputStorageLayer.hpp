#ifndef OUTPUTSTORAGELAYER_H_
#define OUTPUTSTORAGELAYER_H_

#include <string>
#include "NetworkLayer.hpp"
#include "MatrixDefine.h"

class OutputStorageLayer  : public NetworkLayer {
  + <<constructor>> CollectResultsLayer() : void
  + <<constructor>> CollectResultsLayer(name : string, outputData : double[][][]) : void

  private:
    MATRIX_3D(double) outputData;

  public:
    CollectResultsLayer();
    CollectResultsLayer(std::string name, MATRIX_3D(double) outputData);
    // ~CollectResultsLayer();
};
#endif
