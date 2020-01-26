#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include "ClassificationResultPanel.hpp"
#include "TopologyPanel.hpp"
#include "InferencePage.hpp"
#include "TrainingPanel.hpp"
#include "ViewFacade.hpp"
#include "ObjectDetectionInferencePage.hpp"
#include "RenderPanel.hpp"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    training = new TrainingPanel();
    topology = new TopologyPanel();
    imageClassification = new InferencePageAdapter();
    objectDetection = new ObjectDetectionInferencePageAdapter();
}

MainWindow::~MainWindow()
{
    delete ui;
}
TrainingPanel* MainWindow::getTrainingPanel(){
    return training;
}
TopologyPanel* MainWindow::getTopologyPanel(){
    return topology;
}
InferencePageAdapter* MainWindow::getImageClassification(){
    return imageClassification;
}
ObjectDetectionInferencePageAdapter* MainWindow::getObjectDetection(){
    return objectDetection;
}
void MainWindow::on_topology_clicked()
{
    topology->setModal(true);
    topology->exec();
}

void MainWindow::on_training_clicked()
{
    training->setModal(true);
    training->exec();
    training->destroyed();
}

void MainWindow::on_objectDetection_clicked()
{
    objectDetection->getInferPage()->setModal(true);
    objectDetection->getInferPage()->exec();
}
void MainWindow::on_imageClassification_clicked()
{
   imageClassification->getInferencePage()->setModal(true);
   imageClassification->getInferencePage()->exec();
}
void MainWindow::on_pushButton_clicked()
{
    RenderPanel* render = new RenderPanel();
    render->setModal(true);
    render->exec();
}
