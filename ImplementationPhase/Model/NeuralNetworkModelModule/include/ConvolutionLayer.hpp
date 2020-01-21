#ifndef CONVOLUTIONLAYER_H_
#define CONVOLUTIONLAYER_H_

#include <string>
#include "NetworkLayer.hpp"
#include "MatrixDefine.hpp"

class ConvolutionLayer  : public NetworkLayer {

  private:
    TENSOR(float) weightsTensor;
    int stride;
    int padding;

  public:
    ConvolutionLayer();
    ConvolutionLayer(std::string name, int* inputDimensions, TENSOR(float) weights, int stride, int padding);
    void setWeightsTensor(TENSOR(float) weights);
    void setStride(int stride);
    void setPadding(int padding);
    TENSOR(float) getWeightsTensor();
    int getStride();
    int getPadding();
    virtual int* getTensorDimensions();
    // ~ConvolutionLayer();
};
#endif
