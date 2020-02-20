#include "SoftmaxLayerASIC.hpp"

#include <ngraph/opsets/opset.hpp>
#include <ngraph/opsets/opset1.hpp>

//using namespace ngraph;

SoftmaxLayerASIC::SoftmaxLayerASIC(){

}

TENSOR(float) SoftmaxLayerASIC::forward(TENSOR(float) net)
{
    auto arg0 = std::make_shared<ngraph::opset1::Parameter>(ngraph::element::f32, ngraph::Shape{net.size(), net[0].size(), net[0][0].size(), net[0][0][0].size()});
    auto soft0 = std::make_shared<ngraph::opset1::Softmax>(arg0,1);
    // Run shape inference on the nodes
    ngraph::NodeVector ops{soft0};
    validate_nodes_and_infer_types(ops);
    // Create a graph
    auto ng_function = std::make_shared<ngraph::Function>(ngraph::OutputVector{soft0}, ngraph::ParameterVector{arg0});

    InferenceEngine::CNNNetwork network (ng_function);
    return OpenVino().inference(net, &network);
}

TENSOR(float) SoftmaxLayerASIC::backprob(TENSOR(float) feedback)
{
    return forward(feedback);
}
TENSOR(float) SoftmaxLayerASIC::backprob(TENSOR(float) updates, TENSOR(float) output_forward){

}

