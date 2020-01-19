#ifndef DETECTIONRESULTRENDERER_H
#define DETECTIONRESULTRENDERER_H
#include "classificationresultrenderer.h"
//#include "detectionresult.h"
class DetectionResultRenderer : public ClassificationResultRenderer
{
public:
    DetectionResultRenderer();
    //QPixmap drawGraphic(DetectionResult result, QPixmap imagePixmap);
};

#endif // DETECTIONRESULTRENDERER_H
