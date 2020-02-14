#ifndef NEURALNETWORK_H_
#define NEURALNETWORK_H_

#include <list>
#include <string>
// #include "NetworkLayer.hpp" // added as a dependency of the speciffic layers

#include "ConvolutionLayer.hpp"
#include "ActivationLayer.hpp"
#include "PollingLayer.hpp"
#include "LocalResponseNormalizationLayer.hpp"
#include "DenseLayer.hpp"
#include "FlattenLayer.hpp"
#include "DropoutLayer.hpp"
#include "CollectResultsLayer.hpp"
#include "OutputStorageLayer.hpp"
#include "InceptionLayer.hpp"

class NeuralNetwork {

  private:
    std::string name;
    int width;
    int height;
    int channels;
    std::list<NetworkLayer*> layers;
    // NetworkLayer *firstLayer;
    // NetworkLayer *currentLayer;
    // NetworkLayer *lastLayer;
    std::list<NetworkLayer*>::iterator it;
    std::list<std::string> labels;

  public:
    NeuralNetwork();
    NeuralNetwork(std::string name);
    NeuralNetwork(std::string name, int width, int height, int channels);
    void addLayer(NetworkLayer* layer);
    void setName(std::string name);
    void setInputDimensions(int width, int height, int channels);
    void setLabels(std::list<std::string> labels);
    std::string getName();
    int getWidth();
    int getHeight();
    int getChannels();
    std::list<std::string> getLabels();
    std::list<NetworkLayer*>::iterator begin();
    std::list<NetworkLayer*>::iterator end();
    NetworkLayer* getFirstLayer();
    NetworkLayer* getLastLayer();
    NetworkLayer* getNextLayer();
    NetworkLayer* getPreviousLayer();
    int getLayerCount();
    ~NeuralNetwork();
};
#endif
