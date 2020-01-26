// #include "MainWindow.hpp"
#include "ControllerFacade.hpp"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ControllerFacade::getInstance();
    ViewFacade::getInstance()->getMainMenu()->show();
    return a.exec();
}
