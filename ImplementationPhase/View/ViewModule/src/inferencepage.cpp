#include "inferencepage.h"
#include "ui_inferencepage.h"
#include "imageclassificationcontrolpanel.h"
#include "QMessageBox"
InferencePage::InferencePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InferencePage)
{
    ui->setupUi(this);
}

InferencePage::~InferencePage()
{
    delete ui;
}
std::string InferencePage::getNeuralNetworkPath(){
    return ui->controlPanel->getNeuralNetworkPath();
}
bool InferencePage::getSaveResults(){
    return ui->controlPanel->getSaveResultsCheckBox();
}
bool InferencePage::getAppendResult(){
    return ui->controlPanel->getAppendResult();
}
bool InferencePage::getShowResults(){
    return  ui->controlPanel->getShowResultsCheckBox();
}
std::string InferencePage::getImageAmount(){
    return ui->controlPanel->getInputMode();
}
std::string InferencePage::getInputMode(){
    return ui->controlPanel->getInputMode();
}
std::vector<Device> InferencePage::getDevices(){
    return  ui->controlPanel->getDevices();
}
void InferencePage::setDevices(std::vector<Device>* devices){
    ui->controlPanel->setDevices(devices);
}
void InferencePage::update(){
    ui->resultPanel->update();
}
void InferencePage::resultsChanged(std::string nnName, std::string imgName, std::string imgPath, ClassificationResult result){
    ui->resultPanel->resultsChanged(nnName,imgName,imgPath,result);
}
void InferencePage::nextNNEnable(bool flag){
    ui->resultPanel->nextNNEnable(flag);
}
void InferencePage::prevNNEnable(bool flag){
    ui->resultPanel->prevNNEnable(flag);
}
void InferencePage::nextImageEnable(bool flag){
    ui->resultPanel->nextImageEnable(flag);
}
void InferencePage::prevImageEnable(bool flag){
    ui->resultPanel->prevImageEnable(flag);
}
void InferencePage::saveResultEnable(bool flag){
    ui->resultPanel->saveResultEnable(flag);
}
std::string InferencePage::getOperatingMode(){
    ui->controlPanel->getOperatingMode();
}
