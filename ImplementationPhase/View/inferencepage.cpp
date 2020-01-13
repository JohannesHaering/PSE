#include "inferencepage.h"
#include "ui_inferencepage.h"
#include "imageclassificationcontrolpanel.h"
#include "QMessageBox"
InferencePage::InferencePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InferencePage)
{
    ui->setupUi(this);
}

InferencePage::~InferencePage()
{
    delete ui;
}
std::string InferencePage::getNeuralNetworkPath(){
    return ui->controlPanel->getNeuralNetworkPath();
}
bool InferencePage::getSaveResults(){
    return ui->controlPanel->getSaveResultsCheckBox();
}
bool InferencePage::getShowResults(){
    return  ui->controlPanel->getShowResultsCheckBox();
}
std::string InferencePage::getImageAmount(){
    return ui->controlPanel->getInputMode();
}
std::string InferencePage::getInputMode(){
    return ui->controlPanel->getInputMode();
}

void InferencePage::on_pushButton_2_clicked()
{
    ui->resultPanel->resultsChanged("pesho","ivan", ui->controlPanel->getImagePaths(),ui->controlPanel->getImagePaths());
    ui->resultPanel->update();
}
