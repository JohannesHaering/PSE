#include "classificationresultpanel.h"
#include "ui_classificationresultpanel.h"
#include <QPixmap>
#include <QString>
#include <QMessageBox>
#include "inferencepage.h"
ClassificationResultPanel::ClassificationResultPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClassificationResultPanel)
{
    ui->setupUi(this);
    renderer = new ClassificationResultRenderer();
}

ClassificationResultPanel::~ClassificationResultPanel()
{
    delete ui;
}
void ClassificationResultPanel::setCurrentImagePath(std::string path){
    this->currentImagePath = path;
}
void ClassificationResultPanel::setCurrentResultPath(std::string path){
    this->currentResultPath = path;
}
void ClassificationResultPanel::displayImage(){
    ui->imageLabel->setPixmap(imagePixmap->scaled(250,250));
}
void ClassificationResultPanel::displayResult(){
    ui->resultLabel->setPixmap(resultPixmap->scaled(250,250));
}
void ClassificationResultPanel::update(){
    displayImage();
    displayResult();
}
void ClassificationResultPanel::resultsChanged(std::string nnName, std::string imgName, cv::Mat mat, ClassificationResult result){
    ui->imgName->setText(QString::fromStdString(imgName));
    ui->nnName->setText(QString::fromStdString(nnName));
    imagePixmap = new QPixmap(convertCvtoQImg(mat));
    resultPixmap = new QPixmap(renderer->drawGraphic(result));
}
//buttons
void ClassificationResultPanel::nextNNEnable(bool flag){
    ui->nextNNButton->setEnabled(flag);
}
void ClassificationResultPanel::prevNNEnable(bool flag){
    ui->prevNNButton->setEnabled(flag);
}
void ClassificationResultPanel::nextImageEnable(bool flag){
    ui->nextImgButton->setEnabled(flag);
}
void ClassificationResultPanel::prevImageEnable(bool flag){
    ui->prevImgButton->setEnabled(flag);
}
void ClassificationResultPanel::saveResultEnable(bool flag){
    ui->saveResultButton->setEnabled(flag);
}
//clicked buttons
void ClassificationResultPanel::on_prevImgButton_clicked()
{
    //ControllerFacade::getInstance().prevImageClassification();
}

void ClassificationResultPanel::on_nextImgButton_clicked()
{
    //ControllerFacade::getInstance().nextImageClassification();
}

void ClassificationResultPanel::on_prevNNButton_clicked()
{
    //ControllerFacade::getInstance().prevNeuralNetworkClassification();
}

void ClassificationResultPanel::on_nextNNButton_clicked()
{
    //ControllerFacade::getInstance().nextNeuralNetworkClassification();
}

void ClassificationResultPanel::on_saveResultButton_clicked()
{
   //ControllerFacade::getInstance().saveResultsClassification();
}

