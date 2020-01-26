#include "Inferencer.hpp"
#include "Distributor.hpp"
#include "InferencingDistributor.hpp"
#include "InferencingDistributorClassification.hpp"
#include "SaveResultHandler.hpp"
#include "InputImageHandler.hpp"
#include "NeuralNetworkHandler.hpp"
#include "StartHandler.hpp"
#include "PagerHandler.hpp"
#include "NextHandler.hpp"
#include "PrevHandler.hpp"
#include "NewResultHandler.hpp"
#include "PredictionHandler.hpp"
// #include "TrainingDistributor.hpp"
#include "NewTrainStepHandler.hpp"
#include "TopologyInferencer.hpp"
#include "DeviceHandler.hpp"


class ControllerFacade {

    public:
        static ControllerFacade* getInstance();

        // Classification Methods
        void startProcessClassification();
        void saveResultsClassification();
        void nextNeuralNetworkClassification();
        void prevNeuralNetworkClassification();
        void nextImageClassification();
        void prevImageClassification();
        void getImageInputClassification();
        void getNeuralNetworkInputClassifcation();
        void newResultClassification();
        void newPredictionClassification();
		void searchDevicesClassification();

        // Detection Methods
        void startProcessDetection();
        void saveResultsDetection();
        void nextNeuralNetworkDetection();
        void prevNeuralNetworkDetection();
        void nextImageDetection();
        void prevImageDetection();
        void getImageInputDetection();
        void getNeuralNetworkInputDetection();
        void newResultDetection();
        void newPredictionDetection();
		void searchDevicesDetection();

        // Training methods
        // void startProcessTraining();
        // void getImageInputTraining();
        // void getNeuralNetworkInputTraining();
        // void newTrainStep(std::vector<float> training, std::vector<float> test);

        // Topology methods
        void startProcessTopology();
        void getNeuralNetworkInputTopology();


    private:
        ControllerFacade();

        static ControllerFacade* instance;

        // Classsification components
        InferencingDistributor* classificationInferencer;
        SaveResultHandler* saveHandlerClassification;
        InputImageHandler* inputHandlerClassification;
        NeuralNetworkHandler* neuralNetworkHandlerClassification;
        StartHandler* startHandlerClassification;
        PagerHandler* nnNextHandlerClassification;
        PagerHandler* nnPrevHandlerClassification;
        PagerHandler* imgNextHandlerClassification;
        PagerHandler* imgPrevHandlerClassification;
        NewResultHandler* newResultHandlerClassification;
        PredictionHandler* predictionHandlerClassification;
		DeviceHandler* deviceHandlerClassification;

        // Detection components
        InferencingDistributor* detectionInferencer;
        SaveResultHandler* saveHandlerDetection;
        InputImageHandler* inputHandlerDetection;
        NeuralNetworkHandler* neuralNetworkHandlerDetection;
        StartHandler* startHandlerDetection;
        PagerHandler* nnNextHandlerDetection;
        PagerHandler* nnPrevHandlerDetection;
        PagerHandler* imgNextHandlerDetection;
        PagerHandler* imgPrevHandlerDetection;
        NewResultHandler* newResultHandlerDetection;
        PredictionHandler* predictionHandlerDetection;
		DeviceHandler* deviceHandlerDetection;

        // Training components
        // TrainingDistributor* trainingDistributor;
        // InputImageHandler* inputHandlerTraining;
        // NeuralNetworkHandler* neuralNetworkHandlerTraining;
        // StartHandler* startHandlerTraining;
        // NewTrainStepHandler* trainstepHandlerTraining;

        // Topology components
        TopologyInferencer* topologyInferencer;
        NeuralNetworkHandler* neuralNetworkHandlerTopology;
        StartHandler* startHandlerTopology;

};
