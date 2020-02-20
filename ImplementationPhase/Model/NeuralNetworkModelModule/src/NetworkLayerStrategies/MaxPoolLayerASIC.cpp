#include "MaxPoolLayerASIC.hpp"

#include <ngraph/opsets/opset.hpp>
#include <ngraph/opsets/opset1.hpp>

//using namespace ngraph;

MaxPoolLayerASIC::MaxPoolLayerASIC(){

}

TENSOR(float) MaxPoolLayerASIC::forward(TENSOR(float) net)
{
    auto arg0 = std::make_shared<ngraph::opset1::Parameter>(ngraph::element::f32, ngraph::Shape{net.size(), net[0].size(), net[0][0].size(), net[0][0][0].size()});
    auto max0 = std::make_shared<ngraph::opset1::MaxPool>(arg0);
    max0->set_strides(ngraph::Strides({1,1,1}));
    max0->set_pads_begin(ngraph::Shape(0,0));
    max0->set_auto_pad(ngraph::op::PadType::VALID);
    max0->set_kernel(ngraph::Shape({3}));
    // Run shape inference on the nodes
    ngraph::NodeVector ops{max0};
    validate_nodes_and_infer_types(max0);
    // Create a graph
    auto ng_function = std::make_shared<ngraph::Function>(ngraph::OutputVector{max0}, ngraph::ParameterVector{arg0});

    InferenceEngine::CNNNetwork network (ng_function);
    return OpenVino().inference({net}, &network);
}

TENSOR(float) MaxPoolLayerASIC::backprob(TENSOR(float) feedback) {

}

