#include "NeuralNetworkAdapter.hpp"

class TopologyPage {
    public: 
        void topologyChanged(NeuralNetworkAdapter nn);
        void update();
        void startButtonEnable(bool canStart);
};