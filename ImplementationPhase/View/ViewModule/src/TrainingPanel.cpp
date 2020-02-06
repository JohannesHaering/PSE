#include "TrainingPanel.hpp"
#include "ui_TrainingPanel.h"
#include "ControllerFacade.hpp"
#include <vector>
using namespace std;
TrainingPanel::TrainingPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrainingPanel)
{
    ui->setupUi(this);
    renderer = new TrainingRenderer();
}

TrainingPanel::~TrainingPanel()
{
    delete ui;
}
void TrainingPanel::newTrainingFinished(std::vector<float> pointsArrayTest, std::vector<float> pointsArrayTraining){
     graphicPixmap = new QPixmap(renderer->drawGraphic(pointsArrayTest,pointsArrayTraining));
     ui->trainingGraphic->setPixmap(graphicPixmap->scaled(400, 250));
}
std::string TrainingPanel::getNeuralNetworkPaths(){
    return neuralNetworkPaths;
}

float TrainingPanel::getPrecision(){
    return ui->precision->text().toFloat();
}

float TrainingPanel::getLearningRate(){
    return ui->learningRate->text().toFloat();
}

std::string TrainingPanel::getName(){
    return ui->name->text().toUtf8().constData();
}

std::string TrainingPanel::getTypeOfLearning(){
    return ui->comboBox->currentText().toUtf8().constData();
}

void TrainingPanel::enableStart(bool flag) {
  ui->train->setEnabled(flag);
}


void TrainingPanel::on_chooseDataset_clicked()
{
    ControllerFacade::getInstance()->getImageInputTraining();
}
void TrainingPanel::on_chooseNeuralNetwork_clicked(){
    ControllerFacade::getInstance()->getNeuralNetworkInputTraining();
}
void TrainingPanel::on_train_clicked()
{
    ControllerFacade::getInstance()->startProcessTraining();
}
