#include "TopologyInferencer.hpp"
#include "ViewFacade.hpp"

TopologyInferencer::TopologyInferencer() : page(ViewFacade::getTopologyPage()) { }

/*
* Changes the displayed topology of a neural network.
*/
void TopologyInferencer::startProcess() {
	page.topologyChanged(neuralNetwork);
	page.update();
}

/*
* Checks if the process can be started.
*/
bool TopologyInferencer::canStart() {
	if (&neuralNetwork == NULL) {
		return false; 
	}
	return true; 
}

/*
* Enables or disables the Start button accordingly.
*/
void TopologyInferencer::enableStart() {
	page.startButtonEnable(canStart());
}
