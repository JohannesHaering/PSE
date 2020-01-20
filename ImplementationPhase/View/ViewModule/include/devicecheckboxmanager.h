#ifndef DEVICECHECKBOXMANAGER_H
#define DEVICECHECKBOXMANAGER_H
#include "device.h"
#include <QWidget>
#include <QCheckBox>
#include <QVBoxLayout>
namespace Ui {
class DeviceCheckBoxManager;
}

class DeviceCheckBoxManager : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceCheckBoxManager(QWidget *parent = nullptr);
    ~DeviceCheckBoxManager();
    void setDevices(std::vector<Device>* devices);
    std::vector<Device> getDevices();
private:
    Ui::DeviceCheckBoxManager *ui;
    QVBoxLayout* layout;
    std::vector<Device>* devicesVector;
    QCheckBox* checkboxes[];
};

#endif // DEVICECHECKBOXMANAGER_H
