#include "devicecheckboxmanager.h"
#include "ui_devicecheckboxmanager.h"

DeviceCheckBoxManager::DeviceCheckBoxManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceCheckBoxManager)
{
    ui->setupUi(this);
}

DeviceCheckBoxManager::~DeviceCheckBoxManager()
{
    delete ui;
}
