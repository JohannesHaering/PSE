#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TopologyPanel.hpp"
#include "InferencePage.hpp"
#include "ObjectDetectionInferencePage.hpp"
#include "TrainingPanel.hpp"
#include "ObjectDetectionInferencePageAdapter.hpp"
#include "InferencePageAdapter.hpp"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    TrainingPanel* getTrainingPanel();
    TopologyPanel* getTopologyPanel();
    InferencePageAdapter* getImageClassification();
    ObjectDetectionInferencePageAdapter* getObjectDetection();
private slots:
    void on_imageClassification_clicked();

    void on_topology_clicked();

    void on_training_clicked();

    void on_objectDetection_clicked();

    void on_pushButton_clicked();

private:
    TrainingPanel* training;
    TopologyPanel* topology;
    InferencePageAdapter* imageClassification;

    ObjectDetectionInferencePageAdapter* objectDetection;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
