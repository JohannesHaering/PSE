#include "DenseLayerASIC.hpp"
#include "MatrixDefine.hpp"
#include <vector>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>
#include "ngraph/opsets/opset.hpp"
#include "ngraph/opsets/opset1.hpp"

//using namespace ngraph;

DenseLayerASIC::DenseLayerASIC(){

}

TENSOR(float) DenseLayerASIC::forward(TENSOR(float) net)
  {
    auto arg0 = std::make_shared<ngraph::opset1::Parameter>(ngraph::element::f32, ngraph::Shape{net.size(), net[0].size(), net[0][0].size(), net[0][0][0].size()});
    auto arg1 = std::make_shared<ngraph::opset1::Parameter>(ngraph::element::f32, ngraph::Shape{static_cast<unsigned long>(denseLayer->getWidth()), static_cast<unsigned long>(denseLayer->getHeight()),1,1});
    std::vector<std::vector<float>> matrix2 = denseLayer->get_weights();
    TENSOR(float) matrix = {{matrix2}};
    auto dense0 = std::make_shared<ngraph::opset1::MatMul>(arg0,arg1);
    // Run shape inference on the nodes
    ngraph::NodeVector ops{dense0};
    validate_nodes_and_infer_types(ops);
    // Create a graph
    auto ng_function = std::make_shared<ngraph::Function>(ngraph::OutputVector{dense0}, ngraph::ParameterVector{arg1,arg0});

    InferenceEngine::CNNNetwork network (ng_function);
    return OpenVino().inference({std::pair(net, InferenceEngine::Layout::NHWC), std::pair(matrix,InferenceEngine::Layout::NHWC)}, &network);

}

TENSOR(float) DenseLayerASIC::backprob(TENSOR(float) feedback)
{

}
