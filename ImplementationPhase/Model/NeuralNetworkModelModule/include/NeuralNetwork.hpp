#ifndef NEURALNETWORK_H_
#define NEURALNETWORK_H_

#include <list>
#include <string>
// #include "NetworkLayer.hpp" // added as a dependency of the speciffic layers

#include "ConvolutionLayer.hpp"
#include "ActivationLayer.hpp"
#include "MaxPoolLayer.hpp"
#include "DenseLayer.hpp"
#include "FlattenLayer.hpp"
#include "ReLuLayer.hpp"
#include "LeakyReLuLayer.hpp"
#include "SoftmaxLayer.hpp"
#include "SigmoidLayer.hpp"
#include "DeviceType.hpp"

class NeuralNetwork {

  private:
    std::string name;
    int width;
    int height;
    int channels;
    std::list<NetworkLayer*> layers;
    std::list<std::string> labels;

  public:
    NeuralNetwork();
    NeuralNetwork(std::string name);
    NeuralNetwork(std::string name, int width, int height, int channels);
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
    ~NeuralNetwork();
};
#endif

