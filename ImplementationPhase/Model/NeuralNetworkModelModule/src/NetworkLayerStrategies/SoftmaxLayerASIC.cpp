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
    soft0->set_axis(1);
    // Run shape inference on the nodes
    ngraph::NodeVector ops{soft0};
    validate_nodes_and_infer_types(ops);
    // Create a graph
    auto ng_function = std::make_shared<ngraph::Function>(ngraph::OutputVector{soft0}, ngraph::ParameterVector{arg0});

    InferenceEngine::CNNNetwork network (ng_function);
    return OpenVino().inference({std::pair(net, InferenceEngine::Layout::NHWC)}, &network);
}

TENSOR(float) SoftmaxLayerASIC::backprob(TENSOR(float) feedback)
{

}
TENSOR(float) SoftmaxLayerASIC::backprob(TENSOR(float) updates, TENSOR(float) output_forward){
    auto arg0 = std::make_shared<ngraph::opset1::Parameter>(ngraph::element::f32, ngraph::Shape{output_forward.size(), output_forward[0].size(), output_forward[0][0].size(), output_forward[0][0][0].size()});
    auto arg1 = std::make_shared<ngraph::opset1::Parameter>(ngraph::element::f32, ngraph::Shape{updates.size(), updates[0].size(), updates[0][0].size(), updates[0][0][0].size()});
    auto subt0 = std::make_shared<ngraph::opset1::Subtract>(arg0,arg1);
    // Run shape inference on the nodes
    ngraph::NodeVector ops{subt0};
    validate_nodes_and_infer_types(ops);
    // Create a graph
    auto ng_function = std::make_shared<ngraph::Function>(ngraph::OutputVector{subt0}, ngraph::ParameterVector{arg0,arg1});

    InferenceEngine::CNNNetwork network (ng_function);
    return OpenVino().inference({std::pair(output_forward, InferenceEngine::Layout::NHWC), std::pair(updates,InferenceEngine::Layout::NHWC)}, &network);
}

