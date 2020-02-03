#include "fc_sm_layer.h"
#include "fc_layer.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <random>
//#include "helper.h"
#include "mnist/include/mnist/mnist_reader.hpp"

int image_empty(std::vector<float> img) 
{
	for (int i = 0; i < 784; i++) if (img[i] != 0) return 0;
	return 1;
}

void print_image(std::vector<float> img)
{
	for (int i = 0; i < 784; i++) {
		if (i % 28 == 0 && i > 0) std::cout << std::endl;
		std::cout << std::setprecision(1) << img[i] << " " ;
	}
	std::cout << std::endl << "printed image" << std::endl;
}

void print_biase(std::vector<float> biase)
{
	for (auto& bias : biase) std::cout << bias << " ";
	std::cout << std::endl;
}

void print_weights(std::vector<std::vector<float>> weights)
{
	std::cout << "printing weight matrix of size: " << weights.size() << "," << weights[0].size() << std::endl;
	int limit = 10;
	int countera = 0;
	for (int i = 0; i < weights.size(); i++)
	{
		if (countera++ > limit) break;
		int counterb = 0;
		for (int j = 0; j < weights[i].size(); j++)
		{
			if (counterb++ > limit) break;
			std::cout << weights[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int get_label(std::vector<int> labels) 
{
	for (int i = 0; i < labels.size(); i++) {
		if (labels[i] == 1) return i;
	}
}

void print_label(std::vector<int> labels)
{
	std::cout << "Image label is: " << get_label(labels) << std::endl;
}

void print_result(std::vector<float> *output_out, std::vector<int> *labels) 
{
	std::cout << "printing" << output_out->size() << " elements." << std::endl;
	for (int i = 0; i < output_out->size(); i++) std::cout << " output is: " << (*output_out)[i] << " should be: " << (*labels)[i] << std::endl;
	std::cout << "____________" << std::endl;
}

void update_input(std::vector<float> *input_in, auto images, int counter)
{
	for (int i = 0; i < input_in->size(); i++)  //input
	{
		(*input_in)[i] = float(images[counter][i]) /255.0; // test without? / 255.0;
	}
	//print_image(*input_in);
}

void update_labels(std::vector<int> *labels, auto dataset_labels, int counter)
{
	for (int i = 0; i < labels->size(); i++) 
		(*labels)[i] = (dataset_labels[counter] == i) ? 1 : 0;
}


int main(int argc, char** argv) 
{
	char dataset = 'E'; //MNIST, EVEN, EVEN_LARGE;
	int max = 100;
	if (argc == 2) max = atoi(argv[1]);
	float learningRate = 0.01;
	srand (static_cast <unsigned> (time(0)));
	
	int inputSize = 28*28;
	int hiddenSize = 300;
	int outputSize = 10;
	std::vector<float> input_in; //image input size
	std::vector<float> input_out;
	std::vector<float> hidden_out; //softmax does not change size
	std::vector<float> output_out; //softmax does not change size
	std::vector<float> feedback_sm;
	std::vector<float> feedback_hd;
	std::vector<int> labels; //one label per output
	
	std::vector<std::vector<uint8_t>> dataset_train_images;
	std::vector<uint8_t> dataset_train_labels;
	std::vector<std::vector<uint8_t>> dataset_test_images;
	std::vector<uint8_t> dataset_test_labels;
        
	int num_training_examples;
	int num_test_examples;

	std::string MNIST_DATA_LOCATION = "/home/zusez4/Documents/manu_NN/data/mnist/";	
	auto mnist_dataset = mnist::read_dataset<std::vector, std::vector, uint8_t, uint8_t>(MNIST_DATA_LOCATION);
	
	switch(dataset) {
		case 'M':
			dataset_train_images.resize(mnist_dataset.training_images.size());
			dataset_test_images.resize(mnist_dataset.test_images.size());
			dataset_train_labels = mnist_dataset.training_labels;
			dataset_test_labels = mnist_dataset.test_labels;
			for (int i =0; i < mnist_dataset.training_images.size(); i++) dataset_train_images[0] = mnist_dataset.training_images[0];
			for (int i =0; i < mnist_dataset.test_images.size(); i++) dataset_test_images[0] = mnist_dataset.test_images[0];
			inputSize = 28*28;
			hiddenSize = 300;
			outputSize = 10;
			break;

		case 'E':
			/*
			inLayer.set_bias(std::vector<float>{0.1,0.1});
			hdLayer.set_bias(std::vector<float>{0.2,-0.1});
			smLayer.set_bias(std::vector<float>{0.1,0.0});
			inLayer.set_weights(std::vector<std::vector<float>>{{0.5,0.2},{0.1,0.2}});
			hdLayer.set_weights(std::vector<std::vector<float>>{{0.3,-0.1},{0.2,0.1}});
			smLayer.set_weights(std::vector<std::vector<float>>{{0.1,-0.2},{0.1,0.2}});
			*/
			dataset_train_images = std::vector<std::vector<uint8_t>>{{0,0},{0,1},{1,0},{1,1}};//even,uneven,even,uneven
			dataset_train_labels = std::vector<uint8_t>{1,0,1,0};
			dataset_test_images = dataset_train_images;//they are not to many more cases... 
			dataset_test_labels = dataset_train_labels;
			inputSize = 2;
			hiddenSize = 2;
			outputSize = 2;
			break;

		case 'L':
			dataset_train_images = std::vector<std::vector<uint8_t>>{{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,1,0,0},\
						{1,0,0,0},{0,0,1,1},{0,1,0,1},{1,0,0,1},\
						{0,1,1,0},{1,0,1,0},{1,1,0,0},{0,1,1,1},\
						{1,0,1,1},{1,1,0,1},{1,1,1,0},{1,1,1,1}};
			dataset_train_labels = std::vector<uint8_t>{1,0,1,1,1,0,0,0,\
						1,1,1,0,0,0,1,0};
			dataset_test_images = dataset_train_images;

			dataset_test_labels = dataset_train_labels;
			inputSize = 4;
			hiddenSize = 20;
			outputSize = 2;
			break;

		default:
			std::cout << "dataset name not recognized, please restart and try again!" << std::endl;
			return -1;
	}	

	input_in.resize(inputSize);
	labels.resize(outputSize);
	num_training_examples = dataset_train_images.size();
	num_test_examples = dataset_test_images.size();
	std::cout << "Nbr of training images = " << dataset_train_images.size() << std::endl;
	std::cout << "Nbr of training labels = " << dataset_train_labels.size() << std::endl;
	std::cout << "Nbr of test images = " << dataset_test_images.size() << std::endl;
	std::cout << "Nbr of test labels = " << dataset_test_labels.size() << std::endl;
	
	//input works forward and backward
	fc_layer inLayer = fc_layer(inputSize, hiddenSize, learningRate);
	fc_layer hdLayer = fc_layer(hiddenSize, outputSize, learningRate);
	fc_sm_layer smLayer = fc_sm_layer(outputSize, outputSize, learningRate);
	
	

	for (int counter = 0; counter < max; counter++)
	{
		int training_example = rand() % num_training_examples; // 60k training examples
		update_input(&input_in, dataset_train_images, training_example); //last vals should be counter
		update_labels(&labels, dataset_train_labels, training_example);
	
		// inferencing	
		input_out = inLayer.fprop(input_in);
		hidden_out = hdLayer.fprop(input_out);
		output_out = smLayer.fprop(hidden_out);

		// start training
		feedback_sm = smLayer.bprop(labels);
		feedback_hd = hdLayer.bprop(feedback_sm);
		inLayer.bprop(feedback_hd);
		std::cout << "iteration: " << counter << " example" << training_example << " error: " << smLayer.calcCEError();
		std::cout << " correct: " << get_label(labels) << " " << std::endl << std::endl;

		//analysis	
		if (counter == max-1) {
			std::cout << std::endl << "printing hd biase" << std::endl;
			print_biase(hdLayer.get_biase());
			std::cout << "printing error from output to hidden ";
			print_biase(feedback_sm);
			std::cout << "printing hd output ";
			print_biase(hidden_out);
			std::cout << std::endl <<  "printing in biase" << std::endl;
			print_biase(inLayer.get_biase());
			std::cout << "printing error from hidden to in ";
			print_biase(feedback_hd);
		}

	}
	std::cout << "testing done" << std::endl;
		
	for (int counter = 0; counter < 4; counter++)
	{
		update_input(&input_in, dataset_test_images, counter);
		update_labels(&labels, dataset_test_labels, counter);

		input_out = inLayer.fprop(input_in);
		hidden_out = hdLayer.fprop(input_out);
		output_out = smLayer.fprop(hidden_out);

		print_result(&output_out, &labels);
	}
	
	std::cout << "terminating" << std::endl;
}
