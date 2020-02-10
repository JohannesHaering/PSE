#ifndef INPUT_IMAGE_HANDLER_TRAINER_HPP
#define INPUT_IMAGE_HANDLER_TRAINER_HPP

#include "InputImageHandler.hpp"
#include "TrainingDistributor.hpp"

class InputImageHandlerTrainer : public InputImageHandler {

    public:
        InputImageHandlerTrainer(TrainingDistributor *distributor);

    private:
        std::vector<std::string> validformatsmanual = {"jpg", "png", "*"};
        std::vector<std::string> validformatstxt = {"txt"};
        TrainingDistributor *trainingdistributor;

    protected:
        void sendDirectory(std::vector<std::string> dir) override;
        std::vector<std::string> fetchDirectory() override;
        ContentView* page;

};

#endif // INPUTIMAGEHANDLERTRAINER_HPP
