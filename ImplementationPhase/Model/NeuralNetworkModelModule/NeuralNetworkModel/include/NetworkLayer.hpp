#ifndef NETWORKLAYER_H_
#define NETWORKLAYER_H_

#include <string>
#include <vector>
#include "LayerType.hpp"
#include "MatrixDefine.hpp"

class NetworkLayer {

protected:
	LayerType layerType;
	int batchSize;
	MatrixDefine::TENSOR(float) input;
	MatrixDefine::TENSOR(float) output;

public:
	LayerType getLayerType();
	void setBatchSize(int batchsize);

	virtual MatrixDefine::TENSOR(float) forward(std::vector<float> net) = 0;
	virtual MatrixDefine::TENSOR(float) backprob(std::vector<float> net, float learningrate) = 0;
};
#endif
