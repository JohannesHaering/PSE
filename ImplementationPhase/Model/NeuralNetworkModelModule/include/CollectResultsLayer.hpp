#ifndef COLLECTRESULTLAYER_H_
#define COLLECTRESULTLAYER_H_

#include <string>
#include "NetworkLayer.hpp"

class CollectResultsLayer  : public NetworkLayer {

  public:
    CollectResultsLayer();
    CollectResultsLayer(std::string name, int* inputDimensions);
    // ~CollectResultsLayer();
};
#endif
