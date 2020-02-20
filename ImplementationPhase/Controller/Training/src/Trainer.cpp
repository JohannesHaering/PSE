#include "CompleteTrainer.hpp"
#include "ControllerFacade.hpp"
#include "NetworkLayer.hpp"
#include "NeuralNetworkAdapter.hpp"
#include <vector>
#include "Trainer.hpp"
#include "/home/pselabw1920/Documents/mnist/include/mnist/mnist_reader.hpp"
#include "NeuralNetworkFacade.hpp"
#include "TrainerClassificationDataSupply.hpp"
#include "TrainerDataSupply.hpp"
#include "DataType.hpp"

Trainer::Trainer(NeuralNetworkAdapter* neuralNetwork, float desiredPrecision, std::string trainData) : neuralNetwork(neuralNetwork), desiredPrecision(desiredPrecision), trainData(trainData), trainer(CompleteTrainer(neuralNetwork, 0.001f))
{

   // facade->saveNeuralNetwork(neuralNetwork->getNeuralNetwork(), "/home/pselabw1920/Downloads/network.txt");
   
    //trainer = CompleteTrainer(neuralNetwork, 0.01f, batchSize);  
    trainingAcc = std::vector<float>();
    testAcc = std::vector<float>();    
    //TODO somehow update this to use trainData string and replace trainData string by somewhat smarter
    loadDataset();
}


void Trainer::loadDataset()
{
  std::cout<<"Get data" << std::endl;
  supplyer = new TrainerClassificationDataSupply(DATATYPE::MNIST, batchSize);
}

void Trainer::startTraining()
{
  TENSOR(float) results;  
  
  for(int b = 0; b < 5; b++) //train on 5 batches
    {
      //supplier
      
      std::cout<<"Next batch"<<std::endl;
      trainer.forward(supplyer->getTrainingBatchInput(b));
      trainer.train(supplyer->getTrainingBatchOutput(b));
      
      results = trainer.calcCEError(supplyer->getTrainingBatchOutput(b));
      for (int i = 0; i < results.size(); i++)
        testAcc.push_back(results[i][0][0][0]);
      //trainer.forward(dataset_train_images[i]);
      ControllerFacade::getInstance()->newTrainStep(trainingAcc, testAcc);   
      //trainer.train(dataset_train_labels[i]);

      /*if (i % 10 == 0){
        trainer.forward(dataset_test_images[i]);
        testAcc.push_back(trainer.calcCEError(dataset_test_labels[i]));
        ControllerFacade::getInstance()->newTrainStep(trainingAcc, testAcc);   
      }*/
    }
  //  NeuralNetworkFacade* facade = new NeuralNetworkFacade();
    NeuralNetworkFacade* facade = new NeuralNetworkFacade();
    facade->saveNeuralNetwork(neuralNetwork->getNeuralNetwork(), "/home/pselabw1920/Downloads/trainednetwork.txt");
   // facade->saveNeuralNetwork(neuralNetwork->getNeuralNetwork(), "/home/pselabw1920/Downloads/network.cfg");
}
