#include "../include/Data.hpp"
#include "../include/ImageData.hpp"
#include <list>

using namespace std;

class ImageData : public Data {
    public:
        ImageData(list<int> data) : imageData(data){}
        list<int> getData(){
            return imageData;
        }
    private:
        list<int> imageData;
};