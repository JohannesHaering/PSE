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

    //helper functions forward
    float dotProduct(MATRIX_3D(float) input, MATRIX_3D(float) filter, int xStart, int yStart);
    MATRIX_2D(float) Convolute(MATRIX_3D(float) input, MATRIX_3D(float) filter, int stride, int padding);

    //helper functions backward
    float calcWeightUpdate(TENSOR(float) feedback, int numFilters, int filterPosZ, int filterPosY, int filterPosX);
    MATRIX_3D(float) backpropError(MATRIX_3D(float) feedback);

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

