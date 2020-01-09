#include <string>
#include <iostream>
#include "Result.h"

Result::Result(std::string imageID, std::string neuralNetworkID) : imageID(imageID), neuralNetworkID(neuralNetworkID) {}

std::string Result::getImageID() { return imageID; }

std::string Result::getNeuralNetworkID() { return neuralNetworkID; }
