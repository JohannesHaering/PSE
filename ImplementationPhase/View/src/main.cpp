// #include "MainWindow.hpp"
#include "ControllerFacade.hpp"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[]) {
    std::cout<<"Started\n";
    QApplication a(argc, argv);
    std::cout<<"Ran QT\n";
    ControllerFacade::getInstance();
    std::cout<<"Just made a ControllerFacade\n";
    ViewFacade::getInstance()->getMainMenu()->show();
    std::cout<<"Just made a ViewFacade\n";
    return a.exec();
}
