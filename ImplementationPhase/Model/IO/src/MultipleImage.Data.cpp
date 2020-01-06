#include "../include/Data.hpp"
#include "../include/MultipleImageData.hpp"
#include <list>

using namespace std;

class MultipleImageData : public Data {
    public:
        MultipleImageData(list<list<int>> data) : imageData(data){}
        list<list<int>> getData(){
            return imageData;
        }
    private:
        list<list<int>> imageData;
};