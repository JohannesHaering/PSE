#include "InferencePage.hpp"
#include "ui_InferencePage.h"
#include "ImageClassificationControlPanel.hpp"
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
int InferencePage::getInputMode(){
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
    ui->controlPanel->updateValues();
}
void InferencePage::setPowerPrediction(float amount){
    ui->controlPanel->setPowerPrediction(amount);
}
void InferencePage::setPerformancePrediction(float amount){
    ui->controlPanel->setPerformancePrediction(amount);
}
void InferencePage::resultsChanged(std::string nnName, std::string imgName, cv::Mat mat, ClassificationResult result){
    ui->resultPanel->resultsChanged(nnName,imgName,mat,result);
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
void InferencePage::startEnable(bool flag){
    ui->controlPanel->startEnable(flag);
}
int InferencePage::getOperatingMode(){
    return ui->controlPanel->getOperatingMode();
}
