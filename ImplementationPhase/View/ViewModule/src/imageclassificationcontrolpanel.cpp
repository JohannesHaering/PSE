#include "imageclassificationcontrolpanel.h"
#include "ui_imageclassificationcontrolpanel.h"
#include <string>
#include <QMessageBox>
#include "inferencepage.h"
using namespace std;
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
    //ControllerFacade::getInstance().getImageInputClassification();
}
void ImageClassificationControlPanel::on_startImgClass_clicked()
{
  //  ControllerFacade::getInstance().startProcessClassification();
}
void ImageClassificationControlPanel::on_chooseNeuralNetwork_clicked(){
    // ControllerFacade::getInstance().getNeuralNetworkInputClassifcation()
}
