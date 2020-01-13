#ifndef IMAGECLASSIFICATIONCONTROLPANEL_H
#define IMAGECLASSIFICATIONCONTROLPANEL_H

#include <QWidget>
#include <string>
#include "contentview.h"
namespace Ui {
class ImageClassificationControlPanel;
}

class ImageClassificationControlPanel : public QWidget, public ContentView
{
    Q_OBJECT

public:
    explicit ImageClassificationControlPanel(QWidget *parent = nullptr);
    ~ImageClassificationControlPanel();
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
    static ImageClassificationControlPanel* getInstance();
private slots:
    void on_chooseNeuralNetwork_clicked();
    void on_addImage_clicked();

    void on_pushButton_clicked();

private:
    ContentView *contView;
    Ui::ImageClassificationControlPanel *ui;
    static ImageClassificationControlPanel* instance;
    ImageClassificationControlPanel(int a);
};

#endif // IMAGECLASSIFICATIONCONTROLPANEL_H
