#ifndef OPENVINO_H_
#define OPENVINO_H_

#include <ie_plugin_dispatcher.hpp>
#include "MatrixDefine.hpp"
class OpenVino
{
public:
    OpenVino();
    TENSOR(float) inference(std::vector<TENSOR(float)> net, InferenceEngine::CNNNetwork* network);
};

#endif // OPENVINO_H_
