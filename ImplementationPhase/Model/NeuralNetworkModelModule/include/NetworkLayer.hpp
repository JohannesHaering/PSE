#ifndef NETWORKLAYER_H_
#define NETWORKLAYER_H_

#include <string>
#include <vector>
#include "LayerType.hpp"
#include "MatrixDefine.hpp"
#include "DeviceType.hpp"
#include <CL/cl2.hpp>

class NetworkLayer {

protected:
	LayerType layerType;
  MatrixDefine::TENSOR(float) net;
  MatrixDefine::TENSOR(float) output_forward;
  MatrixDefine::TENSOR(float) output_backward;

public:
	LayerType getLayerType();

	virtual MatrixDefine::TENSOR(float) forward(MatrixDefine::TENSOR(float) input) = 0;
	virtual MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) feedback, float learningrate) = 0;
  virtual void setMode(DeviceType device, cl_int deviceID);
};
#endif
