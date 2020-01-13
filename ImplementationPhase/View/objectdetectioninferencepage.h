#ifndef OBJECTDETECTIONINFERENCEPAGE_H
#define OBJECTDETECTIONINFERENCEPAGE_H

#include <QDialog>

namespace Ui {
class ObjectDetectionInferencePage;
}

class ObjectDetectionInferencePage : public QDialog
{
    Q_OBJECT

public:
    explicit ObjectDetectionInferencePage(QWidget *parent = nullptr);
    ~ObjectDetectionInferencePage();
    std::string getOperatingMode();
    std::string getDevices();
    std::string getInputMode();
    std::string getNeuralNetworkPath();
    bool getShowResults();
    bool getSaveResults();

    std::string getImageAmount();
private slots:
    void on_start_clicked();

private:
    Ui::ObjectDetectionInferencePage *ui;
};

#endif // OBJECTDETECTIONINFERENCEPAGE_H
