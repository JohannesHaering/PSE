#ifndef TOPOLOGY_H
#define TOPOLOGY_H

#include <QDialog>
#include "contentview.h"
namespace Ui {
class Topology;
}
class Topology : public QDialog, public ContentView
{
    Q_OBJECT

public:
    explicit Topology(QWidget *parent = nullptr);
    ~Topology();
    std::string getTopologyPath();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Topology *ui;
    ContentView* contView;
    std::string topologyPath;
};

#endif // TOPOLOGY_H
