#include "Inferencer.hpp"
#include "Distributor.hpp"
#include <string>
#include <vector>

/*
* Saves the directories of the input images
*/
void Distributor::setInput(std::vector<std::string> input) {this->directories = input;}

/*
* Returns the amount of saved directories
*/
int Distributor::getAmountImages() {return directories.size();}