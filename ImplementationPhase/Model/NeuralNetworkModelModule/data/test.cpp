//#include "softmax_layer.h"
#include "fc_layer.h"
#include "fc_sm_layer.h"
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
	std::cout << " matrix printed " << std::endl;
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
	int max = 1;
	if (argc == 2) max = atoi(argv[1]);
	float learningRate = 0.1;
	srand (static_cast <unsigned> (time(0)));
	
	int inputSize = 2;
	int hiddenSize = 2;
	int outputSize = 2;
	if (argc == 3) hiddenSize = atoi(argv[2]);
	std::vector<float> input_in; //image input size
	std::vector<float> input_out;
	std::vector<float> hidden_out;
	std::vector<float> output_out; //softmax does not change size
	std::vector<float> feedback_sm;
	std::vector<float> feedback_hd;
	std::vector<int> labels; //one label per output

	std::vector<std::vector<float>> inputs = {{1,1},{0,0},{1,0},{0,1}};
	std::vector<int> labelVec = {1,0,0,1}; //uneven == class2

	//input works forward and backward
	fc_layer inLayer = fc_layer(inputSize, hiddenSize, learningRate);
	fc_layer hdLayer = fc_layer(hiddenSize, outputSize, learningRate);
	fc_sm_layer smLayer = fc_sm_layer(outputSize, outputSize, learningRate);
	
	inLayer.set_bias(std::vector<float>{0.1,0.1});
	hdLayer.set_bias(std::vector<float>{0.2,-0.1});
	smLayer.set_bias(std::vector<float>{0.1,0.0});
	inLayer.set_weights(std::vector<std::vector<float>>{{0.5,0.2},{0.1,0.2}});
	hdLayer.set_weights(std::vector<std::vector<float>>{{0.3,-0.1},{0.2,0.1}});
	smLayer.set_weights(std::vector<std::vector<float>>{{0.1,-0.2},{0.1,0.2}});
		

	std::cout << "init done" << std::endl;

	int DEBUG = 0;
	for (int counter = 0; counter < max; counter++)
	{
		std::cout << std::endl << "//////////////////////////////////////////" << std::endl << "starting new iteration" << std::endl;
	
		int i = rand() % inputs.size(); // 60k training examples
		i = counter;
		input_in = inputs[i%4];
		labels = (labelVec[i] == 1) ? std::vector<int>{0,1} : std::vector<int>{1,0};
		
		// inferencing	
		input_out = inLayer.fprop(input_in);
		hidden_out = hdLayer.fprop(input_out);
		output_out = smLayer.fprop(hidden_out);

		std::cout << std::endl <<  "printing in biase" << std::endl;
		print_biase(inLayer.get_biase());
		std::cout << std::endl <<  "printing in weights" << std::endl;
		print_weights(inLayer.get_weights());
		std::cout << std::endl <<  "printing in output" << std::endl;
		print_biase(input_out);
	
		std::cout << std::endl <<  "printing hd biase" << std::endl;
		print_biase(hdLayer.get_biase());
		std::cout << std::endl <<  "printing hd weights" << std::endl;
		print_weights(hdLayer.get_weights());
		std::cout << std::endl <<  "printing hd output" << std::endl;
		print_biase(hidden_out);
		std::cout << std::endl;

		std::cout << std::endl <<  "printing out biase" << std::endl;
		print_biase(smLayer.get_biase());
		std::cout << std::endl <<  "printing out weights" << std::endl;
		print_weights(smLayer.get_weights());
		std::cout << std::endl <<  "printing out output" << std::endl;
		print_biase(output_out);
		std::cout << std::endl;
		
	
	
		std::cout << "printing sm output ";
		print_biase(output_out);

		// start training
		feedback_sm = smLayer.bprop(labels, learningRate);
		feedback_hd = hdLayer.bprop(feedback_sm, learningRate);
		inLayer.bprop(feedback_hd, learningRate);

		std::cout << "printing sm feedback: " << std::endl;
		print_biase(feedback_sm);
		std::cout << "printing hd feedback: " << std::endl;
		print_biase(feedback_hd);
		

		std::cout << std::endl << "iteration: " << counter << " error: " << smLayer.calcCEError() << " correct: " << get_label(labels) << " " << std::endl;
		std::cout << std::endl;

	
		//analysis	
		/*
		std::cout << std::endl << "printing hd biase" << std::endl;
		print_biase(hdLayer.get_biase());
		std::cout << "printing error from output to hidden ";
		print_biase(feedback_sm);
		std::cout << "printing error from hidden to in ";
		print_biase(feedback_hd);
		*/

	}
	std::cout << "testing done" << std::endl;
	
	for (int counter = 0; counter < 4; counter++)
	{

		input_in = inputs[counter];
		std::cout << "test input: " << input_in[0] << input_in[1] << std::endl;//<< input_in[2] << input_in[3] << std::endl;
		labels = (labelVec[counter] == 1) ? std::vector<int>{0,1} : std::vector<int>{1,0};
		input_out = inLayer.fprop(input_in);
		hidden_out = hdLayer.fprop(input_out);
		output_out = smLayer.fprop(hidden_out);

		print_result(&output_out, &labels);
	}
	
	std::cout << "terminating" << std::endl;
}
