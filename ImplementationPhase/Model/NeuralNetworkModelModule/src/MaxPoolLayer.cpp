#include "MaxPoolLayer.hpp"
#include "MatrixDefine.hpp"
#include "MaxPoolLayerASIC.hpp"

MaxPoolLayer::MaxPoolLayer() {
    layerType = LayerType::POLLING;
}

TENSOR(float) MaxPoolLayer::forward(TENSOR(float) input) {
    
    maxValueMap = std::vector<TENSOR(float)>(input.size(), TENSOR(float)(input[0].size(), MATRIX_3D(float)(input[0][0].size() - filterwidth + 1, MATRIX_2D(float)(input[0][0][0].size() - filterwidth + 1, std::vector<float>(filterwidth * filterwidth, 0)))));
    output = TENSOR(float)(input.size(), MATRIX_3D(float)(input[0].size(), MATRIX_2D(float)(input[0][0].size() - filterwidth + 1, std::vector<float>(input[0][0][0].size() - filterwidth + 1, 0))));
    for (int b = 0; b < maxValueMap.size(); b++) {
        for (int z = 0; z < maxValueMap[0].size(); z++) {
            for (int y = 0; y < maxValueMap[0][0].size(); y++) {
                for (int x = 0; x < maxValueMap[0][0][0].size(); x++) {
                    
                    float max = 0;

                    for (int i = 0; i < filterwidth; i++) {
                        for (int j = 0; j < filterwidth; j++) {
                            if (input[b][z][y + j][x + i] > max) {
                                max = input[b][z][y + j][x + i];
                            }
                        }
                    }

                    output[b][z][y][x] = max;

                    for (int i = 0; i < filterwidth; i++) {
                        for (int j = 0; j < filterwidth; j++) {
                            if (input[b][z][y + j][x + i] == max) {
                                maxValueMap[b][z][y][x][i + filterwidth * j] = 1;
                            }
                        }
                    }         
                }
            }
        }
    }

    return output;

}

TENSOR(float) MaxPoolLayer::backprob(TENSOR(float) feedback, float learningRate) {

    TENSOR(float) output = TENSOR(float)(feedback.size(), MATRIX_3D(float)(feedback[0].size(), MATRIX_2D(float)(feedback[0][0].size() + filterwidth - 1, std::vector<float>(feedback[0][0][0].size() + filterwidth - 1, 0))));
   
    for (int b = 0; b < feedback.size(); b++) {
        for (int z = 0; z < feedback[0].size(); z++) {
            for (int y = 0; y < feedback[0][0].size(); y++) {
                for (int x = 0; x < feedback[0][0][0].size(); x++) {

                    int sum = 0;
                    for (int i = 0; i < maxValueMap[b][z][y][x].size(); i++) {
                        sum += maxValueMap[b][z][y][x][i];
                    }

                    for (int i = 0; i < filterwidth; i++) {
                        for (int j = 0; j < filterwidth; j++) {
                            output[b][z][y + j][x + i] += feedback[b][z][y][x] * maxValueMap[b][z][y][x][i + filterwidth * j] / sum;
                        }
                    }            
                }
            }
        }
    }

    return output;
}

void MaxPoolLayer::setMode(DeviceType device, cl_int deviceID) {
    switch(device) {
        case DeviceType::CPP :
            break;
        case DeviceType::ASIC :
            layerStrategy = new MaxPoolLayerASIC();
            break;
        case DeviceType::CPU :
            break;
    }
}