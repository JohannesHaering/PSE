#include "detectioncontrolpanel.h"
#include "ui_detectioncontrolpanel.h"
#include <vector>
using namespace std;
DetectionControlPanel::DetectionControlPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetectionControlPanel)
{
    ui->setupUi(this);
}

DetectionControlPanel::~DetectionControlPanel()
{
    delete ui;
}
bool DetectionControlPanel::getCheckBoxAppendResults(){
    return ui->appendResults->isChecked();
}
bool DetectionControlPanel::getSaveResultsCheckBox(){
    return ui->saveResults->isChecked();
}
bool DetectionControlPanel::getShowResultsCheckBox(){
    return ui->showResults->isChecked();
}
std::vector<Device> DetectionControlPanel::getDevices(){
    return ui->CheckBoxWidget->getDevices();
}
void DetectionControlPanel::setDevices(std::vector<Device>* devices){
    ui->CheckBoxWidget->setDevices(devices);
}
int DetectionControlPanel::getOperatingMode(){
    return ui->mode->currentIndex();
}
int DetectionControlPanel::getInputMode(){
    return ui->imgAmount->currentIndex();
}
std::string DetectionControlPanel::getNeuralNetworkPath(){
    return neuralNetworkPaths;
}
std::string DetectionControlPanel::getImagePaths(){
    return imagePaths;
}
//clicked buttons
void DetectionControlPanel::on_addImage_clicked()
{
    //ControllerFacade::getInstance().getImageInputDetection();
}

void DetectionControlPanel::on_chooseNeuralNetwork_clicked()
{
   //ControllerFacade::getInstance().getNeuralNetworkInputDetection();
}

void DetectionControlPanel::on_startObjectDet_clicked()
{
    //ControllerFacade::getInstance().startProcessDetection();
}
