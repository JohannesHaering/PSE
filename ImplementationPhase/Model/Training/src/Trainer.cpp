#include "CompleteTrainer.hpp"
#include "NetworkLayer.hpp"
#include "NeuralNetworkAdapter.hpp"
#include <vector>
#include "Trainer.hpp"
#include "/home/pselabw1920/Documents/mnist/include/mnist/mnist_reader.hpp"



Trainer::Trainer(NeuralNetworkAdapter* neuralNetwork, float desiredPrecision, std::string trainData) : neuralNetwork(neuralNetwork), desiredPrecision(desiredPrecision), trainData(trainData), trainer(CompleteTrainer(neuralNetwork, 0.01f)) 
{
    trainer = CompleteTrainer(neuralNetwork, 0.01f);  
    
    //TODO somehow update this to use trainData string and replace trainData string by somewhat smarter
    loadDataset();

}

void Trainer::loadDataset()
{
	//TODO div img values by 128 (256?);
    std::string MNIST_DATA_LOCATION = "/home/pselabw1920/Documents/mnist";
	auto mnist_dataset = mnist::read_dataset<std::vector, std::vector, float, uint8_t>(MNIST_DATA_LOCATION);//TODO change uint8_t to float for img and labels. div img by 128 (256?);

    dataset_train_images = std::vector<std::vector<float>>(mnist_dataset.training_images.size());
    dataset_test_images  = std::vector<std::vector<float>>(mnist_dataset.test_images.size());
    
    for (int i =0; i < mnist_dataset.training_images.size(); i++) {
            dataset_train_images[i] = mnist_dataset.training_images[i];
            for (int j = 0; j < 10; j++)
                dataset_train_labels[j] = float(mnist_dataset.training_labels[j]);

    }
    for (int i =0; i < mnist_dataset.test_images.size(); i++) {
        dataset_test_images[i] = mnist_dataset.test_images[i];
        for(int j = 0; j < 10; j++)
            dataset_test_labels[j] = float(mnist_dataset.test_labels[j]);
    }
}

void Trainer::startTraining()
{
    for(int i = 0; i < dataset_train_images.size(); i++)
    {
        trainer.forward(dataset_train_images[i]);
        trainer.train(dataset_test_images[i]);

        if (i % 100 == 0) testAcc();
    }
    
}

float Trainer::testAcc()
{
    return 42.0;
}






/*
CompleteTrainer::CompleteTrainer(NeuralNetworkAdapter* neuralNetwork, float learningRate) : neuralNetwork(neuralNetwork), learningRate(learningRate) {}


void CompleteTrainer::train(std::vector<float> target)
{
	std::vector<float> output;
	std::vector<float> tmp = target;
	NetworkLayer* lastlayer = neuralNetwork->getLastLayer();

	for (auto layer = neuralNetwork->getFirstLayer(); layer != lastlayer; layer = neuralNetwork->getNextLayer()) 
	{
		output = layer->backprob(target, learningRate);
		tmp = output;
	}
	learningRate *= 0.99;
}


std::vector<float> CompleteTrainer::forward(std::vector<float> input)
{
	std::vector<float> tmp = input;
	std::vector<float> output;
	NetworkLayer* lastlayer = neuralNetwork->getLastLayer();

	for (NetworkLayer* layer = neuralNetwork->getFirstLayer(); layer != lastlayer; layer = neuralNetwork->getNextLayer())
	{
		output = layer->forward(input);
		tmp = output;
	}
	return output;
}*/
