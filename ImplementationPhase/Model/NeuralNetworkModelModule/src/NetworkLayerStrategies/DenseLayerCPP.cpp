#include "DenseLayerCPP.hpp"
#include "DenseLayer.hpp"
#include "MatrixDefine.hpp"
#include <vector>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

DenseLayerCPP::DenseLayerCPP(DenseLayer* layer, int inputSize, int outputSize) : 
layer(layer)
{
  this->inputSize = inputSize;
  this->outputSize = outputSize;
}

TENSOR(float) DenseLayerCPP::forward(TENSOR(float) input_data)
{
    MATRIX_2D(float) weights = layer->get_weights();
    std::vector<float> bias = layer->get_biase();
    TENSOR(float) output = TENSOR(float)(input_data.size(), MATRIX_3D(float)(1, MATRIX_2D(float)(1, std::vector<float>(outputSize))));
    for (int batchIteration = 0; batchIteration < input_data.size(); batchIteration++) {
        output[batchIteration][0][0] = bias;//deep copy?
        for (int i = 0; i < inputSize; i++)
        {
            for (int j = 0; j < outputSize; j++)
                output[batchIteration][0][0][j] += weights[i][j] * input_data[batchIteration][0][0][i];
        }
    }
    std::cout << "finished dense forward" << std::endl;
    return output;
}

TENSOR(float) DenseLayerCPP::backprob(TENSOR(float) updates, float learningRate, TENSOR(float) net)
{
    std::vector<std::vector<float>> weights = layer->get_weights();
    std::vector<std::vector<float>> new_weights = layer->get_weights();//deep copy?
    std::vector<float> new_bias = layer->get_biase(); //deep copy?
    TENSOR(float) output = TENSOR(float)(updates.size(), MATRIX_3D(float)(1, MATRIX_2D(float)(1, std::vector<float>(inputSize))));

    for (int batchIteration = 0; batchIteration < updates.size(); batchIteration++) {
        //calc derivate for next Layers
        for (int input_i = 0; input_i < inputSize; input_i++) {
            double update = 0;
            for (int output_j = 0; output_j < outputSize; output_j++) {
                update += updates[batchIteration][0][0][output_j] * weights[input_i][output_j];
            }
            output[batchIteration][0][0][input_i] = update;
        }

        //update weights	
        double update;
        for (int input_i = 0; input_i < inputSize; input_i++) {
            for (int output_j = 0; output_j < outputSize; output_j++) {
                new_weights[input_i][output_j] -= net[batchIteration][0][0][input_i] * updates[batchIteration][0][0][output_j] * learningRate;
            }
        }

        //update bias
        for (int output_j = 0; output_j < weights[0].size(); output_j++) {
            new_bias[output_j] -= updates[batchIteration][0][0][output_j] * learningRate;
        }       
    }

    layer->set_weights(new_weights);
    layer->set_bias(new_bias);
    return output;
}

TENSOR(float) DenseLayerCPP::backprob(TENSOR(float) updates){}
