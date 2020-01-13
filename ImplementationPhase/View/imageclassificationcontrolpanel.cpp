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
    if(ui->appendResults->isChecked()){ return true;}
     return false;
}
bool ImageClassificationControlPanel::getSaveResultsCheckBox(){
    if(ui->saveResults->isChecked()){ return true;
    } return false;
}
bool ImageClassificationControlPanel::getShowResultsCheckBox(){
    if(ui->showResults->isChecked()){ return true;
    } return false;
}
std::string ImageClassificationControlPanel::getOperatingMode(){
return ui->mode->currentText().toUtf8().constData();
}
std::string ImageClassificationControlPanel::getInputMode(){
    return ui->imgAmount->currentText().toUtf8().constData();
}

void ImageClassificationControlPanel::on_chooseNeuralNetwork_clicked(){
    vector<string> types = {"PNG"};
    neuralNetworkPaths = contView->getFilesFromExplorer(types);
}

std::string ImageClassificationControlPanel::getNeuralNetworkPath(){
    return neuralNetworkPaths;
}

std::string ImageClassificationControlPanel::getImagePaths(){
    return imagePaths;
}
void ImageClassificationControlPanel::on_addImage_clicked()
{
   vector<string> types = {"PNG"};
   imagePaths = contView->getFilesFromExplorer(types);
}
