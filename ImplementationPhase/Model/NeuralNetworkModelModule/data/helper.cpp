//#ifndef HELPER_H
//#define HELPER_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>

#include "helper.h"
#include "mnist/include/mnist/mnist_reader.hpp"
int image_empty(float* img) 
{
	for (int i = 0; i < 784; i++) if (img[i] != 0) return 0;
	return 1;
}

void print_image(float* img)
{
	for (int i = 0; i < 784; i++) {
		std::cout << img[i] << " " ;
		if (i % 28 == 0) std::cout << std::endl;
	}
}

void print_weights(std::vector<std::vector<float>> weights)
{
	int limit = 10;
	int countera = 0;
	for (int i = 10; i < weights.size(); i++)
	{
		std::vector<float> list = weights[i];
		if (countera++ > limit) break;
		int counterb = 0;
		for (int j = 10; j < list.size(); j++)
		{
			if (counterb++ > limit) break;
			std::cout << list[j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void print_result(int outputSize, float *output_out, int *labels) 
{
	for (int i = 0; i < outputSize; i++) std::cout << " output is: " << output_out[i] << " should be: " << labels[i] << std::endl;
	std::cout << "____________" << std::endl;
}

void update_input(float *input_in, int inputSize, auto images, int counter)
{
	for (int i = 0; i < inputSize; i++)  //input
	{
		input_in[i] = float(images[counter][i]) / 255.0;
	}
}

void update_labels(int *labels, int outputSize, auto dataset_labels, int counter)
{
	for (int i = 0; i < outputSize; i++) //random labels
		labels[i] = (dataset_labels[counter] == i) ? 1 : 0;
}

//#endif
