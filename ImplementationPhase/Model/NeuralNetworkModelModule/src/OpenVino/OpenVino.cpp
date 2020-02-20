#include "OpenVino.hpp"

OpenVino::OpenVino()
{

}

TENSOR(float) OpenVino::inference(std::vector<std::pair<TENSOR(float),InferenceEngine::Layout>> net, InferenceEngine::CNNNetwork* network){

    InferenceEngine::Core ie;

    // --------------------------- 1. Configure input & output ---------------------------------------------
    // --------------------------- Prepare input blobs -----------------------------------------------------
    /** Taking information about all topology inputs **/
    InferenceEngine::InputsDataMap inputInfo(network->getInputsInfo());
    int arg_index = 0;
    for(auto & inputInfoItem : inputInfo) {
        if(arg_index > net.size()) {
            break;
        }
        /** Specifying the precision and layout of input data provided by the user.
         * This should be called before load of the network to the device **/
        inputInfoItem.second->setPrecision(InferenceEngine::Precision::FP16);
        inputInfoItem.second->setLayout(net[arg_index].second);
        arg_index++;
    }
    arg_index = 0;
    InferenceEngine::OutputsDataMap outputInfo(network->getOutputsInfo());
    if (outputInfo.size() != 1) throw std::logic_error("Sample supports topologies with 1 output only");
    // -----------------------------------------------------------------------------------------------------

    // --------------------------- 2. Loading model to the device ------------------------------------------
    InferenceEngine::ExecutableNetwork executable_network = ie.LoadNetwork(*network, "MYRIAD");
    // -----------------------------------------------------------------------------------------------------

    // --------------------------- 3. Create infer request -------------------------------------------------
    InferenceEngine::InferRequest inferRequest = executable_network.CreateInferRequest();
    // -----------------------------------------------------------------------------------------------------

    // --------------------------- 4. Prepare input --------------------------------------------------------
    for (auto & item : inputInfo) {
        if (arg_index > net.size()) {
            break;
        }
        InferenceEngine::Blob::Ptr inputBlob = inferRequest.GetBlob(item.first);
        InferenceEngine::SizeVector dims = inputBlob->getTensorDesc().getDims();
        /** Fill input tensor with input data. **/

        InferenceEngine::MemoryBlob::Ptr minput = as<InferenceEngine::MemoryBlob>(inputBlob);
        if (!minput) {
            break;
        }
        // locked memory holder should be alive all time while access to its buffer happens
        auto minputHolder = minput->wmap();

        auto data = minputHolder.as<InferenceEngine::PrecisionTrait<InferenceEngine::Precision::FP16>::value_type *>();

        TENSOR(float) arg = net[arg_index].first;
        int i = 0;
        for (int b = 0; b < dims[3]; b++) {
            for (int z = 0; z < dims[2]; z++) {
                for (int y = 0; y < dims[1]; y++) {
                    for (int x = 0; x < dims[0]; x++) {
                        data[i] = arg[b][z][y][x];
                        i++;
                    }
                }
            }
        }
        //end inputs loop
    }
    // -----------------------------------------------------------------------------------------------------

    // --------------------------- 5. Do inference ---------------------------------------------------------
    inferRequest.Infer();
    // -----------------------------------------------------------------------------------------------------

    // --------------------------- 6. Process output -------------------------------------------------------
    InferenceEngine::Blob::Ptr outputBlob = inferRequest.GetBlob(outputInfo.begin()->first);

    auto output_data = outputBlob->buffer().as<InferenceEngine::PrecisionTrait<InferenceEngine::Precision::FP32>::value_type*>();
    int i = 0;
    TENSOR(float) returnTensor;
    InferenceEngine::SizeVector outputDims = outputBlob->getTensorDesc().getDims();
    for (int b = 0; b < outputDims[3]; b++){
        for (int z = 0; z < outputDims[2]; z++){
            for (int y = 0; y < outputDims[1]; y++){
                for (int x = 0; x < outputDims[0]; x++){
                    returnTensor[b][z][y][x] = output_data[i];;
                    i++;
                }
            }
        }
    }
    return returnTensor;
    // -----------------------------------------------------------------------------------------------------
}
