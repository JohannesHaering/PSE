#ifndef VIEWFACADE_H
#define VIEWFACADE_H
#include <string>
#include <vector>
#include <iostream>
#include "inferencepageadapter.h"
//#include "topology.h"
//#include "training.h"
#include "objectdetectioninferencepageadapter.h"
//#include "mainwindow.h"
class ViewFacade
{

public:
     //Topology* getTopology();
     ObjectDetectionInferencePageAdapter* getObjectDetection();
     InferencePageAdapter* getImageClassification();
     //Training* getTraining();
    /* Static access method. */
    static ViewFacade* getInstance();
    void nextNNEnable(bool flag);
    void prevNNEnable(bool flag);
    void nextImageEnable(bool flag);
    void prevImageEnable(bool flag);
    void saveResultNNEnable(bool flag);
    std::string getCheckBoxesDevice();
    bool getCheckBoxAppendResults();
    bool getShowResultsCheckBox();
    bool getSaveResultsCheckBox();
    bool getAppendResultsCheckBox();
    std::string getNeuralNetworkPath();
    std::string getOperatingMode();
    std::string getImageAmount();
  //  std::vector<std::string> getDevices();
    std::string getInputMode();
    bool getShowResults();
    bool getSaveResults();
  //  std::vector<std::string> getInputPathes();
    std::vector<std::string> getAppendResult();
  //  void topolgyChanged(NeuralNetwork nn);
    void newTrainingFinished(float pointsArrayTest[],float pointsArrayTraining[]);
    float getLearningRate();
    float getPrecision();
    std::string getName();
    std::string getLearningMode();
 //   std::string getPathsFromExplorer();
    void update();
};

#endif // VIEWFACADE_H
