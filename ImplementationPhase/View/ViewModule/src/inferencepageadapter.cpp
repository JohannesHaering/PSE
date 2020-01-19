#include "inferencepageadapter.h"
#include <vector>
#include "Device.hpp"
//#include "inferencepage.h"
InferencePageAdapter::InferencePageAdapter()
{
    
}
std::string InferencePageAdapter::getOperatingMode(){
	return "";
}
std::vector<Device> InferencePageAdapter::getDevices(){
	return {};
}

void InferencePageAdapter::setDevices(std::vector<Device> devices) {

}

std::string InferencePageAdapter::getInputMode(){
	return "";
}
std::string InferencePageAdapter::getNeuralNetworkPath(){
	return "";
}
bool InferencePageAdapter::getShowResults(){
	return true;
}
bool InferencePageAdapter::getSaveResults(){
	return true;
}
void InferencePageAdapter::nextNNEnable(bool flag){

}
void InferencePageAdapter::prevNNEnable(bool flag){

}
void InferencePageAdapter::nextImageEnable(bool flag){

}
void InferencePageAdapter::prevImageEnable(bool flag){

}
void InferencePageAdapter::saveResultEnable(bool flag){

}
