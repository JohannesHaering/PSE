#ifndef TOPOLOGY_PAGE_H_
#define TOPOLOGY_PAGE_H_

#include "NeuralNetworkAdapter.hpp"

class TopologyPage {
    public: 
        void topologyChanged(NeuralNetworkAdapter nn);
        void update();
        void startButtonEnable(bool canStart);
};
#endif