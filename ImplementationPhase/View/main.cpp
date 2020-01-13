#include "mainwindow.h"

#include <QApplication>
#include<QLabel>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QLabel *label = new QLabel;
    label->setText("pesho");
    w.show();
    return a.exec();
}
