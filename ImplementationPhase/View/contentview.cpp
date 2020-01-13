#include "contentview.h"
#include <QFileDialog>
#include <QMessageBox>
using namespace std;
ContentView::ContentView()
{

}
std::string ContentView::getFilesFromExplorer(std::vector<std::string> types){
    QWidget *widg = new QWidget();
    QString path = QFileDialog::getOpenFileName(widg,"Open a file", "C://");
    std::string returnPath = path.toUtf8().constData();
    std::string extention = returnPath.substr(returnPath.find(".") + 1);
    for(vector<string>::const_iterator i = types.begin(); i != types.end(); ++i)  {
        if (*i == extention){
          return returnPath;
        }
    }
    QMessageBox msgBox;
    msgBox.setText("Wrong file input. Please try again!");
    msgBox.exec();
    return 0;
}
