#ifndef TOPOLOGY_INFERENCER_H_
#define TOPOLOGY_INFERENCER_H_

#include "NeuralNetworkAdapter.hpp"
#include "Inferencer.hpp"
#include "viewfacade.h"
#include "topology.h"

// class NeuralNetworkAdapter;
class TopologyInferencer : public Inferencer {

public:
	TopologyInferencer();
	void startProcess();
	bool canStart();
	void enableStart();

private:
	NeuralNetworkAdapter neuralNetwork;
	Topology page;

};
#endif
