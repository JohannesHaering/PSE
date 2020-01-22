#include "renderer.h"
#include <QtCore>
#include <QtGui>
#include <QPixmap>
#include <QLabel>
#include <QColor>
#include <QMessageBox>
Renderer::Renderer()
{
    //QImage imgIn= QImage((uchar*) img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);

}
void Renderer::drawRectangle(QPixmap* img, double x, double y, double width, double height, std::string strokeColor){
    QPainter paint(img);
    QPen pen;
    pen.setColor(Qt::green);
    paint.setPen(pen);
    paint.drawRect(x,y,width,height);
}

void Renderer::drawLine(QPixmap* pixmap, double x, double y,double xEnd,double yEnd, std::string strokeColor){
    QPainter paint(pixmap);
    QPen pen;
   // pen.setColor(Qt::QString::fromStdString(strokeColor));
    QPoint* point1 = new QPoint(x,y);
    QPoint* point2 = new QPoint(xEnd,yEnd);
   paint.drawLine(*point1,*point2);
}
