#include "ReLuLayerASIC.hpp"
#include "MatrixDefine.hpp"
#include <vector>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

#include "ngraph/opsets/opset.hpp"
#include "ngraph/opsets/opset1.hpp"

using namespace ngraph;

ReLuLayerASIC::ReLuLayerASIC(){

}

TENSOR(float) ReLuLayerASIC::forward(TENSOR(float) net)
{
    auto arg0 = make_shared<opset1::Parameter>(Precision::FP32, Layout::ANY, Shape{7});
    auto relu0 = make_shared<opset1::ReLU>(arg0);
    // Run shape inference on the nodes
    NodeVector ops{relu0};
    validate_nodes_and_infer_types(ops);
    // Create a graph with one output (relu0) and four input (arg0)
    auto ng_function = make_shared<Function>(OutputVector{relu0}, ParameterVector{arg0});

    CNNNetwork network (ng_function);

    OpenVino().inference(net, network)

}

TENSOR(float) ReLuLayerASIC::backprob(TENSOR(float) feedback)
{
    return forward(feedback);
}
