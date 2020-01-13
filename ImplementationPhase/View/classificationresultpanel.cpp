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
void ClassificationResultPanel::displayImage(std::string path){
    QString pathImg = QString::fromStdString(path);
    QPixmap pix(pathImg);
    ui->imageLabel->setPixmap(pix.scaled(250,250));
}
void ClassificationResultPanel::displayResult(std::string path){
    QString pathImg = QString::fromStdString(path);
    QPixmap pix(pathImg);
    ui->resultLabel->setPixmap(pix.scaled(250,250));

}
void ClassificationResultPanel::update(){
    displayImage(currentImagePath);
    displayResult(currentResultPath);
}
void ClassificationResultPanel::resultsChanged(std::string nnName, std::string imgName, std::string imgPath, std::string resultPath){
    ui->imgName->setText(QString::fromStdString(imgName));
    ui->nnName->setText(QString::fromStdString(nnName));
    this->setCurrentImagePath(imgPath);
    this->setCurrentResultPath(resultPath);
}
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

