#ifndef TOPOLOGY_H
#define TOPOLOGY_H

#include <QDialog>
#include "ContentView.hpp"
namespace Ui {
class TopologyPanel ;
}
class TopologyPanel  : public QDialog, public ContentView
{
    Q_OBJECT

public:
    explicit TopologyPanel (QWidget *parent = nullptr);
    ~TopologyPanel ();
    std::string getTopologyPath();
private slots:
    void on_pushButton_clicked();

private:
    Ui::TopologyPanel  *ui;
    ContentView* contView;
    std::string topologyPath;
};

#endif // TOPOLOGY_H
