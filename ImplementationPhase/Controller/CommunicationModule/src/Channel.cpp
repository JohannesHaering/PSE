#ifndef CHANNEL_H_
#define CHANNEL_H_
#include <list>

// Abstract class. Should be extended by device-type specific classes.
Channel::Channel(Device connectedDevice) : deviceHandler(connectedDevice) {}
Channel::Channel(Device connectedDevice, std::list<NeuralNetwork> neuralNetworkList) : deviceHandler(connectedDevice), neuralNetworkList(neuralNetworkList) {}

