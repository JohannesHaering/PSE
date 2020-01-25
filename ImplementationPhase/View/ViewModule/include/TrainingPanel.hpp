#ifndef TRAINING_H
#define TRAINING_H
#include "ContentView.hpp"
#include "TrainingRenderer.hpp"
#include <QDialog>

namespace Ui {
class TrainingPanel;
}

class TrainingPanel : public QDialog, public ContentView
{
    Q_OBJECT

public:
    void newTrainingFinished(std::vector<float> pointsArrayTest, std::vector<float> pointsArrayTraining);
    float getLearningRate();
    float getPrecision();
    std::string getName();
    std::string getLearningMode();
    std::string getNeuralNetworkPaths();
    std::string getTypeOfLearning();
    ~TrainingPanel();
    explicit TrainingPanel(QWidget *parent = nullptr);
private slots:
    void on_chooseNeuralNetwork_clicked();
    void on_chooseDataset_clicked();
    void on_train_clicked();
private:
    QPixmap* graphicPixmap;
    Ui::TrainingPanel *ui;
    ContentView *contView;
    void displayGraphic(std::string imgPath);
    std::string neuralNetworkPaths;
    TrainingRenderer* renderer;
};
#endif // TRAINING_H
