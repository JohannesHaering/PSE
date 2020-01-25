#ifndef CLASSIFICATIONRESULTRENDERER_H
#define CLASSIFICATIONRESULTRENDERER_H
#include "Renderer.hpp"
#include "ClassificationResult.hpp"
class ClassificationResultRenderer : public Renderer
{
public:
    ClassificationResultRenderer();
    QPixmap drawGraphic(ClassificationResult result);
};


#endif // CLASSIFICATIONRESULTRENDERER_H
