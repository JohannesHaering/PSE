#include "DenseLayer.hpp"

DenseLayer::DenseLayer() : NetworkLayer(LayerType::DENSE) {}

DenseLayer::DenseLayer(std::string name, int* inputDimensions, MATRIX_2D(double) matrix) : NetworkLayer(name, inputDimensions, LayerType::DENSE), matrix(matrix) {}

void DenseLayer::setMatrix(MATRIX_2D(double) matrix) { this->matrix = matrix; }

MATRIX_2D(double) DenseLayer::getMatrix() { return matrix; }

int* DenseLayer::getTensorDimensions() { return new int[4] {(int) matrix[0].size(), (int) matrix.size(), 0, 0}; }
