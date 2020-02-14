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
    //trainer = CompleteTrainer(neuralNetwork, 0.01f, batchSize);  
    trainingAcc = std::vector<float>();
    testAcc = std::vector<float>();    
    supplyer = new TrainerClassificationDataSupply(DATATYPE::MNIST);
}

//Trainer::Trainer(NeuralNetworkAdapter* neuralNetwork, float desiredPrecision, std::string trainData)
Trainer::Trainer(NeuralNetworkAdapter* neuralNetwork, float desiredPrecision, std::string trainData) : Trainer(neuralNetwork, desiredPrecision, trainData, 16) {}

void Trainer::startTraining()
{
    for(int i = 0; i < batchSize*5; i++)
    {
      trainer.forward(supplyer->getImage(std::to_string(i)));
      trainer.train(supplyer->getOutputVector(std::to_string(i)));

      /*if (i % 10 == 0){
        trainer.forward(dataset_test_images[i]);
        testAcc.push_back(trainer.calcCEError(dataset_test_labels[i]));
        ControllerFacade::getInstance()->newTrainStep(trainingAcc, testAcc);   
      }*/
    }
    NeuralNetworkFacade* facade = new NeuralNetworkFacade();
    facade->saveNeuralNetwork(neuralNetwork->getNeuralNetwork(), "/home/pselabw1920/Downloads/network.cfg");
}
