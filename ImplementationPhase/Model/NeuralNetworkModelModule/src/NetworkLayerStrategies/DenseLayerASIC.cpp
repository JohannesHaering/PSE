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
//    auto arg0 = std::make_shared<ngraph::opset1::Parameter>(ngraph::element::f32, ngraph::Shape{net.size(), net[0].size(), net[0][0].size(), net[0][0][0].size()});
//    // std::vector<float> slope = {0.01};
//    auto relu0 = std::make_shared<ngraph::opset1::PRelu>(arg0, 0.01);
//    auto max1 = std::make_shared<ngraph::opset1::MaxPool>();
//    // Run shape inference on the nodes
//    ngraph::NodeVector ops{relu0};
//    validate_nodes_and_infer_types(ops);
//    // Create a graph
//    auto ng_function = std::make_shared<ngraph::Function>(ngraph::OutputVector{relu0}, ngraph::ParameterVector{arg0});

//    InferenceEngine::CNNNetwork network (ng_function);

//    return OpenVino().inference(net, &network);

}

TENSOR(float) DenseLayerASIC::backprob(TENSOR(float) feedback)
{
    return forward(feedback);
}
