#include <string>
#include <stdexcept>
#include "classprobability.h"

ClassProbability::ClassProbability(std::string name, float probability) : className(name), probability(probability)
{
    if (probability < 0 || probability > 1)
        throw std::invalid_argument("probability should be between 0.0 and 1.0, was " + std::to_string(probability) + "\n");
}

std::string ClassProbability::getClassName() { return className; }

float ClassProbability::getProbability() { return probability; }
