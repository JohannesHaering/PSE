#include "../include/Data.hpp"
#include "../include/VideoData.hpp"
#include <list>

using namespace std;

class VideoData : public Data {
    public:
        VideoData(list<int> data) : videoData(data){}
        list<int> getData(){
            return videoData;
        }
    private:
        list<int> videoData;
};