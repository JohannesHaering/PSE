#include "DenseLayerCPU.hpp"
#include "DenseLayerStrategy.hpp"
#include "MatrixDefine.hpp"
#include "MatrixMultiplicationCPU.hpp"
#include "VectorAdditionCPU.hpp"

#include <vector>

DenseLayerCPU::DenseLayerCPU(std::vector<std::vector<float>> *weights, std::vector<float> *bias, int *inputSize, int *outputSize)
{
    this->weights = weights;
    this->bias = bias;
    this->inputSize = inputSize;
    this->outputSize = outputSize;
}

MatrixDefine::TENSOR(float) DenseLayerCPU::forward(MatrixDefine::TENSOR(float) input_data)
{
    MatrixDefine::TENSOR(float) output = MatrixDefine::TENSOR(float)[new_input.size()][0][0][*outputSize];
    for (int b = 0; b < input_data.size(); b++)
    {
        std::vector<std::vector<float>> product = MatrixMultiplicationCPU::mult(*weights, inputData[b][0]);
        output[b][0][0] = VectorAdditionCPU::addVector(product[0], *bias);
    }

    return output;
}

MatrixDefine::TENSOR(float) DenseLayerCPU::backprob(MatrixDefine::TENSOR(float) feedback, MatrixDefine::TENSOR(float) *net, float learningrate)
{
    std::vector<std::vector<float>> new_weights = *weights;
    std::vector<float> new_bias = *bias;
    MatrixDefine::TENSOR(float) output = MatrixDefine::TENSOR(float)[feedback.size()][0][0][*inputSize];

    for (int batchIteration = 0; batchIteration < new_input.size(); batchIteration++) {
        //calc derivate for next Layers
        for (int input_i = 0; input_i < *inputSize; input_i++) {
            float update = 0;
            for (int output_j = 0; output_j < *outputSize; output_j++) {
                update += feedback[batchIteration][0][0][output_j] * (*weights)[input_i][output_j];
            }
            output[batchIteration][0][0][input_i] = update;
        }

        //update weights	
        float update = 0;
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

    weights = *new_weights;
    bias = *new_bias;

    return output;
}