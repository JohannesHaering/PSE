#include <string>
#include <vector>
#include "NeuralNetworkAdapter.hpp"
#include "TopologyPage.hpp"
#include "TrainingPage.hpp"
#include "InferencePage.hpp"
#include "Result.hpp"

class ViewFacade {
    public: 
        
        static ViewFacade getInstance();

        std::vector<std::string> getDirectories(std::vector<std::string> filetypes);

        static InferencePage getClassificationPage();
        std::string getOperatingModeClassification();
        std::string getDevicesClassification();
        std::string getInputModeClassification();
        std::string getNeuralNetworkPathClassification();
        bool getShowResultsClassification();
        bool getSaveResultsClassification();
        int getImageAmountClassification();
        std::vector<std::string> getInputPathesClassification();
        std::vector<std::string> getAppendResultClassification();
        void setPowerPredictionClassification(int amount);
        void setPerformancePredictionClassification(int amount);
        void showPageClassification(bool flag);
        void startButtonEnableClassification(bool flag);
        void nextNeuralNetworkButtonEnableClass(bool flag);
        void prevNeuralNetworkButtonEnableClass(bool flag);
        void nextImageButtonEnableClass(bool flag);
        void prevImageButtonEnableClass(bool flag);
        void setResultClassification(Result result);
        std::vector<std::string> getPlatformsClassification();

		static InferencePage getDetectionPage();
        std::string getOperatingModeDetection();
        std::string getDevicesDetection();
        std::string getInputModeDetection();
        std::string getNeuralNetworkPathDetection();
        bool getShowResultsDetection();
        bool getSaveResultsDetection();
        int getImageAmountDetection();
        std::vector<std::string> getInputPathesDetection();
        std::vector<std::string> getAppendResultDetection();
        void setPowerPredictionDetection(int amount);
        void setPerformancePredictionDetection(int amount);
        void showPageDetection(bool flag);
        void startButtonEnableDetection(bool flag);
        void nextNeuralNetworkButtonEnableDetection(bool flag);
        void prevNeuralNetworkButtonEnableDetection(bool flag);
        void nextImageButtonEnableDetection(bool flag);
        void prevImageButtonEnableDetection(bool flag);
        void setResultDetection(Result result);

        static TrainingPage getTrainingPage();
        void newTrainingFinished(std::vector<float> pointsArrayTest, std::vector<float> pointsArrayTraining);
        float getLearningRate();
        float getPrecision();
        std::string getName();
        std::string getLearningMode();
        void startButtonEnableTraining(bool flag);

        static TopologyPage getTopologyPage();
        void topologyChanged(NeuralNetworkAdapter neuralNetworkAdapter);
        void startButtonEnableTopology(bool flag);

        void update();


};