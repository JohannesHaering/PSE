#include "training.h"
#include "ui_training.h"
#include <vector>
using namespace std;
Training::Training(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Training)
{
    ui->setupUi(this);
}

Training::~Training()
{
    delete ui;
}

void Training::on_chooseNeuralNetwork_clicked(){
    vector<string> types = {"png"};
    neuralNetworkPaths = contView->getFilesFromExplorer(types);
}

std::string Training::getNeuralNetworkPaths(){
    return neuralNetworkPaths;
}

float Training::getPrecision(){
    return ui->precision->text().toFloat();
}

float Training::getLearningRate(){
    return ui->learningRate->text().toFloat();
}

std::string Training::getName(){
    return ui->name->text().toUtf8().constData();
}

std::string Training::getTypeOfLearning(){
    return ui->comboBox->currentText().toUtf8().constData();
}
void Training::on_chooseDataset_clicked()
{
    vector<string> types = {"png"};
    neuralNetworkPaths = contView->getFilesFromExplorer(types);
}

