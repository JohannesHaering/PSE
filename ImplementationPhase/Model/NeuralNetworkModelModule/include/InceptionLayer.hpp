#ifndef INCEPTIONLAYER_H_
#define INCEPTIONLAYER_H_

#include <list>
#include <string>
#include "NetworkLayer.hpp"
#include "NeuralNetwork.hpp"

class InceptionLayer  : public NetworkLayer {

  private:
    std::list<NeuralNetwork> chains;
    std::list<NeuralNetwork>::iterator it;

  public:
    InceptionLayer();
    InceptionLayer(name : string, inputDimensions : int[]);
    void addLayerChain(chain : NeuralNetwork);
    NeuralNetwork getFirstChain();
    NeuralNetwork getNextChain();
    void resetIterator();
    // ~InceptionLayer();
};
#endif
