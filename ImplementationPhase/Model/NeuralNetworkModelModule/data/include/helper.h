#ifndef HELPER_H
#define HELPER_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>

#include "../mnist/include/mnist/mnist_reader.hpp"
int image_empty(float* img);

void print_image(float* img);

void print_weights(std::vector<std::vector<float>> weights);

void print_result(int outputSize, float *output_out, int *labels);

void update_input(float *input_in, int inputSize, auto images, int counter);

void update_labels(int *labels, int outputSize, auto dataset_labels, int counter);

#endif
