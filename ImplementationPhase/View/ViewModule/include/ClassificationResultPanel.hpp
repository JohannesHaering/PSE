#ifndef CLASSIFICATIONRESULTPANEL_H
#define CLASSIFICATIONRESULTPANEL_H
#include "ClassificationResultRenderer.hpp"
#include <QWidget>
#include "ContentView.hpp"
namespace Ui {
class ClassificationResultPanel;
}

class ClassificationResultPanel : public QWidget, public ContentView
{
    Q_OBJECT

public:
    explicit ClassificationResultPanel(QWidget *parent = nullptr);
    ~ClassificationResultPanel();
    void setCurrentImagePath(std::string path);
    void update();
    void setCurrentResultPath(std::string path);
    void resultsChanged(std::string nnName, std::string imgName, cv::Mat mat, ClassificationResult Result);
    void nextNNEnable(bool flag);
    void prevNNEnable(bool flag);
    void nextImageEnable(bool flag);
    void prevImageEnable(bool flag);
    void saveResultEnable(bool flag);
private slots:
    void on_prevImgButton_clicked();

    void on_nextImgButton_clicked();

    void on_prevNNButton_clicked();

    void on_nextNNButton_clicked();

    void on_saveResultButton_clicked();

private:
    bool canUpdate = false;
    ClassificationResultRenderer* renderer;
    Ui::ClassificationResultPanel *ui;
    std::string currentImagePath;
    std::string currentResultPath;
    // bool canUpdate = false;
    QPixmap* resultPixmap;
    QPixmap* imagePixmap;
    void displayImage();
    void displayResult();
};

#endif // CLASSIFICATIONRESULTPANEL_H
