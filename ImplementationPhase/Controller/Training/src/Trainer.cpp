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
#include <chrono> //for time measurement

Trainer::Trainer(NeuralNetworkAdapter* neuralNetwork, float desiredPrecision, std::string trainData, float learningRate) : neuralNetwork(neuralNetwork), desiredPrecision(desiredPrecision), trainData(trainData), trainer(CompleteTrainer(neuralNetwork, learningRate))
{

    trainingAcc = std::vector<float>();
    testAcc = std::vector<float>();    
    //TODO somehow update this to use trainData string and replace trainData string by somewhat smarter
    //TODO2 we use somewhat smarter now, still should update string
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
  
  for(int b = 0; b < 200; b++) //train on 5 batches
    {
      auto t1 = std::chrono::high_resolution_clock::now();

      trainer.forward(supplyer->getTrainingBatchInput(b));
      trainer.train(supplyer->getTrainingBatchOutput(b));
      
      results = trainer.calcCEError(supplyer->getTrainingBatchOutput(b));
      for (int i = 0; i < results.size(); i++)
        testAcc.push_back(results[i][0][0][0]);
      ControllerFacade::getInstance()->newTrainStep(trainingAcc, testAcc);   

      /*if (i % 10 == 0){
        trainer.forward(dataset_test_images[i]);
        testAcc.push_back(trainer.calcCEError(dataset_test_labels[i]));
        ControllerFacade::getInstance()->newTrainStep(trainingAcc, testAcc);   
      }*/

      auto t2 = std::chrono::high_resolution_clock::now();
      
      std::cout << "batch took "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
              << " milliseconds\n";

    }
    NeuralNetworkFacade* facade = new NeuralNetworkFacade();
    facade->saveNeuralNetwork(neuralNetwork->getNeuralNetwork(), "/home/pselabw1920/Downloads/trainednetwork.txt");
}
