#include "Executor.hpp"
#include "ControllerFacade.hpp"
#include "NetworkLayer.hpp"
#include "NeuralNetworkAdapter.hpp"
#include <vector>
#include "Executor.hpp"
#include "/home/pselabw1920/Documents/mnist/include/mnist/mnist_reader.hpp"



Executor::Executor(NeuralNetworkAdapter* neuralNetwork, std::vector<std::string> inputData) : neuralNetwork(neuralNetwork), inputData(inputData) 
{
      
    
    //TODO somehow update this to use trainData string and replace trainData string by somewhat smarter
    loadDataset();

}

void Executor::loadDataset()
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
}
