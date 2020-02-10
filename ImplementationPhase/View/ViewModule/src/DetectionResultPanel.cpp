#include "DetectionResultPanel.hpp"
#include "ui_DetectionResultPanel.h"

DetectionResultPanel::DetectionResultPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetectionResultPanel)
{
    ui->setupUi(this);
}

DetectionResultPanel::~DetectionResultPanel()
{
    delete ui;
}
void DetectionResultPanel::displayImage(){
    ui->imageLabel->setPixmap(imagePixmap->scaled(250,250));
}
void DetectionResultPanel::displayResult(){
    ui->resultLabel->setPixmap(resultPixmap->scaled(250,250));
}
void DetectionResultPanel::update(){
    displayImage();
    displayResult();
    ui->imgName->setText(QString::fromStdString(currentImageName));
    ui->nnName->setText(QString::fromStdString(currentNNName));
}
void DetectionResultPanel::resultsChanged(std::string nnName, std::string imgName, std::string imgPath, std::string result){
    currentNNName = nnName;
    currentImageName = imgName;

}
void DetectionResultPanel::nextNNEnable(bool flag){
    ui->nextNNButton->setEnabled(flag);
}
void DetectionResultPanel::prevNNEnable(bool flag){
    ui->prevNNButton->setEnabled(flag);
}
void DetectionResultPanel::nextImageEnable(bool flag){
    ui->nextImgButton->setEnabled(flag);
}
void DetectionResultPanel::prevImageEnable(bool flag){
    ui->prevImgButton->setEnabled(flag);
}
void DetectionResultPanel::saveResultEnable(bool flag){
    ui->saveResultsButton->setEnabled(flag);
}
//buttons
void DetectionResultPanel::on_prevImgButton_clicked()
{
 //   ControllerFacade::getInstance().prevImageDetection();
}

void DetectionResultPanel::on_nextImgButton_clicked()
{
  //  ControllerFacade::getInstance().nextImageDetection();
}

void DetectionResultPanel::on_prevNNButton_clicked()
{
   // ControllerFacade::getInstance().prevNeuralNetworkDetection();
}

void DetectionResultPanel::on_nextNNButton_clicked()
{
  //  ControllerFacade::getInstance().nextNeuralNetworkDetection();
}

void DetectionResultPanel::on_saveResultsButton_clicked()
{
    //ControllerFacade::getInstance().startProcessDetection();
}
