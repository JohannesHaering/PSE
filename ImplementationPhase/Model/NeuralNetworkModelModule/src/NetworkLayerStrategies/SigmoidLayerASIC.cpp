#include "SigmoidLayerASIC.hpp"
#include "MatrixDefine.hpp"
#include <vector>
#include "ngraph/opsets/opset.hpp"
#include "ngraph/opsets/opset1.hpp"

SigmoidLayerASIC::SigmoidLayerASIC(){

}

TENSOR(float) SigmoidLayerASIC::forward(TENSOR(float) net)
{
    auto arg0 = std::make_shared<ngraph::opset1::Parameter>(ngraph::element::f32, ngraph::Shape{net.size(), net[0].size(), net[0][0].size(), net[0][0][0].size()});
    auto sigm0 = std::make_shared<ngraph::opset1::Sigmoid>(arg0);
    // Run shape inference on the nodes
    ngraph::NodeVector ops{sigm0};
    validate_nodes_and_infer_types(ops);
    //create graph
    auto ng_function = std::make_shared<ngraph::Function>(ngraph::OutputVector{sigm0}, ngraph::ParameterVector{arg0});

    InferenceEngine::CNNNetwork network (ng_function);
    return OpenVino().inference({std::pair(net, InferenceEngine::Layout::NHWC)}, &network);

}

TENSOR(float) SigmoidLayerASIC::backprob(TENSOR(float) feedback)
{

    auto arg0 = std::make_shared<ngraph::opset1::Parameter>(ngraph::element::f32, ngraph::Shape{feedback.size(), feedback[0].size(), feedback[0][0].size(), feedback[0][0][0].size()});
    auto arg1 = std::make_shared<ngraph::opset1::Parameter>(ngraph::element::f32, ngraph::Shape{1, 1, 1, 1});
    TENSOR(float) subtractMat = {{{{1}}}};
    auto sub0 = std::make_shared<ngraph::opset1::Subtract>(arg1,arg0);
    auto sigm0 = std::make_shared<ngraph::opset1::Multiply>(arg0,sub0);
    // Run shape inference on the nodes
    ngraph::NodeVector ops{sigm0};
    validate_nodes_and_infer_types(ops);
    //create graph
    auto ng_function = std::make_shared<ngraph::Function>(ngraph::OutputVector{sigm0}, ngraph::ParameterVector{arg0, arg1});

    InferenceEngine::CNNNetwork network (ng_function);

    return OpenVino().inference({std::pair(feedback, InferenceEngine::Layout::NHWC), std::pair(subtractMat,InferenceEngine::Layout::NHWC)}, &network);
}
