#include <math.h>
#include "softmax_layer.h"
#include <iostream>
#include <vector>
#include <algorithm>

softmax_layer::softmax_layer() {}
	

std::vector<float> softmax_layer::fprop (std::vector<float> input) 
{
	length = input.size();
	output = std::vector<float>(length);
	float sum = 0;
	for (int i = 0; i < length; i++) {sum += exp(input[i]); std::cout << input[i] << " ";}
	std::cout << "printed sm input. sum(e^x) = " << sum << std::endl;
	for (int i = 0; i < length; i++) 
		output[i] = exp(input[i]) / sum;// + bias[i];// maybe remove it?
	return output;
}

float softmax_layer::get_error() {return error;}

float softmax_layer::calcCEError() //uses labels, output and currentSize 
{
	error = 0;
	for (int i = 0; i < length; i++) error -= labels[i] * log(output[i]);
	return error;
}

std::vector<float> softmax_layer::bprop (std::vector<int> new_labels) // uses output, currentSize and error
{
	labels = std::vector<int>(new_labels);
	backpropRes = std::vector<float>(length);
	for (int i = 0; i < length; i++) {
		backpropRes[i] = output[i] - labels[i];
	}
	calcCEError();
	
	return backpropRes;
}
