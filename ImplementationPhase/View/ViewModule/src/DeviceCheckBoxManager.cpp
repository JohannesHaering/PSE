#include "DeviceCheckBoxManager.hpp"
#include "ui_DeviceCheckBoxManager.h"
#include <QCheckBox>
#include <QScrollArea>
#include <QVBoxLayout>
DeviceCheckBoxManager::DeviceCheckBoxManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceCheckBoxManager)
{
    ui->setupUi(this);
    layout = new QVBoxLayout();
    ui->scrollAreaWidgetContents->setLayout(layout);
    ui->scrollArea->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    ui->scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);
    ui->scrollArea->setWidgetResizable( true );
}

DeviceCheckBoxManager::~DeviceCheckBoxManager()
{
    delete ui;
}
void DeviceCheckBoxManager::setDevices(std::vector<Device>* devices){
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        delete item->widget();
        delete item;
    }
    *checkboxes = new QCheckBox[devices->size()];
    int i = 0;
    devicesVector=devices;
    //layout->removeWidget(checkboxes)
    for(std::vector<Device>::iterator it = devices->begin(); it != devices->end(); ++it) {
        checkboxes[i] = new QCheckBox(QString::fromStdString(it->getName()));
        layout->addWidget(checkboxes[i]);
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
