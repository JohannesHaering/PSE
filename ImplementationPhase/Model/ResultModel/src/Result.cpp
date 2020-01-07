#include <string>
#include "Result.h"
#include <iostream>
using namespace std;

Result::Result(string imageID, string neuralNetworkID) : imageID(imageID), neuralNetworkID(neuralNetworkID) {}

string Result::GetImageID()
{
	return imageID;
}

string Result::GetNeuralNetworkID()
{
	return neuralNetworkID;
}
