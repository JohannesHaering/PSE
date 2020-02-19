#ifndef MATRIXMULTIPLICATIONCPU_H_
#define MATRIXMULTIPLICATIONCPU_H_

#include <vector>
#include <CL/cl.hpp>

class MatrixMultiplicationCPU {
public:
    std::vector<std::vector<float>> mult(std::vector<std::vector<float>> iA, std::vector<std::vector<float>> iB);
};
#endif