#include "../include/Data.hpp"
#include "../include/MultipleStringData.hpp"
#include <string>
#include <list>

using namespace std;

class MultipleStringData : public Data{
    public:
        MultipleStringData(list<string> data) : stringData(data) {}
        list<string> getData(){
            return stringData;
        }
    private:
        list<string> stringData;    
};