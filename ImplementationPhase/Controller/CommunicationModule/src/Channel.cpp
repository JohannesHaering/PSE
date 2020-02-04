#include "Channel.hpp"
#include <list>

// Abstract class. Should be extended by device-type specific classes.
Channel::Channel(Device connectedDevice) : deviceHandler(connectedDevice) {}
Channel::Channel(Device connectedDevice, std::list<NeuralNetworkAdapter> neuralNetworkList) : deviceHandler(connectedDevice), neuralNetworkList(neuralNetworkList) {}

