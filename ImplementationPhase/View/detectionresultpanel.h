#ifndef DETECTIONRESULTPANEL_H
#define DETECTIONRESULTPANEL_H

#include <QWidget>

namespace Ui {
class DetectionResultPanel;
}

class DetectionResultPanel : public QWidget
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
    ~DetectionResultPanel();
    void update();
    void setCurrentResultPath(std::string path);
    void setCurrentImagePath(std::string path);
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
