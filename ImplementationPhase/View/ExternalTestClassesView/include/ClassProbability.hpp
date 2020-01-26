#ifndef CLASS_PROBABILITY_H_
#define CLASS_PROBABILITY_H_
#include <string>

class ClassProbability{
    public:
        ClassProbability(std::string name, float probability);
        std::string getClassName();
        float getProbability();
    private:
        std::string className;
        float probability;
};
#endif
