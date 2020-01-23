#ifndef CONTENTVIEW_H
#define CONTENTVIEW_H
#include <QWidget>
#include <string>
#include <QString>
#include <QVector>
#include <vector>
<<<<<<< HEAD

=======
#include <opencv2/core/mat.hpp>
>>>>>>> stefi_implementation
class ContentView
{
public:
    ContentView();
    std::string getFileFromExplorer(std::vector<std::string> types);
    std::vector<std::string> getFilesFromExplorer(std::vector<std::string> types);
    std::string getDirectoryFromExplorer(std::vector<std::string> types);
    std::string getSaveFileName();
    void showError(std::string error);
<<<<<<< HEAD
  //  QPixmap convertCvtoQImg(cv::Mat mat);
=======
    QPixmap convertCvtoQImg(cv::Mat mat);
>>>>>>> stefi_implementation
private:
      QWidget *widg;
signals:

};

#endif // CONTENTVIEW_H
