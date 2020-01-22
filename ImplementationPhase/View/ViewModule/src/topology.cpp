#include "topology.h"
#include "ui_topology.h"
Topology::Topology(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Topology)
{
    ui->setupUi(this);

}

Topology::~Topology()
{
    delete ui;
}
std::string Topology::getTopologyPath(){
    return topologyPath;
}
void Topology::on_pushButton_clicked()
{
    std::vector<std::string> types = {"exe"};
    topologyPath = contView->getFileFromExplorer(types);
}
