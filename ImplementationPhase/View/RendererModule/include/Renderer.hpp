#ifndef RENDERER_H
#define RENDERER_H
#include <QImage>


class Renderer
{
public:
    Renderer();
    //virtual QPixmap drawGraphic();
    void drawRectangle(QPixmap* pixmap, double x, double y, double width, double height, std::string strokeColor);
    void drawText(QPixmap* pixmap, std::string text, double x, double y, double width, double height);
    void drawLine(QPixmap* pixmap, double x, double y, double xEnd, double yEnd, std::string strokeColor);
};

#endif // RENDERER_H
