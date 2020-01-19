#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "classificationresultpanel.h"
#include "topology.h"
#include "inferencepage.h"
#include "training.h"
#include "viewfacade.h"
#include "objectdetectioninferencepage.h"
#include "render.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    training = new Training();
    topology = new Topology();
    imageClassification = new InferencePageAdapter();
    objectDetection = new ObjectDetectionInferencePageAdapter();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_imageClassification_clicked()
{
   imageClassification->getInferencePage()->setModal(true);
   imageClassification->getInferencePage()->exec();
}
Training* MainWindow::getTraining(){
    return training;
}
Topology* MainWindow::getTopology(){
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
}

void MainWindow::on_objectDetection_clicked()
{
    objectDetection->getInferPage()->setModal(true);
    objectDetection->getInferPage()->exec();
}

void MainWindow::on_pushButton_clicked()
{
    Render* render = new Render();
    render->setModal(true);
    render->exec();
}
