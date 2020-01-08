#ifndef IMAGE_H
#define IMAGE_H

#include <list>
#include <string>
#include <utility>

using namespace std;

class Image {
    public:
        Image(string imageId, int height, int width, int channelNumb, list<int> pixels);
        pair<int, int> getPixelPosition(float x, float y);
        string getImageId();
        int getChannelNumb();
        int getWidth();
        int getHeight();
        list<int> getPixels();
    private:
        string imageId;
        int height;
        int width;
        int channelNumb;
        list<int> pixels;
};

#endif