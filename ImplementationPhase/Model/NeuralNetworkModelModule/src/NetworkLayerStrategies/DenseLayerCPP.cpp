#include "DenseLayerCPP.hpp"
#include <vector>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

DenseLayerCPP::DenseLayerCPP(DenseLayer* layer, int inputSize, int outputSize) : 
layer(layer)
inputSize(inputSize),
outputSize(ouputSize)
{}

TENSOR(float) DenseLayerCPP::forward(TENSOR(float) net)
{
    MATRIX_2D(float) weights = layer->get_weights();
    std::vector<float> bias = layer->get_biase();
    TENSOR(float) output = TENSOR(float)(new_input.size(), MATRIX_3D(float)(1, MATRIX_2D(float)(1, std::vector<float>outputSize)));
    for (int batchIteration = 0; batchIteration < new_input.size(); batchIteration++) {
        output[batchIteration][0][0] = bias;//deep copy?
        for (int i = 0; i < inputSize; i++)
        {
            for (int j = 0; j < outputSize; j++)
                output[batchIteration][0][0][j] += weights[i][j] * net[batchIteration][0][0][i];
        }
    }
    std::cout << "finished dense forward" << std::endl;
    return output;
}

TENSOR(float) DenseLayerCPP::backprob(TENSOR(float) feedback, float learningRate, TENSOR(float) net)
{
    std::vector<std::vector<float>> new_weights = layer.get_weights();//deep copy?
    std::vector<float> new_bias = layer.get_biase(); //deep copy?
    TENSOR(float) output = TENSOR(float)(feedback.size(), MATRIX_3D(float)(1, MATRIX_2D(float)(1, std::vector<float>inputSize)));

    for (int batchIteration = 0; batchIteration < new_input.size(); batchIteration++) {
        //calc derivate for next Layers
        for (int input_i = 0; input_i < inputSize; input_i++) {
            double update = 0;
            for (int output_j = 0; output_j < outputSize; output_j++) {
                update += feedback[batchIteration][0][0][output_j] * weights[input_i][output_j];
            }
            output[batchIteration][0][0][input_i] = update;
        }

        //update weights	
        double update;
        for (int input_i = 0; input_i < inputSize; input_i++) {
            for (int output_j = 0; output_j < outputSize; output_j++) {
                new_weights[input_i][output_j] -= net[batchIteration][0][0][input_i] * feedback[batchIteration][0][0][output_j] * learningRate;
            }
        }

        //update bias
        for (int output_j = 0; output_j < weights[0].size(); output_j++) {
            new_bias[output_j] -= feedback[batchIteration][0][0][output_j] * learningRate;
        }       
    }

    layer->set_weights(new_weights);
    layer->set_bias(new_bias);
    return output;
}
