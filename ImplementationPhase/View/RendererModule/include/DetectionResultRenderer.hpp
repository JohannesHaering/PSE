#ifndef DETECTIONRESULTRENDERER_H
#define DETECTIONRESULTRENDERER_H
#include "ClassificationResultRenderer.hpp"
//#include "detectionResult.hpp"
class DetectionResultRenderer : public ClassificationResultRenderer
{
public:
    DetectionResultRenderer();
    //QPixmap drawGraphic(DetectionResult result, QPixmap imagePixmap);
};

#endif // DETECTIONRESULTRENDERER_H
