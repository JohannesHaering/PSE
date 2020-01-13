#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "classificationresultpanel.h"
#include "topology.h"
#include "inferencepage.h"
#include "training.h"
#include "viewfacade.h"
#include "objectdetectioninferencepage.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    training = new Training();
    topology = new Topology();
    imageClassification = new InferencePage();
    objectDetection = new ObjectDetectionInferencePage();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_imageClassification_clicked()
{
   imageClassification->setModal(true);
   imageClassification->exec();
}
Training* MainWindow::getTraining(){
    return training;
}
Topology* MainWindow::getTopology(){
    return topology;
}
InferencePage* MainWindow::getImageClassification(){
    return imageClassification;
}
ObjectDetectionInferencePage* MainWindow::getObjectDetection(){
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
    objectDetection->setModal(true);
    objectDetection->exec();
}
