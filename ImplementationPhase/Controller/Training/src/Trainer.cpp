#include "CompleteTrainer.hpp"
#include "ControllerFacade.hpp"
#include "NetworkLayer.hpp"
#include "NeuralNetworkAdapter.hpp"
#include <vector>
#include "Trainer.hpp"
#include "/home/steki/Desktop/mnist/include/mnist/mnist_reader.hpp"
#include "NeuralNetworkFacade.hpp"
#include "TrainerClassificationDataSupply.hpp"
#include "TrainerDataSupply.hpp"
#include "DataType.hpp"

Trainer::Trainer(NeuralNetworkAdapter* neuralNetwork, float desiredPrecision, std::string trainData) : neuralNetwork(neuralNetwork), desiredPrecision(desiredPrecision), trainData(trainData), trainer(CompleteTrainer(neuralNetwork, 0.01f))
{
    //trainer = CompleteTrainer(neuralNetwork, 0.01f, batchSize);  
    trainingAcc = std::vector<float>();
    testAcc = std::vector<float>();    
    //TODO somehow update this to use trainData string and replace trainData string by somewhat smarter
    loadDataset();
}


void Trainer::loadDataset()
{
    supplyer = new TrainerClassificationDataSupply(DATATYPE::MNIST, batchSize);
}

void Trainer::startTraining()
{
    for(int b = 0; b < 5; b++) //train on 5 batches
    {
      //supplier
      trainer.forward(supplyer->getTrainingBatchInput(b));
      trainer.train(supplyer->getTrainingBatchOutput(b));
      //trainer.forward(dataset_train_images[i]);
      //trainer.train(dataset_train_labels[i]);

      /*if (i % 10 == 0){
        trainer.forward(dataset_test_images[i]);
        testAcc.push_back(trainer.calcCEError(dataset_test_labels[i]));
        ControllerFacade::getInstance()->newTrainStep(trainingAcc, testAcc);   
      }*/
    }
    NeuralNetworkFacade* facade = new NeuralNetworkFacade();
    facade->saveNeuralNetwork(neuralNetwork->getNeuralNetwork(), "/home/pselabw1920/Downloads/network.cfg");
}
