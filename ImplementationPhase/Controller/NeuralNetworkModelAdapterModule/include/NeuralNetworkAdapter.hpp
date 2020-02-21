#ifndef NEURAL_NETWORK_ADAPTER_H_
#define NEURAL_NETWORK_ADAPTER_H_

#include <string>
#include "NetworkLayer.hpp"
#include "NeuralNetwork.hpp"

class NeuralNetworkAdapter {

    public:
    NeuralNetworkAdapter();
      NeuralNetworkAdapter(NeuralNetwork neuralNetwork);
        NeuralNetwork getNeuralNetwork();
        void addLayer(NetworkLayer* layer);
        void setName(std::string name);
        void setLabels(std::list<std::string> labels);
        std::string getName();
        int getWidth();
        int getHeight();
        int getChannels();
        std::list<std::string> getLabels();
        std::list<NetworkLayer*>::iterator begin();
        std::list<NetworkLayer*>::iterator end();
        std::list<NetworkLayer*>::reverse_iterator rbegin();
        std::list<NetworkLayer*>::reverse_iterator rend();
        int getLayerCount();
        void setMode(DeviceType type);

    protected: 
        NeuralNetwork neuralNetwork;    
        
};
#endif
