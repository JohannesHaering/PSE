#ifndef DEVICECHECKBOXMANAGER_H
#define DEVICECHECKBOXMANAGER_H

#include <QWidget>

namespace Ui {
class DeviceCheckBoxManager;
}

class DeviceCheckBoxManager : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceCheckBoxManager(QWidget *parent = nullptr);
    ~DeviceCheckBoxManager();

private:
    Ui::DeviceCheckBoxManager *ui;
};

#endif // DEVICECHECKBOXMANAGER_H
