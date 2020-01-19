#include "..\include\contentview.h"
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

        QStringList ls = QFileDialog::getOpenFileNames(widg,"open files");

                QString dir = QFileDialog::getExistingDirectory(widg, "Open Directory","/home", QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);

    //QStringList ls = QFileDialog::getOpenFileNames(widg,"open files");
    //std::string extention = returnPath.substr(returnPath.find(".") + 1);
    std::vector<string> paths;
    QStringList::const_iterator constIterator;
    int i=0;
//    for (constIterator = ls.constBegin(); constIterator != ls.constEnd();
//               ++constIterator){
//        paths.at(i) = *constIterator->toUtf8().constData();
//    }
//    for(vector<string>::const_iterator i = types.begin(); i != types.end(); ++i)  {
//        if (*i == extention){
//          return returnPath;
//        }
//    }
    return returnPath;
}
void ContentView::showError(std::string error){
    QMessageBox msgBox;
    msgBox.setText(QString::fromStdString(error));
    msgBox.exec();
}
