#ifndef NETWORKLAYER_H_
#define NETWORKLAYER_H_

#include <string>
#include <vector>
#include "LayerType.hpp"

class NetworkLayer {

protected:
	// std::string name;
	int* inputDimensions;
	LayerType layerType;
	int batchSize;
	int height, width, z;

public:
	/* NetworkLayer(std::string name, int* inputDimensions, LayerType layerType);
	NetworkLayer(LayerType layerType);

	void setName(std::string name);
	void setInputDimensions(int* inputDimensions);
	std::string getName();*/
	LayerType getLayerType();
	int* getInputDimensions();
	void setInputDimension(int* inputDimensions);
	int getBatchSize();
	void setBatchSize(int batchsize);
	int getWidth();
	void setWidth(int width);
	int getHeight();
	void setHeight(int height);
	int getZ();
	void setZ(int z);

	// virtual int* getTensorDimensions();
	// ~NetworkLayer();
	virtual std::vector<float> forward(std::vector<float> net) = 0;
	virtual std::vector<float> backprob(std::vector<float> net, float learningrate) = 0;
protected:
	std::vector<float> input;
	std::vector<float> output;
};
#endif
