#include "DenseLayer.hpp"

DenseLayer::DenseLayer() : NetworkLayer(LayerType::DENSE) {}
DenseLayer::DenseLayer(std::string name, int* inputDimensions, MATRIX_2D(float) matrix) : NetworkLayer(name, inputDimensions, LayerType::DENSE), matrix(matrix) {}
void DenseLayer::setMatrix(MATRIX_2D(float) matrix)
{
  this->matrix = matrix;
}

MATRIX_2D(float) DenseLayer::getMatrix()
{
  return matrix;
}

int* DenseLayer::getTensorDimenssions() {
  return new int[4] {(int) matrix[0].size(), (int) matrix.size(), 0, 0};
}
