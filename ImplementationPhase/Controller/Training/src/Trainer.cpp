#include "CompleteTrainer.hpp"
#include "ControllerFacade.hpp"
#include "NetworkLayer.hpp"
#include "NeuralNetworkAdapter.hpp"
#include <vector>
#include "Trainer.hpp"
#include "/home/pselabw1920/Documents/mnist/include/mnist/mnist_reader.hpp"
#include "NeuralNetworkFacade.hpp"


Trainer::Trainer(NeuralNetworkAdapter* neuralNetwork, float desiredPrecision, std::string trainData, int batchSize) : neuralNetwork(neuralNetwork), desiredPrecision(desiredPrecision), trainData(trainData), batchSize(batchSize), trainer(CompleteTrainer(neuralNetwork, 0.01f, batchSize))
{
    //trainer = CompleteTrainer(neuralNetwork, 0.01f, batchSize);  
    trainingAcc = std::vector<float>();
    testAcc = std::vector<float>();    
    //TODO somehow update this to use trainData string and replace trainData string by somewhat smarter
    loadDataset();
}

//Trainer::Trainer(NeuralNetworkAdapter* neuralNetwork, float desiredPrecision, std::string trainData)
Trainer::Trainer(NeuralNetworkAdapter* neuralNetwork, float desiredPrecision, std::string trainData) : Trainer(neuralNetwork, desiredPrecision, trainData, 16) {}


void Trainer::loadDataset()
{
	//TODO div img values by 128 (256?);
  std::string MNIST_DATA_LOCATION = "/home/pselabw1920/Documents/mnist";
	auto mnist_dataset = mnist::read_dataset<std::vector, std::vector, float, uint8_t>(MNIST_DATA_LOCATION);//TODO change uint8_t to float for img and labels. div img by 128 (256?);


    dataset_train_images = std::vector<std::vector<float>>(mnist_dataset.training_images.size());
    dataset_test_images  = std::vector<std::vector<float>>(mnist_dataset.test_images.size());
    dataset_train_labels = std::vector<std::vector<float>>(mnist_dataset.training_images.size());
    dataset_test_labels  = std::vector<std::vector<float>>(mnist_dataset.test_images.size());

    
    for (int i =0; i < mnist_dataset.training_images.size(); i++) {
        dataset_train_images[i] = mnist_dataset.training_images[i];
        dataset_train_labels[i].resize(10);
        for (int j = 0; j < 10; j++) 
                dataset_train_labels[i][j] = (mnist_dataset.training_labels[i] == j) ? 1.0f : 0.0f;
    }

    for (int i =0; i < mnist_dataset.test_images.size(); i++) {
        dataset_test_images[i] = mnist_dataset.test_images[i];
        dataset_test_labels[i].resize(10);
        for (int j = 0; j < 10; j++) 
                dataset_test_labels[i][j] = (mnist_dataset.test_labels[i] == j) ? 1.0f : 0.0f;
    }
    std::cout << "size dataset_test_labels: " << dataset_test_labels.size() << " " << dataset_test_labels[0].size() << std::endl;
}

void Trainer::startTraining()
{
    for(int i = 0; i < batchSize*5; i++)
    {
      trainer.forward(dataset_train_images[i]);
      trainer.train(dataset_train_labels[i]);

      /*if (i % 10 == 0){
        trainer.forward(dataset_test_images[i]);
        testAcc.push_back(trainer.calcCEError(dataset_test_labels[i]));
        ControllerFacade::getInstance()->newTrainStep(trainingAcc, testAcc);   
      }*/
    }
    NeuralNetworkFacade* facade = new NeuralNetworkFacade();
    facade->saveNeuralNetwork(neuralNetwork->getNeuralNetwork(), "/home/pselabw1920/Downloads/network.cfg");
}
