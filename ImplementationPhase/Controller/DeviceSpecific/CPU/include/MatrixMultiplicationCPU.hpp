#ifndef MATRIXMULTIPLICATIONCPU_H_
#define MATRIXMULTIPLICATIONCPU_H_

#include <vector>

class MatrixMultiplicationCPU {
public:
    std::vector<std::vector<float>>* mult(std::vector<std::vector<float>> A, std::vector<std::vector<float>> B);
};
#endif