#include "inferencepageadapter.h"
#include "inferencepage.h"
InferencePageAdapter::InferencePageAdapter()
{
    inferPage = new InferencePage();
}
std::string InferencePageAdapter::getOperatingMode(){
    return inferPage->getOperatingMode();
}
std::vector<Device> InferencePageAdapter::getDevices(){
    return inferPage->getDevices();
}
std::string InferencePageAdapter::getInputMode(){
    return inferPage->getInputMode();
}
std::string InferencePageAdapter::getNeuralNetworkPath(){
    return inferPage->getNeuralNetworkPath();
}
bool InferencePageAdapter::getShowResults(){
    return inferPage->getShowResults();
}
bool InferencePageAdapter::getSaveResults(){
    return inferPage->getSaveResults();
}
bool InferencePageAdapter::getAppendResult(){
    return inferPage->getAppendResult();
}
void InferencePageAdapter::nextNNEnable(bool flag){
     inferPage->nextNNEnable(flag);
}
void InferencePageAdapter::prevNNEnable(bool flag){
     inferPage->prevNNEnable(flag);
}
void InferencePageAdapter::nextImageEnable(bool flag){
     inferPage->nextImageEnable(flag);
}
void InferencePageAdapter::prevImageEnable(bool flag){
     inferPage->prevImageEnable(flag);
}
void InferencePageAdapter::saveResultEnable(bool flag){
     inferPage->saveResultEnable(flag);
}
InferencePage* InferencePageAdapter::getInferencePage(){
    return inferPage;
}
void InferencePageAdapter::setDevices(std::vector<Device>* devices){
    inferPage->setDevices(devices);
}
void InferencePageAdapter::update(){
    inferPage->update();
}
void InferencePageAdapter::resultsChanged(std::string nnName, std::string imgName, std::string imgPath, ClassificationResult result){
    inferPage->resultsChanged(nnName,imgName,imgPath,result);
}
