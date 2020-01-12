#ifndef MODEL_FACADE_H_
#define MODEL_FACADE_H_

#include <string>
#include <list>

class ModelFacade {
    public:
        std::list<std::string> readDirectory(std::string directory);
};
#endif