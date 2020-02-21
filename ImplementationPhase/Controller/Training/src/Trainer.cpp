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
#include <cmath> //fabs

Trainer::Trainer(NeuralNetworkAdapter* neuralNetwork, float desiredPrecision, std::string trainData, float learningRate) : neuralNetwork(neuralNetwork), desiredPrecision(desiredPrecision), trainData(trainData), trainer(CompleteTrainer(neuralNetwork, learningRate))
{

    trainAcc = std::vector<float>();
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
  TENSOR(float) testresults;
  TENSOR(float) testFeedback;
  for(int b = 0; b < 50; b++) //train on 5 batches
  {
      auto t1 = std::chrono::high_resolution_clock::now();

      trainer.forward(supplyer->getTrainingBatchInput(b));
      //testAcc is after training on this batch, trainAcc ist acc before training on this batch
      
      testFeedback = supplyer->getTrainingBatchOutput(b);
      results = trainer.calcCEError(testFeedback);
      for (int i = 0; i < results.size(); i++)
        trainAcc.push_back(fabs(results[i][0][0][0]));

      trainer.train(supplyer->getTrainingBatchOutput(b));
      
      testresults = trainer.calcCEError(testFeedback);

      //for (int i = 0; i < testresults.size(); i++){
      //  testAcc.push_back(fabs(testresults[i][0][0][0]));
      //}

      if (b % 10 == 0){
        TENSOR(float) forward_output = trainer.forward(supplyer->getTestBatchInput(b));
        TENSOR(float) feedback = supplyer->getTestBatchOutput(b);
        testresults = trainer.calcCEError(feedback);
        int correctNum;
        for (int testb = 0; testb < forward_output.size(); testb++) {

          testAcc.push_back(fabs(testresults[testb][0][0][0]));
          for (int i = 0; i < 10; i++) if (feedback[testb][0][0][i] == 1) correctNum = i;
          std::cout << "should be: " << correctNum << " NN output: " << std::endl;
          for (int i = 0; i < 10; i++) {
              std::cout << forward_output[testb][0][0][i] << " ";
          }
          std::cout << std::endl;
          
        }
      }

      auto t2 = std::chrono::high_resolution_clock::now();
      
      std::cout << "batch took "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
              << " milliseconds\n";
      

    }
    std::cout << "test / train ACC vec length " << testAcc.size() << " " << trainAcc.size() << std::endl;

    for (int i = 0; i < testAcc.size(); i++)
      std::cout << "train: " << trainAcc[i] << " test " << testAcc[i] << std::endl;

    //ControllerFacade::getInstance()->newTrainStep(std::vector<float>{0.3,0.3,0.3,}, std::vector<float>());   
    ControllerFacade::getInstance()->newTrainStep(testAcc, trainAcc);   
    //ControllerFacade::getInstance()->newTrainStep(testAcc, trainAcc);   

    NeuralNetworkFacade* facade = new NeuralNetworkFacade();
    facade->saveNeuralNetwork(neuralNetwork->getNeuralNetwork(), "/home/pselabw1920/Documents/trainednetworks/" + trainData + ".txt");
}
