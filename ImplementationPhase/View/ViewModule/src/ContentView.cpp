#include "ContentView.hpp"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QIODevice>
#include <QBuffer>
#include <QMessageBox>
#include <QDir>
ContentView::ContentView()
{

}
QPixmap ContentView::convertCvtoQImg(cv::Mat mat){
    return QPixmap::fromImage(QImage((unsigned char*) mat.data, mat.cols, mat.rows, QImage::Format_RGB888));
}
std::vector<std::string> ContentView::getFilesFromExplorer(std::vector<std::string> types){
    widg = new QWidget();
    QStringList ls = QFileDialog::getOpenFileNames(widg,"open files",*vectorToString(types), * new QString(QString::fromStdString(types[0])));
    std::vector<std::string> paths;
    for (int i = 0; i < ls.size(); ++i){
         paths.push_back(ls.at(i).toUtf8().constData());
    }
    return paths;
}
QString* ContentView::vectorToString(std::vector<std::string> formats) {
    std::string filter = "";
    for (std::vector<std::string>::iterator it = formats.begin(); it != formats.end(); ++it) {
        filter += *it + "(*." + *it + ") ;; ";
    }
    QString* filterEnd = new QString(QString::fromStdString(filter));
    filterEnd->truncate(filterEnd->lastIndexOf(QChar(';')));
    filterEnd->truncate(filterEnd->lastIndexOf(QChar(';')));
    return filterEnd;
}
std::string ContentView::getDirectoryFromExplorer(std::vector<std::string> types){
    widg = new QWidget();
    QString dir = QFileDialog::getExistingDirectory(widg, "Open Directory","/home", QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
    return dir.toUtf8().constData();
}
std::string ContentView::getFileFromExplorer(std::vector<std::string> types){
    widg = new QWidget();
    QString path = QFileDialog::getOpenFileName(widg,"Open a file","~",*vectorToString(types),new QString(QString::fromStdString(types[0])));
    return path.toUtf8().constData();
}
void ContentView::showError(std::string error){
    QMessageBox msgBox;
    msgBox.setText(QString::fromStdString(error));
    msgBox.exec();
}
std::string ContentView::getSaveFileName(){
   widg = new QWidget();
   return QFileDialog::getSaveFileName(widg,"open file","","JPEG (*.jpg *.jpeg);;PNG (*.png)").toUtf8().constData();
}
