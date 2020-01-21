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
#include "inferencepageadapter.h"
#include "viewfacade.h"

        ControllerFacade* ControllerFacade::getInstance(){
            if (&instance == nullptr) {
                ControllerFacade::instance = new ControllerFacade();
            }
            return instance;
        }

        // Classification Methods
        void ControllerFacade::startProcessClassification(){ classificationInferencer->startProcess(); }

        void ControllerFacade::saveResultsClassification(){ saveHandlerClassification->onAction(); }

        void ControllerFacade::nextNeuralNetworkClassification(){ nnNextHandlerClassification->onAction(); }

        void ControllerFacade::prevNeuralNetworkClassification(){ nnPrevHandlerClassification->onAction(); }

        void ControllerFacade::nextImageClassification(){ imgNextHandlerClassification->onAction(); }

        void ControllerFacade::prevImageClassification(){ imgPrevHandlerClassification->onAction(); }

        void ControllerFacade::getImageInputClassification(){ inputHandlerClassification->onAction(); }

        void ControllerFacade::getNeuralNetworkInputClassifcation(){ neuralNetworkHandlerClassification->onAction(); }

        void ControllerFacade::newResultClassification(){ newResultHandlerClassification->onAction(); }

        void ControllerFacade::newPredictionClassification(){ predictionHandlerClassification->onAction(); }

        // Detection Methods
        void ControllerFacade::startProcessDetection(){ detectionInferencer->startProcess(); }

        void ControllerFacade::saveResultsDetection(){ saveHandlerDetection->onAction(); }

        void ControllerFacade::nextNeuralNetworkDetection(){ nnNextHandlerDetection->onAction(); }

        void ControllerFacade::prevNeuralNetworkDetection(){ nnPrevHandlerDetection->onAction(); }

        void ControllerFacade::nextImageDetection(){ imgNextHandlerDetection->onAction(); }

        void ControllerFacade::prevImageDetection(){ imgPrevHandlerDetection->onAction(); }

        void ControllerFacade::getImageInputDetection(){ inputHandlerDetection->onAction(); }

        void ControllerFacade::getNeuralNetworkInputDetection(){ neuralNetworkHandlerDetection->onAction(); }

        void ControllerFacade::newResultDetection(){ newResultHandlerDetection->onAction(); }

        void ControllerFacade::newPredictionDetection(){ predictionHandlerDetection->onAction(); }

        // Training methods
        void ControllerFacade::startProcessTraining(){ startHandlerTraining->onAction(); }

        void ControllerFacade::getImageInputTraining(){ inputHandlerTraining->onAction(); }

        void ControllerFacade::getNeuralNetworkInputTraining(){ neuralNetworkHandlerTraining->onAction(); }

        void ControllerFacade::newTrainStep(std::vector<float> training, std::vector<float> test){ trainstepHandlerTraining->newAccuracyPoints(training, test); }

        // Topology methods
        void ControllerFacade::startProcessTopology() { startHandlerTopology->onAction(); }

        void ControllerFacade::getNeuralNetworkInputTopology() { neuralNetworkHandlerTopology->onAction(); }

        ControllerFacade::ControllerFacade() {
			ViewFacade view = *ViewFacade::getInstance();
			
            // Setup Classification
			InferencePageAdapter classificationPage = *view.getImageClassification();
            classificationInferencer = new InferencingDistributorClassification(classificationPage);
            NeuralNetworkPager neuralNetworkPager =  NeuralNetworkPager(0, classificationPage);
            ImagePager imagePager = ImagePager(0, classificationPage);
            saveHandlerClassification = new SaveResultHandler(classificationInferencer, neuralNetworkPager, imagePager);
            inputHandlerClassification = new InputImageHandler(classificationInferencer);
            neuralNetworkHandlerClassification = new NeuralNetworkHandler(classificationInferencer);
            startHandlerClassification = new StartHandler(classificationInferencer);
            nnNextHandlerClassification = new NextHandler(neuralNetworkPager);
			nnPrevHandlerClassification = new PrevHandler(neuralNetworkPager);
			imgNextHandlerClassification = new NextHandler(imagePager);
			imgPrevHandlerClassification = new PrevHandler(imagePager);
            newResultHandlerClassification = new NewResultHandler(*classificationInferencer, neuralNetworkPager, imagePager);
            predictionHandlerClassification = new PredictionHandler(classificationPage);
		
            // Setup Detection
			InferencePageAdapter detectionPage = *view.getObjectDetection();
            detectionInferencer = new InferencingDistributorDetection(detectionPage);
            NeuralNetworkPager neuralNetworkPagerDetection = NeuralNetworkPager(0, detectionPage);
            ImagePager imagePagerDetection = ImagePager(0, detectionPage);
            saveHandlerDetection = new SaveResultHandler(detectionInferencer, neuralNetworkPagerDetection, imagePagerDetection);
            inputHandlerDetection = new InputImageHandler(detectionInferencer);
            neuralNetworkHandlerDetection = new NeuralNetworkHandler(detectionInferencer);
            startHandlerDetection = new StartHandler(detectionInferencer);
			nnNextHandlerDetection = new NextHandler(neuralNetworkPagerDetection);
			nnPrevHandlerDetection = new PrevHandler(neuralNetworkPagerDetection);
			imgNextHandlerDetection = new NextHandler(imagePagerDetection);
			imgPrevHandlerDetection = new PrevHandler(imagePagerDetection);
            newResultHandlerDetection = new NewResultHandler(classificationInferencer, neuralNetworkPagerDetection, imagePagerDetection);
            predictionHandlerDetection = new PredictionHandler(detectionPage);

            // Setup Training
            trainingDistributor = new TrainingDistributor();
            inputHandlerTraining = new InputImageHandler(trainingDistributor);
            neuralNetworkHandlerTraining = new NeuralNetworkHandler(trainingDistributor); 
            startHandlerTraining = new StartHandler(trainingDistributor);
            trainstepHandlerTraining = new NewTrainStepHandler();

            // Setup Topology
            topologyInferencer = new TopologyInferencer();
            neuralNetworkHandlerTopology = new NeuralNetworkHandler(topologyInferencer);
            startHandlerTopology = new StartHandler(topologyInferencer);

            ViewFacade::getInstance()->getImageClassification().setActive(true);
        }