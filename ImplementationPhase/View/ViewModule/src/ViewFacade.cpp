#include "ViewFacade.hpp"
#include "ControllerFacade.hpp"


ViewFacade* ViewFacade::instance = 0;

ViewFacade::ViewFacade() {
    mainMenu = new MainWindow();
    ControllerFacade::getInstance();
}

ViewFacade* ViewFacade::getInstance() {
    if (!instance) {
        instance = new ViewFacade();
    }
    return instance;
}

MainWindow* ViewFacade::getMainMenu() {
    return  mainMenu;
}

TrainingPanel* ViewFacade::getTrainingPanel() {
    return mainMenu->getTrainingPanel();
}

TopologyPanel* ViewFacade::getTopologyPanel() {
    return mainMenu->getTopologyPanel();
}

ObjectDetectionInferencePageAdapter* ViewFacade::getObjectDetection() {
    return mainMenu->getObjectDetection();
}

InferencePageAdapter* ViewFacade::getImageClassification() {
    return mainMenu->getImageClassification();
}

// int ViewFacade::startUI(int argc, char *argv[]) {
//   QApplication a(argc, argv);
//   mainMenu->show();
//   return a.exec();
// }
