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
    if(ui->appendResults->isChecked()){ return true;}
     return false;
}
bool DetectionControlPanel::getSaveResultsCheckBox(){
    if(ui->saveResults->isChecked()){ return true;
    } return false;
}
bool DetectionControlPanel::getShowResultsCheckBox(){
    if(ui->showResults->isChecked()){ return true;
    } return false;
}
std::string DetectionControlPanel::getOperatingMode(){
return ui->mode->currentText().toUtf8().constData();
}
std::string DetectionControlPanel::getInputMode(){
    return ui->imgAmount->currentText().toUtf8().constData();
}

std::string DetectionControlPanel::getNeuralNetworkPath(){
    return neuralNetworkPaths;
}

std::string DetectionControlPanel::getImagePaths(){
    return imagePaths;
}
void DetectionControlPanel::on_addImage_clicked()
{
    vector<string> types = {"PNG"};
    imagePaths = contView->getFilesFromExplorer(types);
}

void DetectionControlPanel::on_chooseNeuralNetwork_clicked()
{
    vector<string> types = {"PNG"};
    neuralNetworkPaths = contView->getFilesFromExplorer(types);
}
