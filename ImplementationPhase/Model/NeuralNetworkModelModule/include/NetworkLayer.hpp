#ifndef NETWORKLAYER_H_
#define NETWORKLAYER_H_

#include <string>
#include <vector>
#include "LayerType.hpp"
#include "DeviceType.hpp"
#include "MatrixDefine.hpp"
#include <CL/cl2.hpp>

class NetworkLayer
{

protected:
	LayerType layerType;
	TENSOR(float)	net;
	TENSOR(float)	output_forward;
	TENSOR(float)	output_backward;

public:
	~NetworkLayer();

	LayerType getLayerType();

	virtual TENSOR(float) forward(TENSOR(float) input) = 0;
	virtual TENSOR(float) backprob(TENSOR(float) feedback, float learningrate) = 0;
	virtual void setMode(DeviceType device, cl_int deviceID);

	void setHeight(int height);
	void setWidth(int width);
	void setZ(int z);
	void setBatchSize(int batchsize);

	int getHeight();
	int getWidth();
	int getZ();
	int getBatchSize();

	int height;
	int width;
	int z;
	int batchSize;
};
#endif
