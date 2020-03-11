#ifndef FLATTENLAYER_H_
#define FLATTENLAYER_H_

#include <string>
#include "ConnectionLayer.hpp"
#include "MatrixDefine.hpp"

class FlattenLayer : public ConnectionLayer{
private: 
  int oldx;
  int oldy;
  int oldz;

public:
   FlattenLayer();
	TENSOR(float) forward(TENSOR(float) input_data) override;
	TENSOR(float) backprob(TENSOR(float) updates, float learningRate) override;
	void setMode(DeviceType device) override;
};
#endif
