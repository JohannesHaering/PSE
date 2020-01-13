#ifndef DETECTIONCONTROLPANEL_H
#define DETECTIONCONTROLPANEL_H

#include <QWidget>
#include "classificationresultpanel.h"
#include "contentview.h"
namespace Ui {
class DetectionControlPanel;
}

class DetectionControlPanel : public QWidget, public ContentView
{
    Q_OBJECT

public:
    explicit DetectionControlPanel(QWidget *parent = nullptr);
    ~DetectionControlPanel();
    std::string getCheckBoxesDevice();
    bool getCheckBoxAppendResults();
    bool getShowResultsCheckBox();
    bool getSaveResultsCheckBox();
    std::string getNeuralNetworkPath();
    std::string getOperatingMode();
    std::string neuralNetworkPaths;
    std::string imagePaths;
    std::string getInputMode();
    std::string getImagePaths();
    static DetectionControlPanel* getInstance();
private slots:
    void on_addImage_clicked();

    void on_chooseNeuralNetwork_clicked();

private:
    Ui::DetectionControlPanel *ui;
    ContentView *contView;
};

#endif // DETECTIONCONTROLPANEL_H
