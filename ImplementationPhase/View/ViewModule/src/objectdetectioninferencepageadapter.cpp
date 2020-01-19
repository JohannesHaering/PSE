#include "objectdetectioninferencepageadapter.h"

ObjectDetectionInferencePageAdapter::ObjectDetectionInferencePageAdapter()
{
    inferPage = new ObjectDetectionInferencePage();
}
std::string ObjectDetectionInferencePageAdapter::getOperatingMode(){
    return inferPage->getOperatingMode();
}
std::string ObjectDetectionInferencePageAdapter::getDevices(){
    return inferPage->getDevices();
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
void ObjectDetectionInferencePageAdapter::nextNNEnable(bool flag){
    return inferPage->nextNNEnable(flag);
}
void ObjectDetectionInferencePageAdapter::prevNNEnable(bool flag){
    return inferPage->prevNNEnable(flag);
}
void ObjectDetectionInferencePageAdapter::nextImageEnable(bool flag){
    return inferPage->nextImageEnable(flag);
}
void ObjectDetectionInferencePageAdapter::prevImageEnable(bool flag){
    return inferPage->prevImageEnable(flag);
}
void ObjectDetectionInferencePageAdapter::saveResultEnable(bool flag){
    return inferPage->saveResultEnable(flag);
}
ObjectDetectionInferencePage* ObjectDetectionInferencePageAdapter::getInferPage(){
    return inferPage;
}
