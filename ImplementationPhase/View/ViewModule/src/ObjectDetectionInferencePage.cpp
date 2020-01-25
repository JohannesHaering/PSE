#include "ObjectDetectionInferencePage.hpp"
#include "ui_ObjectDetectionInferencePage.h"
#include "InferencePage.hpp"
ObjectDetectionInferencePage::ObjectDetectionInferencePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ObjectDetectionInferencePage)
{
    ui->setupUi(this);
}

ObjectDetectionInferencePage::~ObjectDetectionInferencePage()
{
    delete ui;
}
std::string ObjectDetectionInferencePage::getNeuralNetworkPath(){
    return ui->controlPanel->getNeuralNetworkPath();
}
int ObjectDetectionInferencePage::getOperatingMode(){
    return ui->controlPanel->getOperatingMode();
}
void ObjectDetectionInferencePage::update(){
    ui->resultPanel->update();
    ui->controlPanel->updateValues();
}
//Check Boxes
bool ObjectDetectionInferencePage::getAppendResult(){
    return  ui->controlPanel->getCheckBoxAppendResults();
}
bool ObjectDetectionInferencePage::getSaveResults(){
    return ui->controlPanel->getSaveResultsCheckBox();
}
bool ObjectDetectionInferencePage::getShowResults(){
    return  ui->controlPanel->getShowResultsCheckBox();
}
int ObjectDetectionInferencePage::getInputMode(){
    return ui->controlPanel->getInputMode();
}
//devices
std::vector<Device> ObjectDetectionInferencePage::getDevices(){
    return ui->controlPanel->getDevices();
}
void ObjectDetectionInferencePage::setDevices(std::vector<Device>* devices){
    ui->controlPanel->setDevices(devices);
}
//buttons
void ObjectDetectionInferencePage::nextNNEnable(bool flag){
     ui->resultPanel->nextNNEnable(flag);
}
void ObjectDetectionInferencePage::prevNNEnable(bool flag){
     ui->resultPanel->prevNNEnable(flag);
}
void ObjectDetectionInferencePage::setPowerPrediction(float amount){
    ui->controlPanel->setPowerPrediction(amount);
}
void ObjectDetectionInferencePage::setPerformancePrediction(float amount){
    ui->controlPanel->setPerformancePrediction(amount);
}
void ObjectDetectionInferencePage::nextImageEnable(bool flag){
     ui->resultPanel->nextImageEnable(flag);
}
void ObjectDetectionInferencePage::prevImageEnable(bool flag){
     ui->resultPanel->prevImageEnable(flag);
}
void ObjectDetectionInferencePage::saveResultEnable(bool flag){
     ui->resultPanel->saveResultEnable(flag);
}
void ObjectDetectionInferencePage::startEnable(bool flag){
    ui->controlPanel->startEnable(flag);
}
