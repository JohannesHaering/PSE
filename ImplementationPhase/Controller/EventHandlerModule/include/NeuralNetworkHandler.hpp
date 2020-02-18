#ifndef NEURALNETWORK_HANDLER_H_
#define NEURALNETWORK_HANDLER_H_

#include "NeuralNetworkSetter.hpp"
#include "FileExplorerHandler.hpp"

class NeuralNetworkHandler : public FileExplorerHandler {
    public:
        NeuralNetworkHandler(Inferencer *inferencer);

    protected:
        void sendDirectory(std::vector<std::string> dir);
        std::vector<std::string> fetchDirectory();

    private:
        NeuralNetworkSetter *neuralnetworksetter;
        std::vector<std::string> validformats = {"cfg", "txt"};
};
#endif
