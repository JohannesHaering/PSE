// #include "MainWindow.hpp"
#include "ViewFacade.hpp"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ViewFacade* viewFacade = ViewFacade::getInstance();
    MainWindow* w = viewFacade->getMainMenu();
    w->show();
    return a.exec();
}
