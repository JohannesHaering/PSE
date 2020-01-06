#include "Data.hpp"
#include <list>

class ImageData : public Data {
    public:
        ImageData(std::list<int> data);
        std::list<int> getData();
};