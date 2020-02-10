#ifndef RESULT_H_
#define RESULT_H_
#include <string>

class Result {
    public:
        Result(std::string imageID, std::string neuralNetworkID);
        std::string getImageID();
        std::string getNeuralNetworkID();

    protected:
        std::string imageID;
        std::string neuralNetworkID;
};
#endif
