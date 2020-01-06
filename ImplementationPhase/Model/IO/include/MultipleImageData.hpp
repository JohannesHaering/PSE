#include "Data.hpp"
#include <list>

class MultipleImageData : public Data {
    public:
        MultipleImageData(std::list<std::list<int>> data);
        std::list<std::list<int>> getData();
};