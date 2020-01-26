#ifndef NEURALNETWORK_HANDLER_H_
#define NEURALNETWORK_HANDLER_H_

#include "NeuralNetworkSetter.hpp"
#include "FileExplorerHandler.hpp"

class NeuralNetworkHandler : public FileExplorerHandler {
    public:
        NeuralNetworkHandler(Inferencer *inferencer);
        NeuralNetworkHandler();

    private:
        std::vector<std::string> validformats = {".cfg"};
        NeuralNetworkSetter *neuralnetworksetter;

    protected:
        void sendDirectory(std::vector<std::string> dir);
        std::vector<std::string> fetchDirectory();
};
#endif
