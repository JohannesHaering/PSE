#ifndef DETECTIONRESULTPANEL_H
#define DETECTIONRESULTPANEL_H
#include "contentview.h"
#include <QWidget>

namespace Ui {
class DetectionResultPanel;
}

class DetectionResultPanel : public QWidget, public ContentView
{
    Q_OBJECT

public:
    void resultsChanged(std::string nnName, std::string imgName, std::string imgPath, std::string resultPath);
    void nextNNEnable(bool flag);
    void prevNNEnable(bool flag);
    void nextImageEnable(bool flag);
    void prevImageEnable(bool flag);
    void saveResultEnable(bool flag);
    explicit DetectionResultPanel(QWidget *parent = nullptr);
    void update();
    void setCurrentResultPath(std::string path);
    void setCurrentImagePath(std::string path);
    ~DetectionResultPanel();
private slots:
    void on_prevImgButton_clicked();

    void on_nextImgButton_clicked();

    void on_prevNNButton_clicked();

    void on_nextNNButton_clicked();

    void on_saveResultsButton_clicked();

private:
    Ui::DetectionResultPanel *ui;
    std::string currentImagePath;
    std::string currentResultPath;
    void displayImage(std::string path);
    void displayResult(std::string path);
    static DetectionResultPanel* instance;
    DetectionResultPanel(int a);
};
#endif // DETECTIONRESULTPANEL_H
