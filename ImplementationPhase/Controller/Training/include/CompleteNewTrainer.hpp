#ifndef COMPLETE_NEW_TRAINER_H_
#define COMPLETE_NEW_TRAINER_H_

#include "NeuralNetwork.hpp"
#include "CompleteTrainer.hpp"

class CompleteNewTrainer : public CompleteNewTrainer {
    private:
        NeuralNetwork initLayersRandomly();
};
#endif
