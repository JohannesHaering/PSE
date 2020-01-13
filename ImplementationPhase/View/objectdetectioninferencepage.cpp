#include "objectdetectioninferencepage.h"
#include "ui_objectdetectioninferencepage.h"

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
void ObjectDetectionInferencePage::on_start_clicked()
{
    ui->resultPanel->resultsChanged("pesho","ivan", ui->controlPanel->getImagePaths(),ui->controlPanel->getImagePaths());
    ui->resultPanel->update();
}
