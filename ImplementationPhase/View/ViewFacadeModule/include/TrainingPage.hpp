#include <vector>
#include <string>

class TrainingPage {
    public:
        void newTrainingFinished(std::vector<float> pointsArrayTest, std::vector<float> pointsArrayTraining);
        float getLearningRate();
        float getPrecision();
        std::string getName();
        std::string getLearningMode();
        void startButtonEnableTraining(bool flag);
};
