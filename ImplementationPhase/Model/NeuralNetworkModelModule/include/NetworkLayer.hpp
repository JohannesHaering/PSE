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
  TENSOR(float) net;
  TENSOR(float) output_forward;
  TENSOR(float) output_backward;

public:
	LayerType getLayerType();

	virtual TENSOR(float) forward(TENSOR(float) input) = 0;
	virtual TENSOR(float) backprob(TENSOR(float) feedback, float learningrate) = 0;
  virtual void setMode(DeviceType device, cl_int deviceID);
};
#endif

