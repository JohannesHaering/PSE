#include "ImageClassificationControlPanel.hpp"
#include "ui_ImageClassificationControlPanel.h"
#include <string>
#include <QMessageBox>
#include "InferencePage.hpp"
ImageClassificationControlPanel::ImageClassificationControlPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageClassificationControlPanel)
{
    ui->setupUi(this);
}

ImageClassificationControlPanel::~ImageClassificationControlPanel()
{
    delete ui;
}
bool ImageClassificationControlPanel::getCheckBoxAppendResults(){
    return ui->appendResults->isChecked();
}
bool ImageClassificationControlPanel::getSaveResultsCheckBox(){
    return ui->saveResults->isChecked();
}
bool ImageClassificationControlPanel::getShowResultsCheckBox(){
   return ui->showResults->isChecked();
}
int ImageClassificationControlPanel::getOperatingMode(){
return ui->mode->currentIndex();
}
int ImageClassificationControlPanel::getInputMode(){
    return ui->imgAmount->currentIndex();
}
bool ImageClassificationControlPanel::getAppendResult(){
    return ui->appendResults->isChecked();
}
std::string ImageClassificationControlPanel::getNeuralNetworkPath(){
    return neuralNetworkPaths;
}
std::string ImageClassificationControlPanel::getImagePaths(){
    return imagePaths;
}
std::vector<Device> ImageClassificationControlPanel::getDevices(){
    return ui->CheckBoxWidget->getDevices();
}
void ImageClassificationControlPanel::setDevices(std::vector<Device>* devices){
    ui->CheckBoxWidget->setDevices(devices);
}
void ImageClassificationControlPanel::startEnable(bool flag){
    ui->startImgClass->setEnabled(flag);
}

void ImageClassificationControlPanel::setPowerPrediction(float amount){
    powerPrediction = amount;
}
void ImageClassificationControlPanel::setPerformancePrediction(float amount){
    performancePrediction = amount;
}
void ImageClassificationControlPanel::updateValues(){
ui->performancePrediction->setText(QString::number(performancePrediction));
ui->powerPrediction->setText(QString::number(powerPrediction));
}
//clicked buttons
void ImageClassificationControlPanel::on_addImage_clicked()
{
    //ControllerFacade::getInstance().getImageInputClassification();
}
void ImageClassificationControlPanel::on_startImgClass_clicked()
{
  //  ControllerFacade::getInstance().startProcessClassification();
}
void ImageClassificationControlPanel::on_chooseNeuralNetwork_clicked(){
    // ControllerFacade::getInstance().getNeuralNetworkInputClassifcation()
}
