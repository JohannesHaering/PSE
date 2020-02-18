F #ifndef CONVOLUTIONLAYER_H_
#define CONVOLUTIONLAYER_H_

#include <string>
#include "NetworkLayer.hpp"
#include "MatrixDefine.hpp"
#include "ConnectionLayer.hpp"

    class ConvolutionLayer : public ConnectionLayer
{

private:
  TENSOR(float)
  weightsTensor;
  int filterSizeX;
  int filterSizeY;
  int filterSizeZ;
  int numFilters;
  int stride;
  int padding;

  //helper functions forward
  float dotProduct(MATRIX_3D(float) input, MATRIX_3D(float) filter, int xStart, int yStart);
  MATRIX_2D(float)
  Convolute(MATRIX_3D(float) input, MATRIX_3D(float) filter, int stride, int padding);

  //helper functions backward
  float calcWeightUpdate(TENSOR(float) feedback, int numFilters, int filterPosZ, int filterPosY, int filterPosX);
  MATRIX_3D(float)
  backpropError(MATRIX_3D(float) feedback);

public:
  ConvolutionLayer();
  ConvolutionLayer(TENSOR(float) filter, int stride, int padding);
  ConvolutionLayer(int filterSizeX, int filterSizeY, int filterSizeZ, int numFilters, int stride, int padding);
  TENSOR(float)
  forward(TENSOR(float) net) override;
  TENSOR(float)
  backprob(TENSOR(float) feedback, float learningRate) override;
  TENSOR(float)
  getWeightsTensor();
  int getStride();
  int getPadding();
  void setWeightsTensor(TENSOR(float) newWeights);
  void setStride(int stride);
  void setPadding(int padding);
  virtual int *getTensorDimensions();
  void setMode(DeviceType device, cl_int deviceID) override;
  // ~ConvolutionLayer();
};
#endif
