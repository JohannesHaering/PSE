#include "training.h"
#include "ui_training.h"
#include <vector>
using namespace std;
Training::Training(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Training)
{
    ui->setupUi(this);
    renderer = new TrainingRenderer();
}

Training::~Training()
{
    delete ui;
}

void Training::on_chooseNeuralNetwork_clicked(){
    vector<string> types = {"png"};
    neuralNetworkPaths = contView->getFileFromExplorer(types);
}
void Training::newTrainingFinished(std::vector<float> pointsArrayTest, std::vector<float> pointsArrayTraining){
     graphicPixmap = new QPixmap(renderer->drawGraphic(pointsArrayTest,pointsArrayTraining));
     ui->trainingGraphic->setPixmap(*graphicPixmap);
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
    std::vector<float> points = {0.5,0.8,0.4};
    std::vector<float> points2 = {0.2,0.3,0.8,0.9};
    newTrainingFinished(points,points2);
}

