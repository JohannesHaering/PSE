#include "FlattenLayer.hpp"
#include <iostream>

FlattenLayer::FlattenLayer() {
    layerType = LayerType::FLATTEN;
}

TENSOR(float) FlattenLayer::forward(TENSOR(float) input) {
    oldz = input[0].size();
    oldy = input[0][0].size();
    oldx = input[0][0][0].size();

    TENSOR(float) output = TENSOR(float)(input.size(), MATRIX_3D(float)(1, MATRIX_2D(float)(1, std::vector<float>(oldz * oldy * oldx))));

    for (int b = 0; b < input.size(); b++) {
        for (int z = 0; z < oldz; z++) {
            for (int y = 0; y < oldy; y++) {
                for (int x = 0; x < oldx; x++) {
                    output[b][0][0][x + y * oldx + z * oldx * oldy] = input[b][z][y][x];
                }
            }
        }
    }

    return output;
}


TENSOR(float) FlattenLayer::backprob(TENSOR(float) updates, float learningrate) {

    TENSOR(float) feedback = TENSOR(float)(updates.size(), MATRIX_3D(float)(oldz, MATRIX_2D(float)(oldy, std::vector<float>(oldx))));
    
    for (int b = 0; b < updates.size(); b++) {
        for (int z = 0; z < oldz; z++) {
            for (int y = 0; y < oldy; y++) {
                for (int x = 0; x < oldx; x++) {
                    feedback[b][z][y][x] = updates[b][0][0][x + y * oldx + z * oldx * oldy];
                }
            }
        }
    }

    return feedback;
}