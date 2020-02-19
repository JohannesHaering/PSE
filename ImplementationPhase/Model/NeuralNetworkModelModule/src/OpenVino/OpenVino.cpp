#include "OpenVino.hpp"

OpenVino::OpenVino()
{

}

TENSOR(float) OpenVino::inference(TENSOR(float) net, CNNNetwork* network){
    std::string pluginPath = "add here plugin path";
    InferenceEngine::PluginDispatcher dispatcher({pluginPath, ""});
    InferencePlugin plugin(dispatcher.getSuitablePlugin(TargetDevice::eMYRIAD));

    // Prepare input blobs
    auto input_info = network.getInputsInfo().begin()->second;
    auto input_name = network.getInputsInfo().begin()->first;
    input_info->setPrecision(Precision::U8);

    // Prepare output blobs
    auto output_info = network.getOutputsInfo().begin()->second;
    auto output_name = network.getOutputsInfo().begin()->first;
    output_info->setPrecision(Precision::FP32);

    // Load network to the plugin
    auto executable_network = plugin.LoadNetwork(network, {});
    auto infer_request = executable_network.CreateInferRequest();

    auto input = infer_request.GetBlob(input_name);
    auto input_data = input->buffer().as<PrecisionTrait<Precision::U8>::value_type*>();

    // Obtain input tensor
    size_t inputDims0 = input->dims()[0];
    size_t inputDims1 = input->dims()[1];
    size_t inputDims2 = input->dims()[2];
    size_t inputDims3 = input->dims()[3];
 // size_t channels_number = input->dims()[2];
 // size_t image_size = input->dims()[1] * input->dims()[0];
    int i = 0;
    for (int b = 0; b < inputDims3; b++){
        for (int z = 0; z < inputDims2; z++){
            for (int y = 0; y < inputDims1; y++){
                for (int x = 0; x < inputDims0); x++){
                                input_data[i] =	net[b][z][y][x];
                                i++;
                }
            }
        }
    }
    //  Start synchronous inference and get inference result
    infer_request.Infer();
    //  Get  Inference Result
    auto output = infer_request.GetBlob(output_name);
    auto output_data = output->buffer().as<PrecisionTrait<Precision::FP32>::value_type*>();
    i = 0;
    TENSOR(float) returnTensor;
    size_t outputDims0 = output->dims()[0];
    size_t outputDims1 = output->dims()[1];
    size_t outputDims2 = output->dims()[2];
    size_t outputDims3 = output->dims()[3];
    for (int b = 0; b < outputDims3; b++){
        for (int z = 0; z < outputDims2; z++){
            for (int y = 0; y < outputDims1; y++){
                for (int x = 0; x < outputDims0); x++){
                              returnTensor[b][z][y][x] = output_data[i];;
                                i++;
                }
            }
        }
    }
    // Do something with the results... (like print top 5
    for (size_t id = 0; id < results_to_display; ++id) {
        std::cout.precision(7);
        auto result = output_data[results[id]];
        std::cout << std::left << std::fixed << result << " label #" << results[id] << std::endl;
    }
    return returnTensor;
}
