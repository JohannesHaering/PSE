#ifndef NEURALNETWORK_H_
#define NEURALNETWORK_H_

#include <list>
#include <string>
#include "NetworkLayer.hpp"

class NeuralNetwork {

  private:
    std::string name;
    int width;
    int heigth;
    int channelNumb;
    std::list<NetworkLayer*> layers;
    // NetworkLayer *firstLayer;
    // NetworkLayer *currentLayer;
    // NetworkLayer *lastLayer;
    std::list<NetworkLayer*>::iterator it;

  public:
    NeuralNetwork();
    NeuralNetwork(std::string name);
    NeuralNetwork(std::string name, int width, int heigth, int channelNumb);
    void addLayer(NetworkLayer* layer);
    void setName(std::string name);
    void setInputDimensions(int width, int heigth, int channelNumb);
    std::string getName();
    int getWidth();
    int getHeigth();
    int getChannelNumb();
    NetworkLayer* getFirstLayer();
    NetworkLayer* getLastLayer();
    NetworkLayer* getNextLayer();
    NetworkLayer* getPreviousLayer();
    ~NeuralNetwork();
};
#endif
