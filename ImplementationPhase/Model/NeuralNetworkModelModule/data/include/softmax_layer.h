#ifndef SOFTMAX_H
#define SOFTMAX_H
#include <math.h>
#include <vector>

class softmax_layer 
{
	private:
		int length;
		float error;
		std::vector<float> input;
		std::vector<float> weightedSums;
		std::vector<float> output;
		std::vector<int> labels;
		std::vector<float> backpropRes;
	
	public:
		softmax_layer();
		std::vector<float> fprop (std::vector<float> input);
		float get_error();
		float calcCEError(); //uses labels, output and length 
		std::vector<float> bprop (std::vector<int> labels); 

};
#endif
