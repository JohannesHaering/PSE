#ifndef VIEWFACADE_H
#define VIEWFACADE_H
#include <string>
#include <vector>
#include <iostream>
#include "InferencePage.hpp"
#include "TopologyPanel.hpp"
#include "TrainingPanel.hpp"
#include "ObjectDetectionInferencePage.hpp"
#include "MainWindow.hpp"

class ViewFacade {

  private:
      /* Here will be the instance stored. */
      static ViewFacade* instance;
      static TopologyPanel* topology;
      static TrainingPanel* training;
      MainWindow* mainMenu;
      static InferencePageAdapter* imageClassification;
      static ObjectDetectionInferencePageAdapter* objectDetection;
      /* Private constructor to prevent instancing. */
       ViewFacade();
       ~ViewFacade() = default;
       ViewFacade(const ViewFacade&) = delete;
       ViewFacade& operator=(const ViewFacade&) = delete;

  public:
       TopologyPanel* getTopologyPanel();
       ObjectDetectionInferencePageAdapter* getObjectDetection();
       InferencePageAdapter* getImageClassification();
       TrainingPanel* getTrainingPanel();
       MainWindow* getMainMenu();
       /* Static access method. */
       static ViewFacade* getInstance();
};

#endif // VIEWFACADE_H
