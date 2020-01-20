#include "imageclassificationcontrolpanel.h"
#include "ui_imageclassificationcontrolpanel.h"
#include <string>
#include <QMessageBox>
#include "inferencepage.h"
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
std::string ImageClassificationControlPanel::getOperatingMode(){
return ui->mode->currentText().toUtf8().constData();
}
std::string ImageClassificationControlPanel::getInputMode(){
    return ui->imgAmount->currentText().toUtf8().constData();
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
//clicked buttons
void ImageClassificationControlPanel::on_addImage_clicked()
{
    std::vector<Device> *devices = new std::vector<Device>();
    Device *device1 = new Device("","cpu1",22,33);
    Device *device2 = new Device("","cpu2",22,33);
    Device *device3 = new Device("","cpu3",22,33);
    devices->push_back(*device1);
    devices->push_back(*device2);
    devices->push_back(*device3);
    setDevices(devices);
    //ControllerFacade::getInstance().getImageInputClassification();
}
void ImageClassificationControlPanel::on_startImgClass_clicked()
{
  //  ControllerFacade::getInstance().startProcessClassification();
}
void ImageClassificationControlPanel::on_chooseNeuralNetwork_clicked(){
    // ControllerFacade::getInstance().getNeuralNetworkInputClassifcation()
}
