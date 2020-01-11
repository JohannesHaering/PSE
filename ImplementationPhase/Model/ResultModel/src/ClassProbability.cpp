#include <string>
#include <stdexcept>
#include "ClassProbability.hpp"

using namespace std;

ClassProbability::ClassProbability(string name, float probability) : className(name), probability(probability)
{
	if (probability < 0 || probability > 1)
		throw std::invalid_argument("probability should be between 0.0 and 1.0, was " + std::to_string(probability) + "\n");
	//this->className = name;
	//this->probability = probability;
}

string ClassProbability::getClassName() { return className; }

float ClassProbability::getProbability() { return probability; }
