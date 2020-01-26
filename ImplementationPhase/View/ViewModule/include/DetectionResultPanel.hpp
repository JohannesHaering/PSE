#ifndef DETECTIONRESULTPANEL_H
#define DETECTIONRESULTPANEL_H
#include "ContentView.hpp"
#include <QWidget>
namespace Ui {
class DetectionResultPanel;
}

class DetectionResultPanel : public QWidget, public ContentView
{
    Q_OBJECT

public:
    void resultsChanged(std::string nnName, std::string imgName, std::string imgPath, std::string result);
    void nextNNEnable(bool flag);
    void prevNNEnable(bool flag);
    void nextImageEnable(bool flag);
    void prevImageEnable(bool flag);
    void saveResultEnable(bool flag);
    explicit DetectionResultPanel(QWidget *parent = nullptr);
    void update();
    ~DetectionResultPanel();

private slots:
    void on_prevImgButton_clicked();

    void on_nextImgButton_clicked();

    void on_prevNNButton_clicked();

    void on_nextNNButton_clicked();

    void on_saveResultsButton_clicked();

private:
    Ui::DetectionResultPanel *ui;
    std::string currentImageName;
    std::string currentNNName;
    QPixmap *imagePixmap;
    QPixmap *resultPixmap;
    void displayImage();
    void displayResult();
};
#endif // DETECTIONRESULTPANEL_H
