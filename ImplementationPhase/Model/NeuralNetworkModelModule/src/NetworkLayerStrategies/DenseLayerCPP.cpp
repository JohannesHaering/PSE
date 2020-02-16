#include "DenseLayerCPP.hpp"
#include <vector>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

DenseLayerCPP::DenseLayerCPP(std::vector<std::vector<float>>* weights, std::vector<float>* bias, int* inputSize, int* outputSize) :
weights(weights),
bias(bias), 
inputSize(inputSize),
outputSize(ouputSize)
{}

TENSOR(float) DenseLayerCPP::forward(TENSOR(float) new_input)
{
    TENSOR(float) output = TENSOR(float)(new_input.size(), MATRIX_3D(float)(1, MATRIX_2D(float)(1, std::vector<float>*outputSize)));
    for (int batchIteration = 0; batchIteration < new_input.size(); batchIteration++) {
        output[batchIteration][0][0] = *bias;//deep copy?
        for (int i = 0; i < *inputSize; i++)
        {
            for (int j = 0; j < *outputSize; j++)
                output[batchIteration][0][0][j] += (*weights)[i][j] * net[batchIteration][0][0][i];
        }
    }
    std::cout << "finished dense forward" << std::endl;
    return output;
}

TENSOR(float) DenseLayerCPP::backprob(TENSOR(float) feedback, float learningRate)
{
    std::vector<std::vector<float>> new_weights = *weights;//deep copy?
    std::vector<float> new_bias = *bias; //deep copy?
    TENSOR(float) output = TENSOR(float)(feedback.size(), MATRIX_3D(float)(1, MATRIX_2D(float)(1, std::vector<float>*inputSize)));

    for (int batchIteration = 0; batchIteration < new_input.size(); batchIteration++) {
        //calc derivate for next Layers
        for (int input_i = 0; input_i < *inputSize; input_i++) {
            double update = 0;
            for (int output_j = 0; output_j < *outputSize; output_j++) {
                update += feedback[batchIteration][0][0][output_j] * (*weights)[input_i][output_j];
            }
            output[batchIteration][0][0][input_i] = update;
        }

        //update weights	
        double update;
        for (int input_i = 0; input_i < *inputSize; input_i++) {
            for (int output_j = 0; output_j < *outputSize; output_j++) {
                new_weights[input_i][output_j] -= (*net)[batchIteration][0][0][input_i] * feedback[batchIteration][0][0][output_j] * learningRate;
            }
        }

        //update bias
        for (int output_j = 0; output_j < (*weights)[0].size(); output_j++) {
            new_bias[output_j] -= feedback[batchIteration][0][0][output_j] * learningRate;
        }       
    }

    *weights = new_weights;
    *bias = new_bias;
    return output;
}
