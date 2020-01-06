#include "../include/StringData.hpp"
#include "../include/Data.hpp"
#include <string>

using namespace std;

class StringData : public Data {
    public:
        StringData(string data) : stringData(data) {}
        string GetData(){
            return stringData;
        }

    private:
        string stringData;
};