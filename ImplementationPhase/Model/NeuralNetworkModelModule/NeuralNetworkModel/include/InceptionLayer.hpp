#ifndef INCEPTIONLAYER_H_
#define INCEPTIONLAYER_H_

#include <list>
#include <string>
#include "NetworkLayer.hpp"
// #include "NeuralNetwork.hpp"

class NeuralNetwork;

class InceptionLayer  : public NetworkLayer {

  private:
    std::list<NeuralNetwork> chains;
    std::list<NeuralNetwork>::iterator it;

  public:
    InceptionLayer();
    InceptionLayer(std::string name, int* inputDimensions);
    InceptionLayer(std::string name, int* inputDimensions, NeuralNetwork chain);
    void addLayerChain(NeuralNetwork chain);
    NeuralNetwork getFirstChain();
    NeuralNetwork getNextChain();
    // ~InceptionLayer();
};
#endif
