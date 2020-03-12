#include "NeuralNetworkAdapter.hpp"
#include "Executor.hpp"
#include "NeuralNetworkFacade.hpp"
#include "Executor.hpp"
#include "MatrixDefine.hpp"
#include "DeviceType.hpp"
#include "MNISTDataParser.hpp"

#include <opencv2/opencv.hpp>
#include <CL/cl2.hpp>

#include <iostream>
#include <string>
#include <vector>


void printMatrix(MATRIX_3D(float) input)
{
      
  for (int i = 0; i < input[0].size(); i++) {
    for (int j = 0; j < input[0][0].size(); j++) {
      if (input[0][i][j] < 0.5f){
        std::cout << "0" << " | ";
      } else {
        std::cout << "1" << " | ";
      }
    }
    std::cout << std::endl << std::endl;
  }


}

int main(int argc, char** argv)
{

    // prepare NN
    std::string TestNeuralNetworkPath;
    if (argc > 1) {
      TestNeuralNetworkPath = argv[1];
    } else {
      TestNeuralNetworkPath = "/home/pselabw1920/Documents/trainednetworks/DenseSmall.txt";
    }
    NeuralNetworkFacade NNFacade = NeuralNetworkFacade();
    NeuralNetworkAdapter network = NeuralNetworkAdapter(NNFacade.loadNeuralNetwork(TestNeuralNetworkPath));
    
    // Set Number of Testimages to calc accuracy
    int batchSize;
    if (argc > 2) {
      batchSize = std::stoi(argv[2]); 
      if (batchSize > 10000) batchSize = 10000;
    } else {
      batchSize = -1;
    }

    // Set Device/Calculationtype : OpenCL on CPU | C++ on CPU
    DeviceType type;
    if (argc > 3 && argv[3] == "OPENCL") {
      type = DeviceType::CPU;
    } else {
      type = DeviceType::CPP;
    }
    network.setMode(type);    

    // Creating Executor, Running inference on testImages
    Executor* executor = new Executor(&network);
    MNISTDataParser gen = MNISTDataParser(batchSize); //-1 gives all testimages in one batch
    std::cout << "RUNNING MNIST" << std::endl;
    TENSOR(float) MNISTInput = gen.parseTest();
    TENSOR(float) testLabels = gen.parseTestLabel();
    TENSOR(float) testOutput = executor->execute(MNISTInput);
    
    // Calculating Accuracy
    int numCorrect = 0;
    for (int i = 0; i < testLabels.size(); i++) {
      int maxPos = 0;
      int correctPos;
      for (int j = 0; j < 10; j++) {
        if (testOutput[i][0][0][j] > testOutput[i][0][0][maxPos]) maxPos = j;
        if (testLabels[i][0][0][j] == 1) correctPos = j;
      }
      if (maxPos == correctPos) numCorrect++;
    }
    std::cout << "TEST ACCURACY ON ALL MNIST TEST IMAGES IS: " << (numCorrect * 1.0f) / testLabels.size() << std::endl;


    return 1;
}
