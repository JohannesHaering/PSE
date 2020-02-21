#ifndef MATRIX_DEFINE_H_
#define MATRIX_DEFINE_H_

#include <vector>

#define TENSOR(TYPE) std::vector<std::vector<std::vector<std::vector<TYPE>>>>
#define MATRIX_3D(TYPE) std::vector<std::vector<std::vector<TYPE>>>
#define MATRIX_2D(TYPE) std::vector<std::vector<TYPE>>

#endif
