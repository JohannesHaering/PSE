#ifndef TRAININGRENDERER_H
#define TRAININGRENDERER_H
#include "renderer.h"
class TrainingRenderer : public Renderer
{
public:
    TrainingRenderer();
    QPixmap drawGraphic(std::vector<float> pointsArrayTest,std::vector<float> pointsArrayTraining);
};

#endif // TRAININGRENDERER_H
