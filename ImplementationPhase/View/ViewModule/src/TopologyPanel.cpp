#include "TopologyPanel.hpp"
#include "ui_TopologyPanel.h"
TopologyPanel ::TopologyPanel (QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TopologyPanel )
{
    ui->setupUi(this);

}

TopologyPanel ::~TopologyPanel ()
{
    delete ui;
}
std::string TopologyPanel ::getTopologyPath(){
    return topologyPath;
}
void TopologyPanel ::on_pushButton_clicked()
{
    std::vector<std::string> types = {"exe"};
    topologyPath = contView->getFileFromExplorer(types);
}
