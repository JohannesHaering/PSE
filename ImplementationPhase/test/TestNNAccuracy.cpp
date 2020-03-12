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
#include <chrono>


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
    NeuralNetworkAdapter networkCPP = NeuralNetworkAdapter(NNFacade.loadNeuralNetwork(TestNeuralNetworkPath));
    NeuralNetworkAdapter networkOpenCL = NeuralNetworkAdapter(NNFacade.loadNeuralNetwork(TestNeuralNetworkPath));
    
    // Set Number of Testimages to calc accuracy
    int batchSize;
    if (argc > 2) {
      batchSize = std::stoi(argv[2]); 
      if (batchSize > 10000) batchSize = 10000;
    } else {
      batchSize = -1; //-1 gives all testimages
    }
    MNISTDataParser gen = MNISTDataParser(batchSize);

    // Set Device/Calculationtype : OpenCL on CPU | C++ on CPU
    DeviceType CPP = DeviceType::CPP;
    DeviceType OpenCL = DeviceType::CPU;
    networkCPP.setMode(CPP);    
    networkOpenCL.setMode(OpenCL);

    // Creating Executor, Running inference on testImages
    Executor* OpenCLExecutor = new Executor(&networkOpenCL);
    Executor* CPPExecutor = new Executor(&networkCPP);
    std::cout << "RUNNING MNIST" << std::endl;
    TENSOR(float) MNISTInput = gen.parseTest();
    TENSOR(float) testLabels = gen.parseTestLabel();
    TENSOR(float) testOutput;
    
    auto startCL = std::chrono::high_resolution_clock::now();
    testOutput = OpenCLExecutor->execute(MNISTInput);
    auto finishCL = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedCL = finishCL - startCL;
    std::cout << "Elapsed time OpenCL: " << elapsedCL.count() << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    testOutput = CPPExecutor->execute(MNISTInput);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time c++: " << elapsed.count() << std::endl;


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
