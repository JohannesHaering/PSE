#ifndef CONVOLUTIONLAYER_H_
#define CONVOLUTIONLAYER_H_

#include <string>
#include "NetworkLayer.hpp"
#include "MatrixDefine.hpp"

class ConvolutionLayer  : public NetworkLayer {

  private:
    TENSOR(double) weightsTensor;
    int stride;
    int padding;

  public:
    ConvolutionLayer();
    ConvolutionLayer(std::string name, int* inputDimensions, TENSOR(double) weights, int stride, int padding);
    void setWeightsTensor(TENSOR(double) weights);
    void setStride(int stride);
    void setPadding(int padding);
    TENSOR(double) getWeightsTensor();
    int getStride();
    int getPadding();
    virtual int* getTensorDimenssions();
    // ~ConvolutionLayer();
};
#endif
