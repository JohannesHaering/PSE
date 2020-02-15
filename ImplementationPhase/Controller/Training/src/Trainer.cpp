#include "CompleteTrainer.hpp"
#include "ControllerFacade.hpp"
#include "NetworkLayer.hpp"
#include "NeuralNetworkAdapter.hpp"
#include <vector>
#include "Trainer.hpp"
#include "NeuralNetworkFacade.hpp"
#include "TrainerDataSupply.hpp"
#include "TrainerClassificationDataSupply.hpp"
#include "DataType.hpp"

Trainer::Trainer(NeuralNetworkAdapter* neuralNetwork, float desiredPrecision, std::string trainData, int batchSize) : neuralNetwork(neuralNetwork), desiredPrecision(desiredPrecision), trainData(trainData), batchSize(batchSize), trainer(CompleteTrainer(neuralNetwork, 0.01f, batchSize))
{
    trainingAcc = std::vector<float>();
    testAcc = std::vector<float>();    
    supplyer = new TrainerClassificationDataSupply(DATATYPE::MNIST);
}

Trainer::Trainer(NeuralNetworkAdapter* neuralNetwork, float desiredPrecision, std::string trainData) : Trainer(neuralNetwork, desiredPrecision, trainData, batchSize) {}

void Trainer::startTraining()
{
    for(int i = 0; i < batchSize; i++)
    {
      trainer.forward(supplyer->getTrainingBatchInput(batchSize, i));
      trainer.train(supplyer->getTrainingBatchOutput(batchSize, i));

      /*if (i % 10 == 0){
        trainer.forward(dataset_test_images[i]);
        testAcc.push_back(trainer.calcCEError(dataset_test_labels[i]));
        ControllerFacade::getInstance()->newTrainStep(trainingAcc, testAcc);   
      }*/
    }
    NeuralNetworkFacade* facade = new NeuralNetworkFacade();
    facade->saveNeuralNetwork(neuralNetwork->getNeuralNetwork(), "/home/pselabw1920/Downloads/network.cfg");
}
