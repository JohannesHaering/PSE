#include "DenseLayerCPU.hpp"
#include "DenseLayerStrategy.hpp"
#include "MatrixDefine.hpp"
#include "MatrixMultiplication.hpp"
#include "DenseLayer.hpp"

#include <vector>
#include <iostream>

DenseLayerCPU::DenseLayerCPU(DenseLayer* layer, int inputSize, int outputSize) : layer(layer)
{
    this->inputSize = inputSize;
    this->outputSize = outputSize;
}

TENSOR(float) DenseLayerCPU::forward(TENSOR(float) input_data)
{
    TENSOR(float) output = TENSOR(float)(input_data.size(), MATRIX_3D(float)(1, MATRIX_2D(float)(1, std::vector<float>(outputSize))));
    for (int b = 0; b < input_data.size(); b++)
    {
      std::cout << "Start product" << std::endl;
        std::vector<std::vector<float>> product = MatrixMultiplication().multiply(layer->get_weights(), input_data[b][0]);
        for( int y = 0;  y < product.size(); y++)
        {
          std::cout << "After product " <<  product[y][0] << std::endl;
          output[b][0][0][y] = product[y][0] + (layer->get_biase())[y];
        }
    }

    return output;
}

TENSOR(float) DenseLayerCPU::backprob(TENSOR(float) updates) { }

TENSOR(float) DenseLayerCPU::backprob(TENSOR(float) updates, float learningRate, TENSOR(float) net)
{
    std::vector<std::vector<float>> new_weights = layer->get_weights();
    std::vector<float> new_bias = layer->get_biase();
	TENSOR(float) output = TENSOR(float)(updates.size(), MATRIX_3D(float)(1, MATRIX_2D(float)(1, std::vector<float>(inputSize))));

    std::vector<std::vector<float>> A = std::vector<std::vector<float>>{{1,2},{2, 4}};
    std::vector<std::vector<float>> B = std::vector<std::vector<float>>{{1, 2},{3,4}};

    for (int batchIteration = 0; batchIteration < net.size(); batchIteration++) {
        //calc derivate for next Layers
        for (int input_i = 0; input_i < inputSize; input_i++) {
            float update = 0;
            for (int output_j = 0; output_j < outputSize; output_j++) {
                update += updates[batchIteration][0][0][output_j] * (layer->get_weights())[input_i][output_j];
            }
            output[batchIteration][0][0][input_i] = update;
        }

        //update weights	
        float update = 0;
        for (int input_i = 0; input_i < inputSize; input_i++) {
            for (int output_j = 0; output_j < outputSize; output_j++) {
                new_weights[input_i][output_j] -= (net)[batchIteration][0][0][input_i] * updates[batchIteration][0][0][output_j] * learningRate;
            }
        }

        //update bias
        for (int output_j = 0; output_j < (layer->get_biase()).size(); output_j++) {
            new_bias[output_j] -= updates[batchIteration][0][0][output_j] * learningRate;
        }       
    }

    layer->set_weights(new_weights);
    layer->set_bias(new_bias);

    return output;
}
