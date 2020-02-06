#include "DenseLayer.hpp"
#include <vector>

DenseLayer::DenseLayer() : NetworkLayer(LayerType::DENSE) {}

DenseLayer::DenseLayer(std::string name, int* inputDimensions, MATRIX_2D(float) matrix, std::vector<float> bias) : NetworkLayer(name, inputDimensions, LayerType::DENSE), matrix(matrix), bias(bias) {}

void DenseLayer::setMatrix(MATRIX_2D(float) matrix) { this->matrix = matrix; }

MATRIX_2D(float) DenseLayer::getMatrix() { return matrix; }

std::vector<float> DenseLayer::getBias() { return bias;  }

int* DenseLayer::getTensorDimensions() { return new int[4] {(int) matrix[0].size(), (int) matrix.size(), 0, 0}; }

