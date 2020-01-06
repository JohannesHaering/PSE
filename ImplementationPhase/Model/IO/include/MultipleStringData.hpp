#include "Data.hpp"
#include <string>
#include <list>


class MultipleStringData : public Data {
    public:
        MultipleStringData(std::list<std::string> data);
        std::list<std::string> getData();
};