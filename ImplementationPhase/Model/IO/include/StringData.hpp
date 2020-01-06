#include "Data.hpp"
#include <string>

class StringData : public Data {
    public:
        StringData(std::string data);
        std::string getData();
};