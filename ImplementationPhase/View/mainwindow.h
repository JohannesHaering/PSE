#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "topology.h"
#include "inferencepage.h"
#include "objectdetectioninferencepage.h"
#include "training.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Training* getTraining();
    Topology* getTopology();
    InferencePage* getImageClassification();
    ObjectDetectionInferencePage* getObjectDetection();
private slots:
    void on_imageClassification_clicked();

    void on_topology_clicked();

    void on_training_clicked();

    void on_objectDetection_clicked();

private:
    Training* training;
    Topology* topology;
    InferencePage* imageClassification;
    ObjectDetectionInferencePage* objectDetection;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
