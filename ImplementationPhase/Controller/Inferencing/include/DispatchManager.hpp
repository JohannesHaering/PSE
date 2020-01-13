#ifndef DISPATCHER_MANAGER_H_
#define DISPATCHER_MANAGER_H_

#include"NeuralNetworkAdapter.hpp"
#include "Mode.hpp"
#include "ResultManager.hpp"
#include <list>

class DispatchManager {
    public: 
        DispatchManager getInstance();
        void setMode(Mode operatingMode);
        void setNeuralNetworkList(std::vector<NeuralNetworkAdapter>);
        ResultManager dispatchImages(std::vector<std::string> imageList);
};
#endif