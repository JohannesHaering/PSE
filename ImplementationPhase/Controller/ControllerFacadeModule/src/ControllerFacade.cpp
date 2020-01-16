#include "Inferencer.hpp"
#include "Distributor.hpp"
#include "InferencingDistributor.hpp"
#include "InferencingDistributorClassification.hpp"
#include "InferencingDistributorDetection.hpp"
#include "SaveResultHandler.hpp"
#include "InputImageHandler.hpp"
#include "NeuralNetworkHandler.hpp"
#include "NeuralNetworkPager.hpp"
#include "ImagePager.hpp"
#include "StartHandler.hpp"
#include "PagerHandler.hpp"
#include "NextHandler.hpp"
#include "PrevHandler.hpp"
#include "NewResultHandler.hpp"
#include "PredictionHandler.hpp"
#include "TrainingDistributor.hpp"
#include "NewTrainStepHandler.hpp"
#include "TopologyInferencer.hpp"
#include "ControllerFacade.hpp"

        ControllerFacade ControllerFacade::getInstance(){
            if (&instance == nullptr) {
                ControllerFacade::instance = ControllerFacade();
            }
            return instance;
        }

        // Classification Methods
        void ControllerFacade::startProcessClassification(){ classificationInferencer.startProcess(); }

        void ControllerFacade::saveResultsClassification(){ saveHandlerClassification.onAction(); }

        void ControllerFacade::nextNeuralNetworkClassification(){ nnNextHandlerClassification.onAction(); }

        void ControllerFacade::prevNeuralNetworkClassification(){ nnPrevHandlerClassification.onAction(); }

        void ControllerFacade::nextImageClassification(){ imgNextHandlerClassification.onAction(); }

        void ControllerFacade::prevImageClassification(){ imgPrevHandlerClassification.onAction(); }

        void ControllerFacade::getImageInputClassification(){ inputHandlerClassification.onAction(); }

        void ControllerFacade::getNeuralNetworkInputClassifcation(){ neuralNetworkHandlerClassification.onAction(); }

        void ControllerFacade::newResultClassification(){ newResultHandlerClassification.onAction(); }

        void ControllerFacade::newPredictionClassification(){ predictionHandlerClassification.onAction(); }

        // Detection Methods
        void ControllerFacade::startProcessDetection(){ detectionInferencer.startProcess(); }

        void ControllerFacade::saveResultsDetection(){ saveHandlerDetection.onAction(); }

        void ControllerFacade::nextNeuralNetworkDetection(){ nnNextHandlerDetection.onAction(); }

        void ControllerFacade::prevNeuralNetworkDetection(){ nnPrevHandlerDetection.onAction(); }

        void ControllerFacade::nextImageDetection(){ imgNextHandlerDetection.onAction(); }

        void ControllerFacade::prevImageDetection(){ imgPrevHandlerDetection.onAction(); }

        void ControllerFacade::getImageInputDetection(){ inputHandlerDetection.onAction(); }

        void ControllerFacade::getNeuralNetworkInputDetection(){ neuralNetworkHandlerDetection.onAction(); }

        void ControllerFacade::newResultDetection(){ newResultHandlerDetection.onAction(); }

        void ControllerFacade::newPredictionDetection(){ predictionHandlerDetection.onAction(); }

        // Training methods
        void ControllerFacade::startProcessTraining(){ startHandlerTraining.onAction(); }

        void ControllerFacade::getImageInputTraining(){ inputHandlerTraining.onAction(); }

        void ControllerFacade::getNeuralNetworkInputTraining(){ neuralNetworkHandlerTraining.onAction(); }

        void ControllerFacade::newTrainStep(std::vector<float> training, std::vector<float> test){ trainstepHandlerTraining.newAccuracyPoints(training, test); }

        // Topology methods
        void ControllerFacade::startProcessTopology() { startHandlerTopology.onAction(); }

        void ControllerFacade::getNeuralNetworkInputTopology() { neuralNetworkHandlerTopology.onAction(); }

        ControllerFacade::ControllerFacade() {
			ViewFacade view = ViewFacade::getInstance();
			
            // Setup Classification
			InferencePage classificationPage = view.getClassificationPage();
            classificationInferencer = InferencingDistributorClassification(classificationPage);
            NeuralNetworkPager neuralNetworkPager = NeuralNetworkPager(0, classificationPage);
            ImagePager imagePager = ImagePager(0, classificationPage);
            saveHandlerClassification = SaveResultHandler(classificationInferencer, neuralNetworkPager, imagePager);
            inputHandlerClassification = InputImageHandler(classificationInferencer);
            neuralNetworkHandlerClassification = NeuralNetworkHandler(classificationInferencer);
            startHandlerClassification = StartHandler(classificationInferencer);
            nnNextHandlerClassification = NextHandler(neuralNetworkPager);
			nnPrevHandlerClassification = PrevHandler(neuralNetworkPager);
			imgNextHandlerClassification = NextHandler(imagePager);
			imgPrevHandlerClassification = PrevHandler(imagePager);
            newResultHandlerClassification = NewResultHandler(classificationInferencer, neuralNetworkPager, imagePager);
            predictionHandlerClassification = PredictionHandler(classificationPage);
		
            // Setup Detection
			InferencePage detectionPage = view.getDetectionPage();
            detectionInferencer = InferencingDistributorDetection(detectionPage);
            NeuralNetworkPager neuralNetworkPagerDetection = NeuralNetworkPager(0, detectionPage);
            ImagePager imagePagerDetection = ImagePager(0, detectionPage);
            saveHandlerDetection = SaveResultHandler(detectionInferencer, neuralNetworkPagerDetection, imagePagerDetection);
            inputHandlerDetection = InputImageHandler(detectionInferencer);
            neuralNetworkHandlerDetection = NeuralNetworkHandler(detectionInferencer);
            startHandlerDetection = StartHandler(detectionInferencer);
			nnNextHandlerDetection = NextHandler(neuralNetworkPagerDetection);
			nnPrevHandlerDetection = PrevHandler(neuralNetworkPagerDetection);
			imgNextHandlerDetection = NextHandler(imagePagerDetection);
			imgPrevHandlerDetection = PrevHandler(imagePagerDetection);
            newResultHandlerDetection = NewResultHandler(classificationInferencer, neuralNetworkPagerDetection, imagePagerDetection);
            predictionHandlerDetection = PredictionHandler(detectionPage);

            // Setup Training
            trainingDistributor = TrainingDistributor();
            inputHandlerTraining = InputImageHandler(trainingDistributor);
            neuralNetworkHandlerTraining = NeuralNetworkHandler(trainingDistributor); 
            startHandlerTraining = StartHandler(trainingDistributor);
            trainstepHandlerTraining = NewTrainStepHandler();

            // Setup Topology
            topologyInferencer = TopologyInferencer();
            neuralNetworkHandlerTopology = NeuralNetworkHandler(topologyInferencer);
            startHandlerTopology = StartHandler(topologyInferencer);

            ViewFacade::getInstance().getClassificationPage().setActive(true);
        }