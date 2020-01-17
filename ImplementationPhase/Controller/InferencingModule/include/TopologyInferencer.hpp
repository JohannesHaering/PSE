#ifndef TOPOLOGY_INFERENCER_H_
#define TOPOLOGY_INFERENCER_H_

#include "Inferencer.hpp"
#include "ViewFacade.hpp"
#include "TopologyPage.hpp"

class TopologyInferencer : public Inferencer {

public:
	TopologyInferencer();
	void startProcess();
	bool canStart();
	void enableStart();

private:
	NeuralNetworkAdapter neuralNetwork;
	TopologyPage page;

};
#endif