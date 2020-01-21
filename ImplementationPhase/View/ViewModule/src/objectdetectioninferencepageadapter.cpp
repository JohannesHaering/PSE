#include "objectdetectioninferencepageadapter.h"

ObjectDetectionInferencePageAdapter::ObjectDetectionInferencePageAdapter()
{
    inferPage = new ObjectDetectionInferencePage();
}
std::string ObjectDetectionInferencePageAdapter::getOperatingMode(){
    return inferPage->getOperatingMode();
}
std::vector<Device> ObjectDetectionInferencePageAdapter::getDevices(){
    return inferPage->getDevices();
}
void ObjectDetectionInferencePageAdapter::setDevices(std::vector<Device> *devices){
    inferPage->setDevices(devices);
}
std::string ObjectDetectionInferencePageAdapter::getInputMode(){
    return inferPage->getInputMode();
}
std::string ObjectDetectionInferencePageAdapter::getNeuralNetworkPath(){
    return inferPage->getNeuralNetworkPath();
}
bool ObjectDetectionInferencePageAdapter::getShowResults(){
    return inferPage->getShowResults();
}
bool ObjectDetectionInferencePageAdapter::getSaveResults(){
    return inferPage->getSaveResults();
}
void ObjectDetectionInferencePageAdapter::update(){
     inferPage->update();
}
//buttons
void ObjectDetectionInferencePageAdapter::nextNNEnable(bool flag){
     inferPage->nextNNEnable(flag);
}
void ObjectDetectionInferencePageAdapter::prevNNEnable(bool flag){
     inferPage->prevNNEnable(flag);
}
void ObjectDetectionInferencePageAdapter::nextImageEnable(bool flag){
     inferPage->nextImageEnable(flag);
}
void ObjectDetectionInferencePageAdapter::prevImageEnable(bool flag){
     inferPage->prevImageEnable(flag);
}
void ObjectDetectionInferencePageAdapter::saveResultEnable(bool flag){
     inferPage->saveResultEnable(flag);
}
ObjectDetectionInferencePage* ObjectDetectionInferencePageAdapter::getInferPage(){
    return inferPage;
}
