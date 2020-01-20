#ifndef CONTENTVIEW_H
#define CONTENTVIEW_H

#include <QWidget>
#include <string>
#include <QString>
#include <QVector>
#include <vector>
class ContentView
{
public:
    ContentView();
    std::string getFileFromExplorer(std::vector<std::string> types);
    std::vector<std::string> getFilesFromExplorer(std::vector<std::string> types);
   // std::string getFilesFromExplorer(std::vector<std::string> types);
    std::string getDirectoryFromExplorer(std::vector<std::string> types);
    std::string getSaveFileName();
    void showError(std::string error);
private:
      QWidget *widg;
signals:

};

#endif // CONTENTVIEW_H
