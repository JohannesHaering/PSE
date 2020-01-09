#include <string>
#include <iostream>
#include "Result.hpp"

Result::Result(std::string imageID, std::string neuralNetworkID) : imageID(imageID), neuralNetworkID(neuralNetworkID) {}

std::string Result::getImageID() { return imageID; }

std::string Result::getNeuralNetworkID() { return neuralNetworkID; }
