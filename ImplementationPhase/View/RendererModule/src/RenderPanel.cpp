#include "RenderPanel.hpp"
#include "ui_RenderPanel.h"
#include "ContentView.hpp"
#include <QPainter>
#include <QFile>
#include <QIODevice>
#include <QBuffer>
#include <QMessageBox>
#include <QDir>
#include <QFileDialog>
#include "ClassificationResultRenderer.hpp"
#include "TrainingRenderer.hpp"
#include "ViewFacade.hpp"
RenderPanel::RenderPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RenderPanel)
{
    ui->setupUi(this);
}

RenderPanel::~RenderPanel()
{
    delete ui;
}

void RenderPanel::on_start_clicked()
{
//        ClassificationResultRenderer *rend = new ClassificationResultRenderer();
//        ClassProbability *prob1 = new ClassProbability("pesho", 0.1);
//        ClassProbability *prob2 = new ClassProbability("kari", 0.5);
//        ClassProbability *prob3 = new ClassProbability("mitakaa", 0.7);
//        std::list<ClassProbability> *prob = new std::list<ClassProbability>;
//      //std::list<ClassProbability>::iterator it;
//        prob->push_back(*prob1);
//        prob->push_back(*prob2);
//        prob->push_back(*prob3);
//        ClassificationResult result("1","2",*prob);
//        pixmap = new QPixmap(rend->drawGraphic(result));
//        drawRectangle(pixmap,30,50,30,40,"green");
//        ui->img->setPixmap(*pixmap);
    ViewFacade *view = ViewFacade::getInstance();
    view->getImageClassification()->showError("asdf");


}

void RenderPanel::on_addImage_clicked()
{
    std::vector<std::string> types = {"PNG","JPG","png","jpg","jpeg","JPEG"};
    ContentView contView;
    path = contView.getFileFromExplorer(types);
    QString pathImg = QString::fromStdString(path);
    pixmap = new QPixmap(pathImg);
    ui->img->setPixmap(pixmap->scaled(1150,450));
}

void RenderPanel::on_save_clicked()
{
    QByteArray bytes;
    QBuffer buffer(&bytes);
    buffer.open(QIODevice::WriteOnly);
    QString savePath = QFileDialog::getSaveFileName(this,tr("open file"),"",tr("Files (*.jpg *.jpeg *.png)"));
    pixmap->save(savePath);
}

void RenderPanel::on_currentImageStart_clicked()
{
    drawRectangle(pixmap,100,400,300,200,"blue");
    drawLine(pixmap,100,200,500,400,"green");
    ui->img->setPixmap(*pixmap);
}

void RenderPanel::on_trainingbutt_clicked()
{
    TrainingRenderer* rend = new TrainingRenderer();
    std::vector<float> points = {0.5,0.8,0.4};
    std::vector<float> points2 = {0.2,0.3,0.8,0.9};
    pixmap = new QPixmap(rend->drawGraphic(points,points2));
    ui->img->setPixmap(*pixmap);

}

void RenderPanel::on_trainingsss_clicked()
{
    TrainingRenderer* rend = new TrainingRenderer();
    std::vector<float> points = {0.1,0.2,0.5,0.9};
    std::vector<float> points2 = {0.2,0.3,0.8,0.9};
   pixmap = new QPixmap(rend->drawGraphic(points,points2));
   ui->img->setPixmap(*pixmap);

}
