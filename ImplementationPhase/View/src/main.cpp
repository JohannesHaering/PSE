// #include "MainWindow.hpp"
#include "ControllerFacade.hpp"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ControllerFacade::getInstance();
    ViewFacade::getInstance()->getMainMenu()->show();
    a.exec();
    return 0;
}
