#ifndef CLASSIFICATIONRESULTRENDERER_H
#define CLASSIFICATIONRESULTRENDERER_H
#include "renderer.h"
#include "classificationresult.h"
class ClassificationResultRenderer : public Renderer
{
public:
    ClassificationResultRenderer();
    QPixmap drawGraphic(ClassificationResult result);
};


#endif // CLASSIFICATIONRESULTRENDERER_H
