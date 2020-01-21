#ifndef CONTENTVIEW_H
#define CONTENTVIEW_H
#include <QWidget>
#include <string>
#include <QString>
#include <QVector>
#include <vector>
#include <opencv2/core/mat.hpp>
class ContentView
{
public:
    ContentView();
    std::string getFileFromExplorer(std::vector<std::string> types);
    std::vector<std::string> getFilesFromExplorer(std::vector<std::string> types);
    std::string getDirectoryFromExplorer(std::vector<std::string> types);
    std::string getSaveFileName();
    void showError(std::string error);
    QPixmap convertCvtoQImg(cv::Mat mat);
private:
      QWidget *widg;
signals:

};

#endif // CONTENTVIEW_H
