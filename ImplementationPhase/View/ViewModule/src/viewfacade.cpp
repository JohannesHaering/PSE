#include "viewfacade.h"


ViewFacade* ViewFacade::instance = 0;
ViewFacade::ViewFacade()
{
}
ViewFacade* ViewFacade::getInstance()
{
    if (instance == 0)
    {
        instance = new ViewFacade();
    }

    return instance;
}
Training* ViewFacade::getTraining(){
    return mainMenu->getTraining();
}
Topology* ViewFacade::getTopology(){
    return mainMenu->getTopology();
}
ObjectDetectionInferencePageAdapter* ViewFacade::getObjectDetection(){
    return mainMenu->getObjectDetection();
}
InferencePageAdapter* ViewFacade::getImageClassification(){
    return mainMenu->getImageClassification();
}
