#include "detectionresultpanel.h"
#include "ui_detectionresultpanel.h"

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
void DetectionResultPanel::setCurrentImagePath(std::string path){
    this->currentImagePath = path;
}
void DetectionResultPanel::setCurrentResultPath(std::string path){
    this->currentResultPath = path;
}
void DetectionResultPanel::displayImage(std::string path){
    QString pathImg = QString::fromStdString(path);
    QPixmap pix(pathImg);
    ui->imageLabel->setPixmap(pix.scaled(250,250));
}
void DetectionResultPanel::displayResult(std::string path){
    QString pathImg = QString::fromStdString(path);
    QPixmap pix(pathImg);
    ui->resultLabel->setPixmap(pix.scaled(250,250));
}
void DetectionResultPanel::update(){
    displayImage(currentImagePath);
    displayResult(currentResultPath);
}
void DetectionResultPanel::resultsChanged(std::string nnName, std::string imgName, std::string imgPath, std::string resultPath){
    ui->imgName->setText(QString::fromStdString(imgName));
    ui->nnName->setText(QString::fromStdString(nnName));
    this->setCurrentImagePath(imgPath);
    this->setCurrentResultPath(resultPath);
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
