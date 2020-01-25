#ifndef TOPOLOGY_INFERENCER_H_
#define TOPOLOGY_INFERENCER_H_

#include "NeuralNetworkAdapter.hpp"
#include "Inferencer.hpp"
#include "ViewFacade.hpp"
#include "TopologyPanel.hpp"

// class NeuralNetworkAdapter;
class TopologyInferencer : public Inferencer {

public:
	TopologyInferencer();
	void startProcess();
	bool canStart();
	void enableStart();

private:
	NeuralNetworkAdapter neuralNetwork;
	TopologyPanel page;

};
#endif
