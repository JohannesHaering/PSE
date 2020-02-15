#ifndef CONVOLUTIONLAYER_H_
#define CONVOLUTIONLAYER_H_

#include <string>
#include "NetworkLayer.hpp"
#include "MatrixDefine.hpp"

class ConvolutionLayer  : public ConnectionLayer {

  private:
    TENSOR(float) weightsTensor;
    int filterSizeX;
    int filterSizeY;
    int filterSizeZ;
    int numFilters;
    int stride;
    int padding;

  public:
    ConvolutionLayer();
    ConvolutionLayer(int filterSizeX, int filterSizeY, int filterSizeZ, int numFilters, int stride, int padding);
    TENSOR(float) getWeightsTensor();
    int getStride();
    int getPadding();
    virtual int* getTensorDimensions();
    // ~ConvolutionLayer();
};
#endif
