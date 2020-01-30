#ifndef POLLINGLAYER_H_
#define POLLINGLAYER_H_

#include <string>
#include "NetworkLayer.hpp"
#include "PollingType.hpp"

class PollingLayer  : public NetworkLayer {

  private:
    PollingType type;
    int size;
    int stride;

  public:
    PollingLayer();
    PollingLayer(std::string name, int* inputDimensions, int size, int stride, PollingType type);
    void setType(PollingType type);
    void setSize(int size);
    void setStride(int stride);
    PollingType getType();
    int getSize();
    int getStride();
    virtual int* getTensorDimensions();
    // ~PolingLayer();
};
#endif
#ifndef POLLINGTYPE_H_
#define POLLINGTYPE_H_

enum PollingType {
  MAX,
  AVEREAGE
};
#endif
