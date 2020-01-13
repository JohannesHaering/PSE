#ifndef CLASSIFICATIONRESULTPANEL_H
#define CLASSIFICATIONRESULTPANEL_H

#include <QWidget>

namespace Ui {
class ClassificationResultPanel;
}

class ClassificationResultPanel : public QWidget
{
    Q_OBJECT

public:
    explicit ClassificationResultPanel(QWidget *parent = nullptr);
    ~ClassificationResultPanel();
    void setCurrentImagePath(std::string path);
    void update();
    void setCurrentResultPath(std::string path);
    static ClassificationResultPanel* getInstance();
    void resultsChanged(std::string nnName, std::string imgName, std::string imgPath, std::string resultPath);
    void nextNNEnable(bool flag);
    void prevNNEnable(bool flag);
    void nextImageEnable(bool flag);
    void prevImageEnable(bool flag);
    void saveResultEnable(bool flag);
private:
    Ui::ClassificationResultPanel *ui;
    std::string currentImagePath;
    std::string currentResultPath;
    void displayImage(std::string path);
    void displayResult(std::string path);
    static ClassificationResultPanel* instance;
    ClassificationResultPanel(int a);
};

#endif // CLASSIFICATIONRESULTPANEL_H
