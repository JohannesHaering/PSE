#ifndef VIEWFACADE_H
#define VIEWFACADE_H
#include <string>
#include <vector>
#include <iostream>
#include "inferencepage.h"
#include "topology.h"
#include "training.h"
#include "objectdetectioninferencepage.h"
#include "mainwindow.h"
class ViewFacade
{
private:
    /* Here will be the instance stored. */
    static ViewFacade* instance;
    static Topology* topology;
    static Training* training;
    MainWindow* mainMenu;
    static InferencePageAdapter* imageClassification;
    static ObjectDetectionInferencePageAdapter* objectDetection;
    /* Private constructor to prevent instancing. */
     ViewFacade();

public:
     Topology* getTopology();
     ObjectDetectionInferencePageAdapter* getObjectDetection();
     InferencePageAdapter* getImageClassification();
     Training* getTraining();
     MainWindow* getMainMenu();
     /* Static access method. */
     static ViewFacade* getInstance();
};

#endif // VIEWFACADE_H
