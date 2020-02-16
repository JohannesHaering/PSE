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

MatrixDefine::TENSOR(float) DenseLayerCPP::forward(MatrixDefine::TENSOR new_input)
{
    MatrixDefine::TENSOR(float) output = MatrixDefine::TENSOR(float)[new_input.size()][0][0][*outputSize];
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

MatrixDefine::TENSOR(float) DenseLayerCPP::backprob(MatrixDefine::TENSOR(float) feedback, float learningrate)
{
    std::vector<std::vector<float>> new_weights = *weights;//deep copy?
    std::vector<float> new_bias = *bias; //deep copy?
    MatrixDefine::TENSOR(float) output = MatrixDefine::TENSOR(float)[feedback.size()][0][0][*inputSize];

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
