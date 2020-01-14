#ifndef NEURALNETWORK_H_
#define NEURALNETWORK_H_

#include <list>
#include <string>
#include "NetworkLayer.hpp"

class NeuralNetwork {

  private:
    std::string name;
    std::list<NetworkLayer> layers;
    // NetworkLayer *firstLayer;
    // NetworkLayer *currentLayer;
    // NetworkLayer *lastLayer;
    std::list<NetworkLayer>::iterator it;

  public:
    NeuralNetwork();
    NeuralNetwork(std::string name);
    void addLayer(NetworkLayer& layer);
    void setName(std::string name);
    std::string getName();
    NetworkLayer* getFirstLayer();
    NetworkLayer* getLastLayer();
    NetworkLayer* getNextLayer();
    NetworkLayer* getPreviousLayer();
    ~NeuralNetwork();
};
#endif
