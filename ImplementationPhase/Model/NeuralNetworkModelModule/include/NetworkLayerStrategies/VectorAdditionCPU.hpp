#ifndef VECTORADDITION_H_
#define VECTORADDITION_H_

#include <vector>

class VectorAdditionCPU {
public:
    static std::vector<float> addVector(std::vector<float> a, std::vector<float> b);
};
#endif