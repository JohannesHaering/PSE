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
    std::string getFilesFromExplorer(std::vector<std::string> types);
signals:

};

#endif // CONTENTVIEW_H
