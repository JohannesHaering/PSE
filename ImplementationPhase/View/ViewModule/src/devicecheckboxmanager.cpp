#include "../include/devicecheckboxmanager.h"
#include "ui_devicecheckboxmanager.h"
#include <QCheckBox>
#include <QScrollArea>
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
void DeviceCheckBoxManager::setDevices(std::vector<Device>* devices){
    checkboxes[devices->size()];
    int i = 0;
    devicesVector=devices;
    for(std::vector<Device>::iterator it = devices->begin(); it != devices->end(); ++it) {
        checkboxes[i] = new QCheckBox(QString::fromStdString(it->getName()));
        ui->verticalLayout->addWidget(checkboxes[i]);
    }
}
std::vector<Device> DeviceCheckBoxManager::getDevices(){
    std::vector<Device>* returnDevices = new std::vector<Device>();
    int i=0;
    for(std::vector<Device>::iterator it = devicesVector->begin(); it != devicesVector->end(); ++it) {
        if(checkboxes[i]->isChecked()){
            returnDevices->push_back(*it);
        }
        i++;
    }
    return *returnDevices;
}
