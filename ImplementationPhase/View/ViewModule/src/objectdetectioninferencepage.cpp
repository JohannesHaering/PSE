#include "objectdetectioninferencepage.h"
#include "ui_objectdetectioninferencepage.h"
#include "inferencepage.h"
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
std::string ObjectDetectionInferencePage::getOperatingMode(){
    return ui->controlPanel->getOperatingMode();
}
void ObjectDetectionInferencePage::update(){
    ui->resultPanel->update();
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
std::string ObjectDetectionInferencePage::getImageAmount(){
    return ui->controlPanel->getInputMode();
}
std::string ObjectDetectionInferencePage::getInputMode(){
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
void ObjectDetectionInferencePage::nextImageEnable(bool flag){
     ui->resultPanel->nextImageEnable(flag);
}
void ObjectDetectionInferencePage::prevImageEnable(bool flag){
     ui->resultPanel->prevImageEnable(flag);
}
void ObjectDetectionInferencePage::saveResultEnable(bool flag){
     ui->resultPanel->saveResultEnable(flag);
}
