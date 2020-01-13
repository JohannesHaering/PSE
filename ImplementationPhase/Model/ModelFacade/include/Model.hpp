#include "Result.hpp"
#include "NeuralNetworkAdapter.hpp"
#include <string>

class Model {
    public:
        static Model getInstance(); 
        void saveResult(Result result);
        NeuralNetworkAdapter  parseNeuralNetwork(std::string directory);
};